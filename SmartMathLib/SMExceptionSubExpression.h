#pragma once

#include "SMException.h"

using namespace std;

//base namespace of SmarthMathLib.dll
namespace SM
{
	//base namespace of exception classes in SmarthMathLib.dll
	namespace SME
	{
		//class of presents every error messages which relate on ubExpression class.
		class SMExceptionSubExpression : public SMException
		{
		public:

			SMExceptionSubExpression(string & error_message);

			SMExceptionSubExpression(const char * error_message);

			~SMExceptionSubExpression();

			SMExceptionMessage GetLastErrorMessage() override;

			int GetErrorCount() override;

		private:

			static string _initial_class_type;

			static list<SMExceptionMessage> _list_error_message;

		};//SMExceptionSubExpression

	};//SME

};//SM
