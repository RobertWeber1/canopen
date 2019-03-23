#include <tuple>
#include <algorithm>
#include <stdint.h>
#include <type_traits>

namespace canopen
{


template<uint16_t INDEX, class TYPE>
struct Entry
{
	using base_type = TYPE;
	static constexpr uint16_t index = INDEX;
};



template<class LAST = void>
constexpr size_t max_buffer_size()
{
    return sizeof(LAST::base_type);
}

template<class FIRST, class... REST>
constexpr size_t max_buffer_size()
{
    return std::max(sizeof(FIRST::base_type), max_buffer_size<REST...>());
}



template<class ... ENTRIES>
struct ObjectDictionay : ENTRIES ...
{
	static size_t required_buffer_size()
	{
		return max_buffer_size<ENTRIES...>();
	}
};


} //namespace canopen
