
// automatically generated by luatablegen
#include "../lua-5.3.4/src/lua.h"
#include "../lua-5.3.4/src/lauxlib.h"
#include "../lua-5.3.4/src/lualib.h"
#include <inttypes.h>
#include <stdbool.h>
#include "./Wasm_Module_tablegen.h"

#include "../wasm.h"

static Wasm_Module* convert_Wasm_Module (lua_State* __ls, int index) {
	Wasm_Module* dummy = (Wasm_Module*)lua_touserdata(__ls, index);
	if (dummy == NULL) printf("Wasm_Module:bad user data type.\n");
	return dummy;
}

static Wasm_Module* check_Wasm_Module(lua_State* __ls, int index) {
	Wasm_Module* dummy;
	luaL_checktype(__ls, index, LUA_TUSERDATA);
	dummy = (Wasm_Module*)luaL_checkudata(__ls, index, "Wasm_Module");
	if (dummy == NULL) printf("Wasm_Module:bad user data type.\n");
	return dummy;
}

Wasm_Module* push_Wasm_Module(lua_State* __ls) {
	lua_checkstack(__ls, 1);
	Wasm_Module* dummy = lua_newuserdata(__ls, sizeof(Wasm_Module));
	luaL_getmetatable(__ls, "Wasm_Module");
	lua_setmetatable(__ls, -2);
	return dummy;
}

int Wasm_Module_push_args(lua_State* __ls, Wasm_Module* _st) {
	lua_checkstack(__ls, 13);
	lua_pushlightuserdata(__ls, _st->type_section);
	lua_pushlightuserdata(__ls, _st->import_section);
	lua_pushlightuserdata(__ls, _st->function_section);
	lua_pushlightuserdata(__ls, _st->table_section);
	lua_pushlightuserdata(__ls, _st->memory_section);
	lua_pushlightuserdata(__ls, _st->global_section);
	lua_pushlightuserdata(__ls, _st->export_section);
	lua_pushlightuserdata(__ls, _st->start_section);
	lua_pushlightuserdata(__ls, _st->element_section);
	lua_pushlightuserdata(__ls, _st->code_section);
	lua_pushlightuserdata(__ls, _st->data_section);
	lua_pushlightuserdata(__ls, _st->W_Custom_Sections);
	lua_pushstring(__ls, _st->name);
	return 0;
}

int new_Wasm_Module(lua_State* __ls) {
	lua_checkstack(__ls, 13);
	W_Type_Section* type_section = lua_touserdata(__ls,-13);
	W_Import_Section* import_section = lua_touserdata(__ls,-12);
	W_Function_Section* function_section = lua_touserdata(__ls,-11);
	W_Table_Section* table_section = lua_touserdata(__ls,-10);
	W_Memory_Section* memory_section = lua_touserdata(__ls,-9);
	W_Global_Section* global_section = lua_touserdata(__ls,-8);
	W_Export_Section* export_section = lua_touserdata(__ls,-7);
	W_Start_Section* start_section = lua_touserdata(__ls,-6);
	W_Element_Section* element_section = lua_touserdata(__ls,-5);
	W_Code_Section* code_section = lua_touserdata(__ls,-4);
	W_Data_Section* data_section = lua_touserdata(__ls,-3);
	void** W_Custom_Sections = lua_touserdata(__ls,-2);
	char* name = lua_tostring(__ls,-1);
	Wasm_Module* dummy = push_Wasm_Module(__ls);
	dummy->type_section = type_section;
	dummy->import_section = import_section;
	dummy->function_section = function_section;
	dummy->table_section = table_section;
	dummy->memory_section = memory_section;
	dummy->global_section = global_section;
	dummy->export_section = export_section;
	dummy->start_section = start_section;
	dummy->element_section = element_section;
	dummy->code_section = code_section;
	dummy->data_section = data_section;
	dummy->W_Custom_Sections = W_Custom_Sections;
	dummy->name = name;
	return 1;
}

static int getter_Wasm_Module_type_section(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	lua_pop(__ls, -1);
	lua_pushlightuserdata(__ls, dummy->type_section);
	return 1;
}
static int getter_Wasm_Module_import_section(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	lua_pop(__ls, -1);
	lua_pushlightuserdata(__ls, dummy->import_section);
	return 1;
}
static int getter_Wasm_Module_function_section(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	lua_pop(__ls, -1);
	lua_pushlightuserdata(__ls, dummy->function_section);
	return 1;
}
static int getter_Wasm_Module_table_section(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	lua_pop(__ls, -1);
	lua_pushlightuserdata(__ls, dummy->table_section);
	return 1;
}
static int getter_Wasm_Module_memory_section(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	lua_pop(__ls, -1);
	lua_pushlightuserdata(__ls, dummy->memory_section);
	return 1;
}
static int getter_Wasm_Module_global_section(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	lua_pop(__ls, -1);
	lua_pushlightuserdata(__ls, dummy->global_section);
	return 1;
}
static int getter_Wasm_Module_export_section(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	lua_pop(__ls, -1);
	lua_pushlightuserdata(__ls, dummy->export_section);
	return 1;
}
static int getter_Wasm_Module_start_section(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	lua_pop(__ls, -1);
	lua_pushlightuserdata(__ls, dummy->start_section);
	return 1;
}
static int getter_Wasm_Module_element_section(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	lua_pop(__ls, -1);
	lua_pushlightuserdata(__ls, dummy->element_section);
	return 1;
}
static int getter_Wasm_Module_code_section(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	lua_pop(__ls, -1);
	lua_pushlightuserdata(__ls, dummy->code_section);
	return 1;
}
static int getter_Wasm_Module_data_section(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	lua_pop(__ls, -1);
	lua_pushlightuserdata(__ls, dummy->data_section);
	return 1;
}
static int getter_Wasm_Module_W_Custom_Sections(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	lua_pop(__ls, -1);
	lua_pushlightuserdata(__ls, dummy->W_Custom_Sections);
	return 1;
}
static int getter_Wasm_Module_name(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	lua_pop(__ls, -1);
	lua_pushstring(__ls, dummy->name);
	return 1;
}

