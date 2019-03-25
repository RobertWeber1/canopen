#pragma once
#include <canopen/od/type_traits.h>
#include <canopen/od/access_type.h>
#include <canopen/od/index_type.h>


namespace canopen
{

namespace od
{


template<
	IndexType INDEX_TYPE,
	typename IndexDataType<INDEX_TYPE>::Type_t INDEX,
	class DATA_TYPE,
	AccessType ACCESS = AccessType::ReadWrite>
struct Entry
{
	using IndexType_t = typename IndexDataType<INDEX_TYPE>::Type_t;
	using DataType_t = DATA_TYPE;
	static constexpr IndexType_t index = INDEX;
	static constexpr AccessType access = ACCESS;

	static_assert(
		DataTypeValid<IndexType_t, DataType_t>::value,
		"Only basic data types allowed at sub index");
};



} //namespace od

} //namespace canopen
