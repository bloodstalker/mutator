
-- luarocks install luaposix
--local posix = require("posix")

function reg_test()
  local xobj = require("demo1")
  local jmp_table = require("demo2")
  local asm_rewriter = require("asmtest")
  local wasm_import = require("demo3")
  local libwasm = require("wasmtest")

  local argparse = require("argparse")

  local parser = argparse("regtest", "bruiser's regression test script")
  parser:flag("-x --xobj")
  parser:flag("-j --jmpt")
  parser:flag("-a --asm")
  parser:flag("-w --wasm")
  --libwasm.demo("/home/bloodstalker/devi/hell2/bruiser/autogen/wasm/ft/test.wasm")

end

reg_test()
