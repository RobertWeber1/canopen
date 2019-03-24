#pragma once
#include <cstdint>

namespace canopen
{

namespace sdo
{


enum class AbortCode : uint32_t
{
	ToobleBitNotAlternated       = 0x05030000,
	Timeout                      = 0x05040000,
	InvalidCommand               = 0x05040001,
	InvalidBlockSize             = 0x05040002,
	InvalidSequenceNumber        = 0x05040003,
	CrcError                     = 0x05040004,
	OutOfMemory                  = 0x05040005,
	UnsupportedAccess            = 0x06010000,
	WriteOnlyObject              = 0x06010001,
	ReadOnlyObject               = 0x06010002,
	OjectDoesNotExitst           = 0x06020000,
	ObjectNotMappable            = 0x06040041,
	ObjectTooLargeForPdoMapping  = 0x06040042,
	ParameterIncompatibel        = 0x06040043,
	InternalIncompatibility      = 0x06040047,
	HardwareError                = 0x06060000,
	ParameterLengthMissmatch     = 0x06070010,
	ParameterLengthTooHigh       = 0x06070012,
	ParameterLengthTooLow        = 0x06070013,
	SubindexDoesNotExist         = 0x06090011,
	InvalidParameterValue        = 0x06090030,
	ParameterValueTooHigh        = 0x06090031,
	ParameterValueTooLow         = 0x06090032,
	MaxLessThanMin               = 0x06090036,
	ResourceNotAvailable         = 0x060A0023,
	GeneralError                 = 0x08000000,
	ApplicationError             = 0x08000020,
	ApplicationLocalControlError = 0x08000021,
	ApplicationStateError        = 0x08000022,
	FailedToGenerateOd           = 0x08000023,
	NoDataAvailable              = 0x08000024
};


} //namespace sdo

} //namespace canopen