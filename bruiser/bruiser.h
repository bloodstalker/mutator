
/***************************************************Project Mutator****************************************************/
//-*-c++-*-
/*first line intentionally left blank.*/
/*the header for bruiser's main.*/
/*Copyright (C) 2017 Farzad Sadeghi

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
/*code structure inspired by Eli Bendersky's tutorial on Rewriters.*/
/**********************************************************************************************************************/
/*inclusion guard*/
#ifndef BRUISER_H
#define BRUISER_H
/**********************************************************************************************************************/
/*included modules*/
/*project headers*/
#include "../tinyxml2/tinyxml2.h"
/*standard library headers*/
#include <string>
#include <fstream>
/*clang headers*/
#include "clang/AST/ASTContext.h"
#include "clang/AST/Expr.h"
#include "clang/AST/Type.h"
#include "clang/AST/ASTTypeTraits.h"
/*llvm headers*/
/**********************************************************************************************************************/
/*using*/
using namespace tinyxml2;
using namespace llvm;
using namespace clang;
/**********************************************************************************************************************/
namespace bruiser
{ //start of namespace bruiser
/**********************************************************************************************************************/
  const char* M0REP = "../test/misrareport.xml";
/**********************************************************************************************************************/
#define JOIN2(x1, x2) x1##x2
#define JOIN3(x1, x2, x3) x1##x2##x3

#define PTR_NVA(x1, x2) x1(*)(x2)
#define PTR_VA(x1, x2) x1(*)(x2, ...)

#define RED "\033[1;31m"
#define CYAN "\033[1;36m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define BLACK "\033[1;30m"
#define BROWN "\033[1;33m"
#define MAGENTA "\033[1;35m"
#define GRAY "\033[1;37m"
#define DARKGRAY "\033[1;30m"
#define YELLOW "\033[1;33m"
#define NORMAL "\033[0m"
#define CLEAR	"\033[2J"

#define LN_RED 31
#define LN_GREEN 32
#define LN_YELLOW 33
#define LN_BLUE 34
#define LN_MAGENTA 35
#define LN_CYAN 36
#define LN_WHITE 37

#define BOLD 1
#define NO_BOLD 0

#define SHELL_HISTORY_SIZE  10000
#define SHELL_HISTORY_FILE "bruiser-history.txt"

#define GLOBAL_TIME_OUT 100000

#define NOT_IMPLEMENTED \
  do{\
    printf(BROWN "not implemented yet.");\
    printf(NORMAL"\n");\
  }while(0)

#define  PRINT_WITH_COLOR(X,Y) \
  do{\
    printf(X Y NORMAL);\
  }while(0)

#define  PRINT_WITH_COLOR_LB(X,Y) \
  do{\
    printf(X "%s", Y);\
    printf(NORMAL"\n");\
  }while(0)
/**********************************************************************************************************************/
/*Error Codes*/
#define M0_ERROR_CODES \
  X(BAD_M0_XML, "bad m0 xml.", 100) \
  X(CANT_OPEN_M0_XML, "could not open m0 xml.", 101) \

#define X(__x1, __x2, __x3) __x1,
  enum class M0_ERR {M0_ERROR_CODES};
#undef X
/**********************************************************************************************************************/
/*Enums*/
/**********************************************************************************************************************/
struct help
{
  public:
    std::string name;
    std::string proto;
    std::string descr;
    std::string protoprefix;
    std::string retval;
};

help CMDHelp[] = {
  {"help()", "help()", "display general help", "none", "none"},
  {"quit()", "quit()", "quit bruiser", "none", "none"},
  {"exit()", "exit()", "quit bruiser", "none", "none"},
  {"m0()", "m0()", "bruiser reads the report generated by mutator-lvl0", "", ""},
  {"readxmlfile()", "readxmlfile(\"myxml.xml\")", "bruiser reads the specified xml file, if no argument is provided bruiser tries to read the m0 report at the default location", "", "tinyxml2::XMLError"},
  {"hijackmain()", "hijackmain()", "runs a specific matcher that replaces the main with a new main", "none", "returns the rewritten source code as a string"},
  {"clear()", "clear()", "clears the terminal", "", "none"},
  {"history()", "", "prints bruiser's history", "", "none"},
  {"!", "", "prints the command from history", "", "none"},
  {"Vars()", "", "lists all available variable declarations", "none", "returns a string array of the variable declarations"},
  {"Funcs()", "", "lists all available function declarations", "none", "returns a string array of the function declarations"},
  {"Classess()", "", "lists all available class declarations", "none", "returns a string array of the class declarations"},
  {"Structs()", "", "lists all available struct declarations", "none", "returns a string array of the structure declarations"},
  {"Arrays()", "", "lists all available array declarations", "none", "returns a string array of the array declarations"},
  {"Unions()", "", "lists all available union declarations", "none", "returns a string array of the union declarations"},
  {"make()", "make(\"all\")", "runs your make command", "", ""},
  {"historysize()", "historysize(200)", "sets the history size", "[uint history_size]", "none"},
  {"showsource()", "showsource(1,5,\"test.cpp\")", "shows the source code for the given range and filename", "[uint beginline, uint endline, string filename]", "returns a string array of the returned source file"},
  {"extractmutagen()", "extractmutagen(\"test.cpp\")", "runs m0 on the source(s)", "[string]", "pid"},
  {"strainrecognition()", "", "", "", ""},
  {"setmakepath()", "setmakepath(\"../../myproject\")", "tells bruiser where to execute the make command run from make()", "string", "none"},
  {"run()", "run(\"myexecutable\")", "runs the mutant", "string", "return value"},
  {"setbinpath()", "setbinpath(\"bin_path\")", "sets the binary path for mutant executable", "string", "none"},
  {"getbinpath()", "getbinpath()", "gets the binary path for mutant executable", "none", "string"},
  {"getmakepath()", "getmakepath()", "gets the make path for mutant executable", "none", "string"},
  {"getpaths()", "getpaths()", "gets the currently loaded paths that bruiser looks through", "none", "array of strings"},
  {"getsourcefiles()", "getsourcefiles()", "gets the currently loaded source files that bruiser will look through", "none", "array of strings"},
  {"changedirectory()", "changedirectory()", "changes bruiser's working directory. only use it when you know what you are doing.", "destination directory, [string]", "return value"},
  {"pwd()", "pwd()", "pwd", "", ""},
  {"objload()", "objload(\"main\", \"../bfd/test/test.so\")", "load the compiled functions into bruiser", "string", "success or failure"},
  {"listObjects()", "listObjects(\"function\")", "lists the loaded objects of the given type", "string", "success or failure"},
  {"xobjwrapper()", "xobjwrapper(\"function\")", "call an xobject", "", "success or failure"},
  {"xobjregister", "xobjregister(code_table, registration_name)", "registers an xobject as a callable function from lua", "", "pointer to the function"},
  {"xcall", "xcall(index, num_args)", "call xobj with the given index in to the xobj vector with the given number of args", "", "returns the xobj call result"},
  {"xobjlist", "xobjlist()", "return a table containing xobj pointers and names. names are keys, values are the pointers.", "", "table of pairs"},
  {"xallocglobal", "xallocglobal(index)", "allocate a global value with index index", "", ""},
  {"xallocallglobals", "xallocallglobals()", "allocate all globals", "", ""},
  {"getjmptable", "getjmptable(size, code)", "get a table of all jumps", "", "returns a pointer to the head of the jump table linked-list as lightuserdata"},
  {"freejmptable", "freejmptable(head)", "free the jmp table linked-list", "", "nothing"},
  {"dumpjmptable", "dumpjmptable(head)", "dumps the jmp table linked-list", "", "nothing"},
  {"ramdump", "ramdump(pid)", "dumps the ram", "", "ram contents"}
};
/**********************************************************************************************************************/
/**
 * @brief This class handles the logging for bruiser.
 */
class BruiserReport
{
  public:
    BruiserReport ();

