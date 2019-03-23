#pragma once
#include <cstdint>

namespace canopen
{

namespace sdo
{


enum class AbortCode : uint32_t
{
	ToobleBitNotAlternated       = 0x05030000, // Toggle bit not alternated.
	Timeout                      = 0x05040000, // SDO protocol timed out.
	InvalidCommand               = 0x05040001, // Client/server command specifier not valid or unknown.
	InvalidBlockSize             = 0x05040002, // Invalid block size (block mode only).
	InvalidSequenceNumber        = 0x05040003, // Invalid sequence number (block mode only).
	CrcError                     = 0x05040004, // CRC error (block mode only).
	OutOfMemory                  = 0x05040005, // Out of memory.
	UnsupportedAccess            = 0x06010000, // Unsupported access to an object.
	WriteOnlyObject              = 0x06010001, // Attempt to read a write only object.
	ReadOnlyObject               = 0x06010002, // Attempt to write a read only object.
	OjectDoesNotExitst           = 0x06020000, // Object does not exist in the object dictionary.
	ObjectNotMappable            = 0x06040041, // Object cannot be mapped to the PDO.
	ObjectTooLargeForPdoMapping  = 0x06040042, // The number and length of the objects to be mapped would exceed PDO length.
	ParameterIncompatibel        = 0x06040043, // General parameter incompatibility reason.
	InternalIncompatibility      = 0x06040047, // General internal incompatibility in the device.
	HardwareError                = 0x06060000, // Access failed due to an hardware error.
	ParameterLengthMissmatch     = 0x06070010, // Data type does not match, length of service parameter does not match
	ParameterLengthTooHigh       = 0x06070012, // Data type does not match, length of service parameter too high
	ParameterLengthTooLow        = 0x06070013, // Data type does not match, length of service parameter too low
	SubindexDoesNotExist         = 0x06090011, // Sub-index does not exist.
	InvalidParameterValue        = 0x06090030, // Invalid value for parameter (download only).
	ParameterValueTooHigh        = 0x06090031, // Value of parameter written too high (download only).
	ParameterValueTooLow         = 0x06090032, // Value of parameter written too low (download only).
	MaxLessThanMin               = 0x06090036, // Maximum value is less than minimum value.
	ResourceNotAvailable         = 0x060A0023, // Resource not available: SDO connection
	GeneralError                 = 0x08000000, // General error
	ApplicationError             = 0x08000020, // Data cannot be transferred or stored to the application.
	ApplicationLocalControlError = 0x08000021, // Data cannot be transferred or stored to the application because of local control.
	ApplicationStateError        = 0x08000022, // Data cannot be transferred or stored to the application because of the present device state.
	FailedToGenerateOd           = 0x08000023, // Object dictionary dynamic generation fails or no object dictionary is present (e.g.object dictionary is generated from file and generation fails because of an file error).
	NoDataAvailable              = 0x08000024  // No data available
};


} //namespace sdo

} //namespace canopen