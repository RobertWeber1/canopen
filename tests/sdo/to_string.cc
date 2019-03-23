#include <canopen/sdo/to_string.h>
#include "../catch.h"

TEST_CASE("abort code to string")
{
	using namespace canopen::sdo;

	REQUIRE(
		std::string(to_string(AbortCode::ToobleBitNotAlternated)) ==
		"Toggle bit not alternated.");

	REQUIRE(
		std::string(to_string(AbortCode::Timeout)) ==
		"SDO protocol timed out.");

	REQUIRE(
		std::string(to_string(AbortCode::InvalidCommand)) ==
		"Client/server command specifier not valid or unknown.");

	REQUIRE(
		std::string(to_string(AbortCode::InvalidBlockSize)) ==
		"Invalid block size (block mode only).");

	REQUIRE(
		std::string(to_string(AbortCode::InvalidSequenceNumber)) ==
		"Invalid sequence number (block mode only).");

	REQUIRE(
		std::string(to_string(AbortCode::CrcError)) ==
		"CRC error (block mode only).");

	REQUIRE(
		std::string(to_string(AbortCode::OutOfMemory)) ==
		"Out of memory.");

	REQUIRE(
		std::string(to_string(AbortCode::UnsupportedAccess)) ==
		"Unsupported access to an object.");

	REQUIRE(
		std::string(to_string(AbortCode::WriteOnlyObject)) ==
		"Attempt to read a write only object.");

	REQUIRE(
		std::string(to_string(AbortCode::ReadOnlyObject)) ==
		"Attempt to write a read only object.");

	REQUIRE(
		std::string(to_string(AbortCode::OjectDoesNotExitst)) ==
		"Object does not exist in the object dictionary.");

	REQUIRE(
		std::string(to_string(AbortCode::ObjectNotMappable)) ==
		"Object cannot be mapped to the PDO.");

	REQUIRE(
		std::string(to_string(AbortCode::ObjectTooLargeForPdoMapping)) ==
		"The number and length of the objects to be mapped would exceed PDO length.");

	REQUIRE(
		std::string(to_string(AbortCode::ParameterIncompatibel)) ==
		"General parameter incompatibility reason.");

	REQUIRE(
		std::string(to_string(AbortCode::InternalIncompatibility)) ==
		"General internal incompatibility in the device.");

	REQUIRE(
		std::string(to_string(AbortCode::HardwareError)) ==
		"Access failed due to an hardware error.");

	REQUIRE(
		std::string(to_string(AbortCode::ParameterLengthMissmatch)) ==
		"Data type does not match, length of service parameter does not match");

	REQUIRE(
		std::string(to_string(AbortCode::ParameterLengthTooHigh)) ==
		"Data type does not match, length of service parameter too high");

	REQUIRE(
		std::string(to_string(AbortCode::ParameterLengthTooLow)) ==
		"Data type does not match, length of service parameter too low");

	REQUIRE(
		std::string(to_string(AbortCode::SubindexDoesNotExist)) ==
		"Sub-index does not exist.");

	REQUIRE(
		std::string(to_string(AbortCode::InvalidParameterValue)) ==
		"Invalid value for parameter (download only).");

	REQUIRE(
		std::string(to_string(AbortCode::ParameterValueTooHigh)) ==
		"Value of parameter written too high (download only).");

	REQUIRE(
		std::string(to_string(AbortCode::ParameterValueTooLow)) ==
		"Value of parameter written too low (download only).");

	REQUIRE(
		std::string(to_string(AbortCode::MaxLessThanMin)) ==
		"Maximum value is less than minimum value.");

	REQUIRE(
		std::string(to_string(AbortCode::ResourceNotAvailable)) ==
		"Resource not available: SDO connection");

	REQUIRE(
		std::string(to_string(AbortCode::GeneralError)) ==
		"General error");

	REQUIRE(
		std::string(to_string(AbortCode::ApplicationError)) ==
		"Data cannot be transferred or stored to the application.");

	REQUIRE(
		std::string(to_string(AbortCode::ApplicationLocalControlError)) ==
		"Data cannot be transferred or stored to the application because of "
		"local control.");

	REQUIRE(
		std::string(to_string(AbortCode::ApplicationStateError)) ==
		"Data cannot be transferred or stored to the application because of "
		"the present device state.");

	REQUIRE(
		std::string(to_string(AbortCode::FailedToGenerateOd)) ==
		"Object dictionary dynamic generation fails or no object dictionary is "
		"present (e.g.object dictionary is generated from file and generation "
		"fails because of an file error).");

	REQUIRE(
		std::string(to_string(AbortCode::NoDataAvailable)) ==
		"No data available");
}
