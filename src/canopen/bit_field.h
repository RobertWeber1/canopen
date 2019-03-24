#pragma once
#include <cstdint>
#include <tuple>

namespace canopen
{


template<class REP, uint8_t OFFSET, uint8_t WIDTH>
struct BaseMask
{
	static const REP value = (REP(1) << WIDTH) - 1;
};


template<class REP, uint8_t OFFSET, uint8_t WIDTH>
struct SetMask
{
	static const REP value = BaseMask<REP, OFFSET, WIDTH>::value << OFFSET;
};


template<class REP, uint8_t OFFSET, uint8_t WIDTH>
struct ClearMask
{
	static const REP value = static_cast<REP>(~(BaseMask<REP, OFFSET, WIDTH>::value << OFFSET));
};


template<class TYPE, uint8_t OFFSET, uint8_t WIDTH>
struct BitFieldEntry
{
	using Type = TYPE;
	static const uint8_t Offset = OFFSET;
	static const uint8_t Width = WIDTH;
	TYPE value;
};


template<class REP, class T, uint8_t OFFSET, uint8_t WIDTH>
REP& set(REP & result, BitFieldEntry<T, OFFSET, WIDTH> const& v)
{
	result =
		(result & ClearMask<REP, OFFSET, WIDTH>::value) |
		((v.value & BaseMask<REP, OFFSET, WIDTH>::value) << OFFSET);
	return result;
}


template<class RAW, class ENTRY>
typename ENTRY::Type get(RAW data)
{
	return
		static_cast<typename ENTRY::Type>(
			(data >> ENTRY::Offset) &
			BaseMask<RAW, ENTRY::Offset, ENTRY::Width>::value);
}


template<class REP, class ... ENTRIES>
REP squash(ENTRIES const& ... entries)
{
	REP result = 0;

	using dummy_ = int[];
	(void)dummy_{1,
		(result |=
			((static_cast<REP>(entries.value) &
				BaseMask<REP, ENTRIES::Offset, ENTRIES::Width>::value)
			  << ENTRIES::Offset))... };

	return result;
}


template<class REP, class ... ENTRIES>
std::tuple<typename ENTRIES::Type...> split(REP value)
{
	return {get<REP, ENTRIES>(value) ...};
}



template<class REP, class ... ENTRIES>
struct BitField
{
	using Data_t = std::tuple<typename ENTRIES::Type...>;

	static Data_t from_raw(REP data)
	{
		return split<REP, ENTRIES...>(data);
	}

	template<class ... TYPES>
	static REP to_raw(TYPES ... values)
	{
		return squash<REP>(ENTRIES{values} ...);
	}
};



} //namespace canopen
