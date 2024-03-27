#include <iostream>
#include <lua.hpp>
#include "calc.h"

using namespace std;

void func(){
    // Calling a Lua script
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    luaL_dofile(L, "script.lua");
    cout << "End of function" <<endl;
    cout << " " <<endl;
}

int main (){

    func();
    cout << "After the func call" <<endl;
    // Creating the Lua State
    lua_State* L = luaL_newstate();

    luaL_openlibs(L); // load the lua standard libraries
    luaL_dofile(L, "print.lua"); // Running the Lua script
    // Running the lua code 
    const char* lua_code = "print('Hello Lua') print('Lua Again')";

    if (luaL_dostring(L, lua_code) != LUA_OK){
        cerr << "Error Executing Lua" << endl;
        lua_close(L);
        return 1;
    }
    cout << "Lua run successfully" <<endl;
    
    // Calling the maths functions
    int result_add = add(34, 567);
    int result_minus = minus_calc(345, 89);
    int result_mulitply = multiply(302, 45);
    int result_divide = divide(60, 15);

    cout << "Add: " + to_string(result_add) <<endl;
    cout << "Minus: " + to_string(result_minus) << endl;
    cout << "Multiply: " + to_string(result_mulitply) <<endl;
    cout << "Divide: " + to_string(result_divide) << endl;

    lua_close(L);

    cout << "C++" <<endl;
    return 0;
}
