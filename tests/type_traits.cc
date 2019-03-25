#include <canopen/type_traits.h>
#include "catch.h"
#include <type_traits>

using namespace canopen;

TEST_CASE("convert index enum type to data type")
{
	REQUIRE((std::is_same<uint16_t, IndexDataType<od::IndexType::Main>::type>::value));
	REQUIRE((std::is_same<uint8_t, IndexDataType<od::IndexType::Sub>::type>::value));
}

TEST_CASE("is base data type")
{
	REQUIRE(IsBasicDatatype<bool>::value);
	REQUIRE(IsBasicDatatype<uint8_t>::value);
	REQUIRE(IsBasicDatatype<int8_t>::value);
	REQUIRE(IsBasicDatatype<uint16_t>::value);
	REQUIRE(IsBasicDatatype<int16_t>::value);
	REQUIRE(IsBasicDatatype<uint32_t>::value);
	REQUIRE(IsBasicDatatype<int32_t>::value);
	REQUIRE(IsBasicDatatype<uint64_t>::value);
	REQUIRE(IsBasicDatatype<int64_t>::value);
	REQUIRE(IsBasicDatatype<float>::value);
	REQUIRE(IsBasicDatatype<double>::value);

	REQUIRE_FALSE(IsBasicDatatype<std::string>::value);
	REQUIRE_FALSE(IsBasicDatatype<struct SomeType>::value);
}