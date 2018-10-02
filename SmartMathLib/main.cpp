#include "stdafx.h"

using namespace std;
//using namespace std::tr1;

int main()
{
	string expression = "((2 + 2) * 2) / 10";

	regex rx(" ");

	expression = regex_replace(expression, regex(" "), "");

	expression = regex_replace(expression, regex("/d"), "NON");

	cout << expression;

	return 0;
};