    ~BruiserReport();

    template <typename T>
    bool PrintToLog(T __arg);

  private:
    std::ofstream BruiserLog;
};
/**********************************************************************************************************************/
/**
 * @brief looks through types.
 */
class TypeInfo
{
  public:
    explicit TypeInfo(const clang::ast_type_traits::DynTypedNode* __dtn);

    ~TypeInfo();

    const clang::Type* getTypeInfo(clang::ASTContext* __astc);

  private:
    const clang::ast_type_traits::DynTypedNode* DTN;
};
/**********************************************************************************************************************/
class ReadM0
{
  public:
    /*default ctor*/
    ReadM0()
    {
      try
      {
      XMLError eResult [[maybe_unused]] = IntermediateXMLDoc.LoadFile(M0REP);

      RootPointer = IntermediateXMLDoc.FirstChild();
      }
      catch (std::exception& e)
      {

      }
    }

    /*asks for the xml report you want to read*/
    ReadM0(const char* __xml_report_file)
    {
      try
      {
      XMLError eResult [[maybe_unused]] = IntermediateXMLDoc.LoadFile(__xml_report_file);

      RootPointer = IntermediateXMLDoc.FirstChild();
      }
      catch (std::exception& e)
      {

      }
    }

    ~ReadM0() {}

    XMLError LoadXMLDoc(void)
    {
      XMLError eResult = IntermediateXMLDoc.LoadFile(M0REP);

      return eResult;
    }

