#pragma once
#include <canopen/sdo/abort_code.h>


namespace canopen
{

namespace sdo
{

inline
char const* to_string(AbortCode abort_code)
{
	switch(abort_code)
	{
		case AbortCode::ToobleBitNotAlternated:
			return "Toggle bit not alternated.";
		case AbortCode::Timeout:
			return "SDO protocol timed out.";
		case AbortCode::InvalidCommand:
			return "Client/server command specifier not valid or unknown.";
		case AbortCode::InvalidBlockSize:
			return "Invalid block size (block mode only).";
		case AbortCode::InvalidSequenceNumber:
			return "Invalid sequence number (block mode only).";
		case AbortCode::CrcError:
			return "CRC error (block mode only).";
		case AbortCode::OutOfMemory:
			return "Out of memory.";
		case AbortCode::UnsupportedAccess:
			return "Unsupported access to an object.";
		case AbortCode::WriteOnlyObject:
			return "Attempt to read a write only object.";
		case AbortCode::ReadOnlyObject:
			return "Attempt to write a read only object.";
		case AbortCode::OjectDoesNotExitst:
			return "Object does not exist in the object dictionary.";
		case AbortCode::ObjectNotMappable:
			return "Object cannot be mapped to the PDO.";
		case AbortCode::ObjectTooLargeForPdoMapping:
			return
				"The number and length of the objects to be mapped would exceed "
				"PDO length.";
		case AbortCode::ParameterIncompatibel:
			return "General parameter incompatibility reason.";
		case AbortCode::InternalIncompatibility:
			return "General internal incompatibility in the device.";
		case AbortCode::HardwareError:
			return "Access failed due to an hardware error.";
		case AbortCode::ParameterLengthMissmatch:
			return
				"Data type does not match, length of service parameter does "
				"not match";
		case AbortCode::ParameterLengthTooHigh:
			return
				"Data type does not match, length of service parameter too high";
		case AbortCode::ParameterLengthTooLow:
			return
				"Data type does not match, length of service parameter too low";
		case AbortCode::SubindexDoesNotExist:
			return "Sub-index does not exist.";
		case AbortCode::InvalidParameterValue:
			return "Invalid value for parameter (download only).";
		case AbortCode::ParameterValueTooHigh:
			return "Value of parameter written too high (download only).";
		case AbortCode::ParameterValueTooLow:
			return "Value of parameter written too low (download only).";
		case AbortCode::MaxLessThanMin:
			return "Maximum value is less than minimum value.";
		case AbortCode::ResourceNotAvailable:
			return "Resource not available: SDO connection";
		case AbortCode::GeneralError:
			return "General error";
		case AbortCode::ApplicationError:
			return "Data cannot be transferred or stored to the application.";
		case AbortCode::ApplicationLocalControlError:
			return
				"Data cannot be transferred or stored to the application "
				"because of local control.";
		case AbortCode::ApplicationStateError:
			return
				"Data cannot be transferred or stored to the application "
				"because of the present device state.";
		case AbortCode::FailedToGenerateOd:
			return
				"Object dictionary dynamic generation fails or no object "
				"dictionary is present (e.g.object dictionary is generated "
				"from file and generation fails because of an file error).";
		case AbortCode::NoDataAvailable:
			return "No data available";
	}
}


}

} //namespace canopen
