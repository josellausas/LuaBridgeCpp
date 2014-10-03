/*
	LuaBridge.cpp by Jose@zunware.com
	Oct 2, 2014

	Description: Wrapper class for using Lua with C++
*/

// Since Lua is written in pure C, import them like this:


#include <iostream>
#include <string>

extern "C" {
	#include "lua-5.2.3/src/lua.h"
	#include "lua-5.2.3/src/lualib.h"
	#include "lua-5.2.3/src/lauxlib.h"	
}


using namespace std;

int main(int argc, char** argv)
{
	lua_State *L = luaL_newstate();
	
	// Load the libds
	luaL_openlibs(L);

	// do file
	luaL_dofile(L, "test.lua");

	// Acces variables from file (lua_State*, [nombre de variable]). 
	// Puts it in the stack
	lua_getglobal(L, "variable1");
	string* variable1 = 0; 

	// Check if it exists
	if(lua_isnil(L, -1))
	{
		printf("The Lua variable is nil!");		
	}
	else
	{
		variable1 = new string(lua_tostring(L, -1)); // pop the last variable as a string	
	}


	// Test variable 1
	cout << "Hola " <<  variable1->c_str() << " desde C++" << endl;


	lua_close(L);

	// cleanup the memory
	if(variable1)
	{
		delete variable1;
	}

	return 0;
}