    XMLError ReadFirstElement(void)
    {
      RootPointer = IntermediateXMLDoc.FirstChild();

      if (RootPointer == nullptr)
      {
        return XML_ERROR_FILE_READ_ERROR;
      }
      else
      {
        return XML_SUCCESS;
      }
    }

    XMLNode* getRootPointer(void)
    {
      return RootPointer;
    }

  private:
    void Debug(void)
    {

    }

    XMLDocument IntermediateXMLDoc;
    XMLNode* RootPointer;
};
/**********************************************************************************************************************/
class SearchM0
{
  public:
    SearchM0(XMLNode* __rptr) : RootPointer(__rptr) {}

    ~SearchM0() {};

    void Debug(void)
    {
      if (!RootPointer->NoChildren())
      {
        const XMLElement* XMLE [[maybe_unused]] = RootPointer->FirstChildElement();
      }
    }

  private:
    XMLNode* RootPointer;
};
/**********************************************************************************************************************/
class Daemonize
{
  public:
    Daemonize (std::string __exe, std::string __opts) : Exe(__exe), Opts(__opts) {}

  private:
    std::string Exe;
    std::string Opts;
};
/**********************************************************************************************************************/
/*structs to hold load.py's return values*/
/*@DEVI-at some point in the future i might revert to using libbfd or libelf.*/

/*elf*/
#define ELF_EI_MAGIC =      0x000000000000ffff;
#define ELF_EI_CLASS =      0x00000000000f0000;
#define ELF_EI_DATA =       0x0000000000f00000;
#define ELF_EI_VERSION =    0x000000000f000000;
#define ELF_EI_OSABI =      0x00000000f0000000;
#define ELF_EI_ABIVERSION = 0x0000000f00000000;
#define ELF_EI_PAD =        0xfffffff000000000;

// @DEVI-FIXME-using uint128 here
// fails to build on stock ubuntu 16.04
# if 0
struct ELFHDR_64 {
  public:
    ELFHDR_64() = default;
    ELFHDR_64(__uint128_t _ident, uint16_t _type, uint16_t _machine, 
        uint32_t _version, uint64_t _entry, uint64_t _phoff,  uint64_t _shoff, 
        uint32_t _flags, uint16_t _ehsize, uint16_t _phentsize, 
        uint16_t _phnum, uint16_t _shentsize, uint16_t _shnum, uint16_t _shstrndx) {
      e_ident = _ident; e_type = _type; e_machine = _machine; e_version = _version; 
      e_entry = _entry; e_phoff = _phoff; e_shoff = _shoff; e_flags = _flags;
      e_ehsize = _ehsize; e_phentsize = _phentsize; e_phnum = _phnum;
      e_shentsize = _shentsize; e_shnum = _shnum; e_shstrndx = _shstrndx;
    }
    __uint128_t e_ident; uint16_t e_type; uint16_t e_machine; uint32_t e_version; 
    uint64_t e_entry; uint64_t e_phoff; uint64_t e_shoff; uint32_t e_flags; 
    uint16_t e_ehsize; uint16_t e_phentsize; uint16_t e_phnum; uint16_t e_shentsize; 
    uint16_t e_shnum; uint16_t e_shstrndx;
};

// @DEVI-FIXME-using uint128 here
struct ELFHDR_32 {
  public:
    ELFHDR_32() = default;
    ELFHDR_32(__uint128_t _ident, uint16_t _type, uint16_t _machine, uint32_t _version, 
        uint32_t _entry, uint32_t _phoff, uint32_t _shoff, uint32_t _flags, 
        uint16_t _ehsize, uint16_t _phentsize, uint16_t _phnum, uint16_t _shentsize, 
        uint16_t _shnum, uint16_t _shstrndx) {
      e_ident = _ident; e_type = _type; e_machine = _machine; e_version = _version; 
      e_entry = _entry; e_phoff = _phoff; e_shoff = _shoff; e_flags = _flags;
      e_ehsize = _ehsize; e_phentsize = _phentsize; e_phnum = _phnum;
      e_shentsize = _shentsize; e_shnum = _shnum; e_shstrndx = _shstrndx;
    }

