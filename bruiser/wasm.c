
/***************************************************Project Mutator****************************************************/
/*first line intentionally left blank.*/
/*bruiser's wasm interface implementation*/
/*Copyright (C) 2018 Farzad Sadeghi

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 3
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.*/
/**********************************************************************************************************************/
#include "./lua-5.3.4/src/lua.h"
#include "./lua-5.3.4/src/lauxlib.h"
#include "./lua-5.3.4/src/lualib.h"
#include "./wasm.h"
/**********************************************************************************************************************/
static Wasm_Module* convert_wasm_module(lua_State* ls, int index) {
  Wasm_Module* dummy = lua_touserdata(ls, index);
  if (dummy == NULL) {printf("convert_wasm_module: bad userdata.\n");}
  return dummy;
}

static Wasm_Module* check_wasm_module(lua_State* ls, int index) {
  Wasm_Module* dummy;
  luaL_checktype(ls, index, LUA_TUSERDATA);
  dummy = (Wasm_Module*)luaL_checkudata(ls, index, "wasm_module");
  if (dummy == NULL) {printf("check_wasm_module: bad userdata.\n");}
  return dummy;
}

#pragma weak main
int main(int argc, char** argv) {
}
/**********************************************************************************************************************/
/*last line intentionally left blank.*/

