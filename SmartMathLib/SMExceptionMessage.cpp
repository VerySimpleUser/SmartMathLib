#include "stdafx.h"
#include "SMExceptionMessage.h"

using namespace SM;
using namespace SME;

SMExceptionMessage::SMExceptionMessage(string & error_message, string & class_initiator)
{
	this->_time_error = this->SetCurrentSystemTime();
	this->_error_message = error_message;
	this->_class_initiator = class_initiator;
};

SM::SME::SMExceptionMessage::SMExceptionMessage(const char * error_message, const char * class_initiator)
{
	this->_time_error = this->SetCurrentSystemTime();
	this->_error_message = error_message;
	this->_class_initiator = class_initiator;
};

SMExceptionMessage::SMExceptionMessage(const SMExceptionMessage &sm_exception_message)
{
	this->_time_error = sm_exception_message._time_error;
	this->_error_message = sm_exception_message._error_message;
	this->_class_initiator = sm_exception_message._class_initiator;
};

string SMExceptionMessage::GetFullErrorDescription(bool is_time_give, bool is_initial_class_give)
{
	string full_error_description = this->_error_message;

	if (is_initial_class_give)
		full_error_description.insert(0, "[Initial class = " + this->_class_initiator + "]");

	if (is_time_give)
		full_error_description.insert(0, "[Time = " + this->_time_error + "]");

	return full_error_description;
};

SMExceptionMessage::~SMExceptionMessage()
{
	return;
};

char* SMExceptionMessage::SetCurrentSystemTime()
{
	char time[32];

	__time32_t aclock;						//number for keep cont seconds since 1940 year.
	_time32(&aclock);						//function for get count seconds since 1940 year.

	tm newtime;								//struct for time representation by differently.
	_localtime32_s(&newtime, &aclock);		//function of convert time-seconds in time-date.

	asctime_s(time, size(time), &newtime);	//function of convert a time-data struct in time-strok.

	return time;
};
