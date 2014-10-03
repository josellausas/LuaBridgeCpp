#include <iostream>

#include "LuaBridge.h"

class LuaBridge;

using namespace std;

// Tests getting a string variable from Lua
const char* test01(LuaBridge* b)
{
	const char* aStringFromLua = b->getString("variable1");

	if(strcmp(aStringFromLua, "Lua") == 0)
	{
		return "Success";
	}
	else
	{
		return "Failure";
	}

}

// Tests getting a number variable from Lua
const char* test02(LuaBridge* b)
{
	int aNumberFromLua = b->getInt("variable2");

	if(aNumberFromLua == 1337)
	{
		return "Success";
	}
	else
	{
		return "Failure";
	}

}

int main(int argc, char** argv)
{

	// Create a Lua Instance with libraries loaded
	LuaBridge* b = new LuaBridge(true);

	// Parse a lua file
	b->parseFile("test.lua");
	
	// Runs a series of tests
	cout << "Test01: " << test01(b) << endl;
	cout << "Test02: " << test02(b) << endl;

	return 0;
}