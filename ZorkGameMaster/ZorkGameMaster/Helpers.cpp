#include "stdafx.h"
#include "Helpers.h"

 void Tokenize(const string& line, vector<string>& arguments)
{
	const char* str = line.c_str();// c_str lo pasa  a una forma manejable en C de C++ a C

	do
	{
		const char *begin = str;

		while (*str != ' ' && *str) //mientras no sea vacio y no sea null
			str++;

		arguments.push_back(string(begin, str));
	} while (0 != *str++);
}
