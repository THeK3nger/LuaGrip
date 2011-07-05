#include "luagrip.hpp"
#include <string.h>

LuaGrip::LuaGrip() 
{
    this->m_State = luaL_newstate();
    luaL_openlibs(this->m_State);
}

LuaGrip::~LuaGrip()
{
    lua_close(this->m_State);
}

bool LuaGrip::AddFunction(const char *pFunctionName, LuaFunctionType pFunction)
{
    lua_register(this->m_State,pFunctionName,pFunction);
    return true;
}

bool LuaGrip::RunScript(const char *pFilename)
{
    if (!luaL_loadfile(this->m_State, pFilename))
    {
        if (!lua_pcall(this->m_State, 0, LUA_MULTRET, 0))
        {
            return false;
        }
    } else return false;
}

bool LuaGrip::RunString(const char *pCommand)
{
    if (luaL_loadbuffer(this->m_State, pCommand, strlen(pCommand), "line") == 0)
    {
        if (lua_pcall(this->m_State, 0, 0, 0) != 0)
        {
            return false;
        }
    } else return false;

    return true;
}

const char *LuaGrip::GetErrorString(void)
{
    return lua_tostring(this->m_State, -1);
}

const char *LuaGrip::GetStringArgument(int num, const char *pDefault)
{
	return luaL_optstring(this->m_State, num, pDefault);

}

double LuaGrip::GetNumberArgument(int num, double dDefault)
{
	return luaL_optnumber(this->m_State, num, dDefault);
}

void LuaGrip::PushString(const char *pString)
{
	lua_pushstring(this->m_State, pString);
}

void LuaGrip::PushNumber(double value)
{
	lua_pushnumber(this->m_State, value);
}

void LuaGrip::PopLast()
{
    lua_pop(this->m_State,1);
}
