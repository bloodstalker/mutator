
xobj = require("lua-scripts.xobj")
colors = require("ansicolors")
elf_file = "../bfd/test/test.so"
elf_exe = "../bfd/test/test"

function main()
  xobj.getSO(elf_file)
  local add2_code = xobj.codeTableByName_number("'add2'")
  local sub2_code = xobj.codeTableByName_number("'sub2'")
  local adddouble_code = xobj.codeTableByName_number("'adddouble'")
  local subdouble_code = xobj.codeTableByName_number("'subdouble'")
  local triple_code = xobj.codeTableByName_number("'triple'")
  local quad_code = xobj.codeTableByName_number("'quad'")
  local passthrough_code = xobj.codeTableByName_number("'passthrough'")

  --xobj.printFuncSizes()

  xobjregister(add2_code, "add2")
  xobjregister(sub2_code, "sub2")
  xobjregister(adddouble_code, "adddouble")
  xobjregister(subdouble_code, "subdouble")
  xobjregister(triple_code, "triple")
  xobjregister(quad_code, "quad")
  xobjregister(passthrough_code, "passthrough")
end

function pretty_dump()
  count = 0
  local text_section = xobj.getTextSection()
  io.write(colors("%{blue}".."    ".."\t".."00 ".."01 ".."02 ".."03 ".."04 ".."05 ".."06 ".."07 ".."08 ".."09 ".."0A ".."0B ".."0C ".."0D ".."0E ".."0F"))
  for k,v in pairs(text_section) do
    if count % 16 == 0 then
      print()
      io.write(colors("%{blue}".."0x"..string.format("%03x",count)), "\t")
    end
    io.write(colors("%{green}"..string.format("%02x", v)), " ")
    count = count + 1
  end
  count = 0
  print()
end

function test()
  local text_section = xobj.getTextSection()
  dummy = xobj.CSDump(text_section)
  print(dummy)
end

function asm_rewriter()
  local text_section = xobj.getTextSection()
  local head = getjmptable(#text_section, text_section)
  print("head value is",head)
  dumpjmptable(head)
  freejmptable(haed)
end

setmetatable(jmp_s_t, {__call = function(self, arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12)
                                  local t = self.new(arg1,arg2,arg3,arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12)
                                  print("created", t)
                                  return t
                                end})

function jmp_s_t:show(msg)
  print(msg, self, self:custom())
  return self
end

function jmp_t_test()
  local t = jmp_s_t.new(1,2,3,nil,nil,nil,7,8,9,0,0,1)
  t:show("t is")
  local t_next = jmp_s_t.new()
  local t_next_y = jmp_s_t.new()
  local t_next_n = jmp_s_t.new()
  t:set_next(t_next)
  t:set_next_y(t_next_y)
  t:set_next_n(t_next_n)
  t:show("t is")
  tt = jmp_s_t()
  tt:show("tt is")
  --collectgarbage()
  --t:show("t is")
end

function integ_test()
  local text_section = xobj.getTextSection()
  local head = jmp_s_t.new()
  head = getjmptable(#text_section, text_section)
  head:show("XXXXXhead is")
  print(head:location())
  --while head:next() ~= nil do
  for i=1,11,1 do
    head = head:next()
    head:show("next is")
  end
end

--main()
--pretty_dump()
--test()
--asm_rewriter()
--jmp_t_test()
integ_test()
