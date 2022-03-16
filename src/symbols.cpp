#include "../headers/symbols.hpp"
#include "../headers/utils.hpp"
#include <vector>
#include <unordered_map>

using namespace std;

extern unordered_map<string, string> temporaries;
vector<Symbol> symbolTable;


Attribute createActualAttribute(string type)
{
	Attribute actual;
	actual.label = createTempCode();
	actual.type = type;
	addTemporary(actual.label, actual.type);

	return actual;
}

void addSymbolInTable(string label, string type, Attribute actual)
{
  string variableName = createVariable();
	Symbol symbol;
	
  symbol.label = label;
	symbol.name = variableName;
	symbol.type = type;
	symbol.initialized = true;

	symbolTable.push_back(symbol);

	actual.translation = "";
	actual.label = "";
}

int findSymbol(string label)
{
	for (int i = 0; i < symbolTable.size(); i++)
	{
		if (symbolTable[i].label == label)
		{
			return i;
		}
	}
	return -1;
}

Symbol getSymbol(string label)
{
	int position = findSymbol(label);
	return symbolTable[position];
}

string declareVariables()
{
  string result = "";
  for (auto &x: temporaries)
  {
    result = result + x.second + " " +x.first + ";\n";
  }
  for (int i = 0; i < symbolTable.size(); i++)
  {
    result = result + symbolTable[i].type + " " +symbolTable[i].name + ";\n";
  }
  return result;
}

string declareDefines()
{
  string result = "";

  result += "#define bool int\n";
  result += "#define true 1\n";
  result += "#define false 0\n";
  return result;
}