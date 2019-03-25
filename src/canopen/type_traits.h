#pragma once
#include <canopen/od/index_type.h>
#include <canopen/od/access_type.h>
#include <cstdint>


namespace canopen
{


template<od::IndexType>
struct IndexDataType;


template<>
struct IndexDataType<od::IndexType::Main>
{
	using type = uint16_t;
};


template<>
struct IndexDataType<od::IndexType::Sub>
{
	using type = uint8_t;
};

//----------------------------------------------------------------------------//

template<class T>
struct IsBasicDatatype
{
	enum{ value = false };
};

template<>
struct IsBasicDatatype<bool>
{
	enum{ value = true };
};

template<>
struct IsBasicDatatype<int8_t>
{
	enum{ value = true };
};

template<>
struct IsBasicDatatype<uint8_t>
{
	enum{ value = true };
};

template<>
struct IsBasicDatatype<int16_t>
{
	enum{ value = true };
};

template<>
struct IsBasicDatatype<uint16_t>
{
	enum{ value = true };
};

template<>
struct IsBasicDatatype<int32_t>
{
	enum{ value = true };
};

template<>
struct IsBasicDatatype<uint32_t>
{
	enum{ value = true };
};

template<>
struct IsBasicDatatype<int64_t>
{
	enum{ value = true };
};

template<>
struct IsBasicDatatype<uint64_t>
{
	enum{ value = true };
};

template<>
struct IsBasicDatatype<float>
{
	enum{ value = true };
};

template<>
struct IsBasicDatatype<double>
{
	enum{ value = true };
};

//----------------------------------------------------------------------------//

// template<od::IndexType, class TYPE>
// struct DataTypeValid

} //namespace canopen

