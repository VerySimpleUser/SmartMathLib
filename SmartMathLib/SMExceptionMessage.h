#pragma once

using namespace std;

//base namespace of SmarthMathLib.dll
namespace SM
{
	//base namespace of exception classes in SmarthMathLib.dll
	namespace SME
	{
		//class of presents a sole error message
		class SMExceptionMessage
		{
		public:

			SMExceptionMessage(string & error_message, string & class_initiator);

			SMExceptionMessage(const char * error_message, const char * class_initiator);

			SMExceptionMessage(const SMExceptionMessage &sm_exception_message);

			string GetFullErrorDescription(bool is_time_give = true, bool _is_class_initiator_give = true);

			~SMExceptionMessage();

		private:

			char* SetCurrentSystemTime();

			string _time_error;

			string _error_message;

			string _class_initiator;

		};//SMExceptionMessage

	};//SME

};//SM

