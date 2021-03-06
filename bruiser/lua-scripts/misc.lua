
------------------------------------------------Project Mutator-----------------------------------------------
--bruiser's lua functions that fall under misc or util
--Copyright (C) 2018 Farzad Sadeghi

--This program is free software; you can redistribute it and/or
--modify it under the terms of the GNU General Public License
--as published by the Free Software Foundation; either version 3
--of the License, or (at your option) any later version.

--This program is distributed in the hope that it will be useful,
--but WITHOUT ANY WARRANTY; without even the implied warranty of
--MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
--GNU General Public License for more details.

--You should have received a copy of the GNU General Public License
--along with this program; if not, write to the Free Software
--Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.*/
--------------------------------------------------------------------------------------------------------------
--start of xobj module
local misc = {}

function misc.pgrep(name)
  local handle = io.popen("pgrep "..name)
  local ret = {}
  for line in handle:lines() do
    table.insert(ret, tonumber(line))
  end
  return ret
end

--end of xobj module
return misc
--------------------------------------------------------------------------------------------------------------

