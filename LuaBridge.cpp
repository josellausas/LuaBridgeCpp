/*
	LuaBridge.cpp by Jose@zunware.com
	Oct 2, 2014

	Description: Wrapper class for using Lua with C++
*/

#include "LuaBridge.h"

LuaBridge::LuaBridge()
{
	this->mLuaState = NULL;
	this->mLuaState = luaL_newstate();
}

LuaBridge::LuaBridge(bool loadWithLibs)
{
	this->mLuaState = NULL;
	this->mLuaState = luaL_newstate();
	
	if(loadWithLibs)
	{
		luaL_openlibs(this->mLuaState);
	}
}

// Copy Constructor
LuaBridge::LuaBridge( const LuaBridge& other )
{
	this->mLuaState = other.mLuaState;
}

// Destructor
LuaBridge::~LuaBridge()
{
	// Dispose of Lua
	if(this->mLuaState)
	{
		lua_close(this->mLuaState);	
		this->mLuaState = NULL;
	}
}

// Assigment Operator Overload
LuaBridge& LuaBridge::operator=( const LuaBridge& rhs )
{
	this->mLuaState = rhs.mLuaState;

	return *this;
}

bool LuaBridge::parseFile(const char* filename)
{
	// do file
	luaL_dofile(this->mLuaState, filename);

	return true;
	
}

const char* LuaBridge::getString(const char* name)
{
	// Acces variables from file (lua_State*, [nombre de variable]). 
	lua_getglobal(this->mLuaState, name); // PUSH01
	
	// Check if it exists
	if(lua_isnil(this->mLuaState, -1))
	{
		printf("The Lua variable: - %s - is nil!", name);	
		return NULL;	
	}
	else
	{
		return lua_tostring(this->mLuaState, -1); // POP01
	}
}

int LuaBridge::getInt(const char* name)
{
	lua_getglobal(this->mLuaState, name); // PUSH01

	// Check if it exists
	if(lua_isnil(this->mLuaState, -1))
	{
		printf("The Lua variable: - %s - is nil!", name);	
		return 0;	
	}
	else
	{
		return lua_tonumber(this->mLuaState, -1); // POP01
	}
}

