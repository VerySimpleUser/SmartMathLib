#pragma once
#include "stdafx.h"
#include "SMExceptionMessage.h"

using namespace std;

//base namespace of SmarthMathLib.dll
namespace SM
{
	//base namespace of exception classes in SmarthMathLib.dll
	namespace SME
	{
		//class of presents every error messages which relate on SmarthMathLib.dll
		class SMException
		{
		public:

			SMException(string & error_massage, string & class_initiator);

			SMException(const char * error_massage, const char * class_initiator);

			virtual ~SMException();

			virtual SMExceptionMessage GetLastErrorMessage();

			virtual int GetErrorCount();

		private:

			static list<SMExceptionMessage> _list_error_message;

		};//SMException

	};//SME

};//SM