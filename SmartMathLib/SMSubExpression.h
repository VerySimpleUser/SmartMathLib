#pragma once

#include "stdafx.h"
#include "SMExceptionSubExpression.h"

using namespace std;

//base namespace of SmarthMathLib.dll
namespace SM
{
	//templated class for calculation a simple binary math expressions as addition, subtraction, multiplication and division.
	template <typename ValueType = double>
	class SMSubExpression
	{
	public:

		SMSubExpression(string math_expression);

		~SMSubExpression();

		//function of initialize current math expression computing.
		ValueType ComputMathExpression(bool is_parallel_computing = false, ValueType *ansver_variable = nullptr);

	private:

		//function of computation the math expression in nonparallel mode.
		ValueType ComputMathExpressionInNonparallelMode();

		//function of computation the math expression in parallel mode.
		static void ComputMathExpressionInParallelMode(void *);

		//math expression which mast be computed.
		string _math_expression;

	};//SMSubExpression

};//SM