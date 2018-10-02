#include "stdafx.h"
#include "SMExceptionSubExpression.h"

using namespace SM;
using namespace SME;

string SMExceptionSubExpression::_initial_class_type = "SubExpression<ValueType>";

list<SMExceptionMessage> SMExceptionSubExpression::_list_error_message{};

SMExceptionSubExpression::SMExceptionSubExpression(string & error_message)
	: SMException(error_message, this->_initial_class_type)
{
	SMExceptionSubExpression::_list_error_message.push_front(SMExceptionMessage{ error_message, this->_initial_class_type });
};

SMExceptionSubExpression::SMExceptionSubExpression(const char * error_message)
	: SMException(error_message, this->_initial_class_type.c_str())
{
	SMExceptionSubExpression::_list_error_message.push_front(SMExceptionMessage{ error_message, this->_initial_class_type.c_str() });
};

SMExceptionSubExpression::~SMExceptionSubExpression()
{
	return;
};

SMExceptionMessage SMExceptionSubExpression::GetLastErrorMessage()
{
	return *SMExceptionSubExpression::_list_error_message.end();
};

int SMExceptionSubExpression::GetErrorCount()
{
	return SMExceptionSubExpression::_list_error_message.size();
};
