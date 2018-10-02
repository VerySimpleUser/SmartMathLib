#include "stdafx.h"
#include "SMException.h"

using namespace SM;
using namespace SME;

list<SMExceptionMessage> SMException::_list_error_message{};

SMException::SMException(string & error_massage, string & class_initiator)
{
	SMException::_list_error_message.push_front(SMExceptionMessage{ error_massage, class_initiator });
};

SM::SME::SMException::SMException(const char * error_massage, const char * class_initiator)
{
	SMException::_list_error_message.push_front(SMExceptionMessage{ error_massage, class_initiator });
};

SMException::~SMException()
{
	return;
};

SMExceptionMessage SMException::GetLastErrorMessage()
{
	return *SMException::_list_error_message.end();
};

int SM::SME::SMException::GetErrorCount()
{
	return SMException::_list_error_message.size();
};