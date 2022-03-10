#include "../headers/utils.hpp"
#include <unordered_map>
#include <iostream>

using namespace std;


int count_var = 0;
unordered_map<string, string> temporaries;



void yyerror(string MSG)
{
	cout << MSG << endl;
	exit (0);
}

string createTempCode()
{
	count_var++;
	return "t" + intToString(count_var);
}

string intToString(int value)
{
	return to_string(value);
}

void addTemporary(string label, string type)
{
  temporaries[label] = type;
}