    __uint128_t e_ident; uint16_t e_type; uint16_t e_machine; uint32_t e_version;
    uint32_t e_entry; uint32_t e_phoff; uint32_t e_shoff; uint32_t e_flags;
    uint16_t e_ehsize; uint16_t e_phentsize; uint16_t e_phnum; uint16_t e_shentsize;
    uint16_t e_shnum; uint16_t e_shstrndx;
};
#endif
/*program header*/
struct PHDR_64 {
  public:
    PHDR_64() = default;
    PHDR_64(uint32_t _type, uint32_t _flags, uint64_t _offset, uint64_t _vaddr, 
        uint64_t _paddr, uint64_t _filesz, uint64_t _memsz, uint64_t _align) {
      p_type = _type; p_flags = _flags; p_offset = _offset; p_vaddr = _vaddr;
      p_paddr = _paddr; p_filesz = _filesz; p_memsz = _memsz; p_align = _align;
    }

    uint32_t p_type; uint32_t p_flags; uint64_t p_offset; uint64_t p_vaddr;
    uint64_t p_paddr; uint64_t p_filesz; uint64_t p_memsz; uint64_t p_align;
};
struct PHDR_32 {
  public:
    PHDR_32() = default;
    PHDR_32(uint32_t _type, uint32_t _offset, uint32_t _vaddr, uint32_t _paddr, 
        uint32_t _filesz, uint32_t _memsz, uint32_t _flags, uint32_t _align) {
      p_type = _type; p_flags = _flags; p_offset = _offset; p_vaddr = _vaddr;
      p_paddr = _paddr; p_filesz = _filesz; p_memsz = _memsz; p_align = _align;
    };

    uint32_t p_type;
    uint32_t p_offset;
    uint32_t p_vaddr;
    uint32_t p_paddr;
    uint32_t p_filesz;
    uint32_t p_memsz;
    uint32_t p_flags;
    uint32_t p_align;
};
/*section header*/
struct SHDR_64 {
  public:
    SHDR_64() = default;
    SHDR_64(uint32_t _name, uint32_t _type, uint64_t _flags, uint64_t _addr, 
        uint64_t _offset, uint64_t _size, uint32_t _link, uint32_t _info, 
        uint64_t _addralign, uint64_t _entsize) {
      sh_name = _name; sh_type = _type; sh_flags = _flags; sh_addr = _addr;
      sh_offset = _offset; sh_size = _size; sh_link = _link; sh_info = _info;
      sh_addralign = _addralign; sh_entsize = _entsize;
    };

    uint32_t sh_name; uint32_t sh_type; uint64_t sh_flags; uint64_t sh_addr;
    uint64_t sh_offset; uint64_t sh_size; uint32_t sh_link; uint32_t sh_info;
    uint64_t sh_addralign; uint64_t sh_entsize;
};
struct SHDR_32 {
  public:
    SHDR_32() = default;
    SHDR_32(uint32_t _name, uint32_t _type, uint32_t _flags, uint32_t _addr, 
        uint32_t _offset, uint32_t _size, uint32_t _link, uint32_t _info, 
        uint32_t _addralign, uint32_t _entsize) {
      sh_name = _name; sh_type = _type; sh_flags = _flags; sh_addr = _addr;
      sh_offset = _offset; sh_size = _size; sh_link = _link; sh_info = _info;
      sh_addralign = _addralign; sh_entsize = _entsize;
    };

    uint32_t sh_name; uint32_t sh_type; uint32_t sh_flags; uint32_t sh_addr;
    uint32_t sh_offset; uint32_t sh_size; uint32_t sh_link; uint32_t sh_info;
    uint32_t sh_addralign; uint32_t sh_entsize;
};
/*symbol table entry*/
struct ST_Entry_64 {};
struct ST_Entry_32 {};
/**********************************************************************************************************************/
} // end of namespace bruiser
#endif
/*last line intentionally left balnk.*/

