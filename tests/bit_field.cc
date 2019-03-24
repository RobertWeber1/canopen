#include <canopen/bit_field.h>
#include "catch.h"

using namespace canopen;

enum class ValueA
{
	Foo = 1
};

enum class ValueB
{
	Bar = 5
};


using FieldA = BitFieldEntry<ValueA, 0, 4>;
using FieldB = BitFieldEntry<ValueB, 4, 4>;

TEST_CASE("BitFieldEntry")
{
	REQUIRE(squash<uint8_t>(FieldA{ValueA::Foo}, FieldB{ValueB::Bar}) == 0x51);

	REQUIRE(
		(split<uint8_t, FieldA, FieldB>(0x51)) ==
		std::make_tuple(ValueA::Foo, ValueB::Bar));
}


using TestBitField = BitField<uint8_t, FieldA, FieldB>;

TEST_CASE("BitField")
{
	REQUIRE(TestBitField::to_raw(ValueA::Foo, ValueB::Bar) == 0x51);

	REQUIRE(
		TestBitField::from_raw(0x51) ==
		std::make_tuple(ValueA::Foo, ValueB::Bar));
}
