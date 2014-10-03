#LuaBridgeCpp

##About
A C++ wrapper for using Lua.

##Features
+ Call C++ functions inside Lua.
+ Call Lua functions inside C++.
+ Get variables from one language to another.
+ OOP Design.

##How to

In C++ use it like this:

	// Create a Lua Instance with libraries loaded
	LuaBridge* b = new LuaBridge(true);
	
	// Parse a lua file
	b->parseFile("test.lua");
	
	// Get variables from the lua file by name
	const char* aStringFromLua   = b->getString("variable1");
	int aNumberFromLua 			 = b->getInt("variable2");

