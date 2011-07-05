#ifndef H_LUAGRIP
#define H_LUAGRIP

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

struct lua_State;

#define LuaGlue extern "C" int

extern "C" {
    typedef int (*LuaFunctionType)(struct lua_State *pLuaState);
};

class LuaGrip
{
    public:
        /**
         * Constructor.
         */
        LuaGrip();
        virtual ~LuaGrip();
        
        /**
         * Execute Lua script indicated by pFilename.
         * 
         * @param pFilename [in] Script's path.
         * @return false on error. true otherwise.
         */
        bool RunScript(const char *pFilename);
        
        /**
         * Execute one string.
         * 
         * @param pCommand [in] String representing a Lua command.
         * @return false on error. true otherwise.
         */ 
        bool RunString(const char *pCommand);
        
        /**
         * Get a string representing the last occurred error.
         * 
         * @return ...
         */
        const char *GetErrorString();
        
        /**
         * Link a C/C++ function to Lua interpeter.
         * 
         * @param pFunctionName [in] String of function name.
         * @param pfunction [in] Pointer to a function you are going to link.
         * @return  false on error. true otherwise.
         */
        bool AddFunction(const char *pFunctionName, LuaFunctionType pFunction);
        
        /**
         * 
         */
        const char *GetStringArgument(int num, const char *pDefault=NULL);
        
        /**
         * 
         */
        double GetNumberArgument(int num, double dDefault=0.0);
        
        void PopLast();
        
        void PushString(const char *pString);
        void PushNumber(double value);
    
    private:
        lua_State *m_State;
};

#endif /* H_LUAGRIP */