static int setter_Wasm_Module_type_section(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	dummy->type_section = luaL_checkudata(__ls, 2, "Wasm_Module");
	lua_settop(__ls, 1);
	return 1;
}
static int setter_Wasm_Module_import_section(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	dummy->import_section = luaL_checkudata(__ls, 2, "Wasm_Module");
	lua_settop(__ls, 1);
	return 1;
}
static int setter_Wasm_Module_function_section(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	dummy->function_section = luaL_checkudata(__ls, 2, "Wasm_Module");
	lua_settop(__ls, 1);
	return 1;
}
static int setter_Wasm_Module_table_section(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	dummy->table_section = luaL_checkudata(__ls, 2, "Wasm_Module");
	lua_settop(__ls, 1);
	return 1;
}
static int setter_Wasm_Module_memory_section(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	dummy->memory_section = luaL_checkudata(__ls, 2, "Wasm_Module");
	lua_settop(__ls, 1);
	return 1;
}
static int setter_Wasm_Module_global_section(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	dummy->global_section = luaL_checkudata(__ls, 2, "Wasm_Module");
	lua_settop(__ls, 1);
	return 1;
}
static int setter_Wasm_Module_export_section(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	dummy->export_section = luaL_checkudata(__ls, 2, "Wasm_Module");
	lua_settop(__ls, 1);
	return 1;
}
static int setter_Wasm_Module_start_section(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	dummy->start_section = luaL_checkudata(__ls, 2, "Wasm_Module");
	lua_settop(__ls, 1);
	return 1;
}
static int setter_Wasm_Module_element_section(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	dummy->element_section = luaL_checkudata(__ls, 2, "Wasm_Module");
	lua_settop(__ls, 1);
	return 1;
}
static int setter_Wasm_Module_code_section(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	dummy->code_section = luaL_checkudata(__ls, 2, "Wasm_Module");
	lua_settop(__ls, 1);
	return 1;
}
static int setter_Wasm_Module_data_section(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	dummy->data_section = luaL_checkudata(__ls, 2, "Wasm_Module");
	lua_settop(__ls, 1);
	return 1;
}
static int setter_Wasm_Module_W_Custom_Sections(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	dummy->W_Custom_Sections = luaL_checkudata(__ls, 2, "Wasm_Module");
	lua_settop(__ls, 1);
	return 1;
}
static int setter_Wasm_Module_name(lua_State* __ls) {
	Wasm_Module* dummy = check_Wasm_Module(__ls, 1);
	dummy->name = luaL_checkstring(__ls, 2);
	lua_settop(__ls, 1);
	return 1;
}

static const luaL_Reg Wasm_Module_methods[] = {
	{"new", new_Wasm_Module},
	{"set_type_section", setter_Wasm_Module_type_section},
	{"set_import_section", setter_Wasm_Module_import_section},
	{"set_function_section", setter_Wasm_Module_function_section},
	{"set_table_section", setter_Wasm_Module_table_section},
	{"set_memory_section", setter_Wasm_Module_memory_section},
	{"set_global_section", setter_Wasm_Module_global_section},
	{"set_export_section", setter_Wasm_Module_export_section},
	{"set_start_section", setter_Wasm_Module_start_section},
	{"set_element_section", setter_Wasm_Module_element_section},
	{"set_code_section", setter_Wasm_Module_code_section},
	{"set_data_section", setter_Wasm_Module_data_section},
	{"set_W_Custom_Sections", setter_Wasm_Module_W_Custom_Sections},
	{"set_name", setter_Wasm_Module_name},
	{"type_section", getter_Wasm_Module_type_section},
	{"import_section", getter_Wasm_Module_import_section},
	{"function_section", getter_Wasm_Module_function_section},
	{"table_section", getter_Wasm_Module_table_section},
	{"memory_section", getter_Wasm_Module_memory_section},
	{"global_section", getter_Wasm_Module_global_section},
	{"export_section", getter_Wasm_Module_export_section},
	{"start_section", getter_Wasm_Module_start_section},
	{"element_section", getter_Wasm_Module_element_section},
	{"code_section", getter_Wasm_Module_code_section},
	{"data_section", getter_Wasm_Module_data_section},
	{"W_Custom_Sections", getter_Wasm_Module_W_Custom_Sections},
	{"name", getter_Wasm_Module_name},
	{0,0}
};

static const luaL_Reg Wasm_Module_meta[] = {
	{0, 0}
};

int Wasm_Module_register(lua_State* __ls) {
	luaL_openlib(__ls, "Wasm_Module", Wasm_Module_methods, 0);
	luaL_newmetatable(__ls, "Wasm_Module");
	luaL_openlib(__ls, 0, Wasm_Module_meta, 0);
	lua_pushliteral(__ls, "__index");
	lua_pushvalue(__ls, -3);
	lua_rawset(__ls, -3);
	lua_pushliteral(__ls, "__metatable");
	lua_pushvalue(__ls, -3);
	lua_rawset(__ls, -3);
	lua_pop(__ls, 1);
return 1;
}

