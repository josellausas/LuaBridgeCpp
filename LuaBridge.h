#ifndef _ZUNWARE_LUA_BRIDGE_
#define _ZUNWARE_LUA_BRIDGE_

/*

	LuaBridge.h

	Oct 3, 2014 by jose@zunware.com

*/

// Since Lua is written in purex C, import them like this:
extern "C" {
	#include "lua-5.2.3/src/lua.h"
	#include "lua-5.2.3/src/lualib.h"
	#include "lua-5.2.3/src/lauxlib.h"	
}

#include <string>

class LuaBridge
{
private:
	lua_State* mLuaState;

public:
	// Constructor
	LuaBridge();
	// Custom Constructor
	LuaBridge(bool loadWithLibs);
	// Copy Constructor
	LuaBridge( const LuaBridge& other );
	// Destructor
	~LuaBridge();
	// Assigment Operator Overload
	LuaBridge& operator=( const LuaBridge& rhs );

	bool parseFile(const char* filename); // Parses a file and returns true if success

	const char* getString(const char* name);
	int getInt(const char* name);

};

#endif