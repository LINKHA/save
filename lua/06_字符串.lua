string1 = "Lua"
print("\"字符串 1 是\"",string1)
string2 = 'runoob.com'
print("字符串 2 是",string2)

string3 = [["Lua 教程"]]
print("字符串 3 是",string3)

--字符串长度计算
local myString = "Hello, RUNOOB!"
print("-------------------------------------")
-- 计算字符串的长度（字符个数）
local length = string.len(myString)

print(length) -- 输出 14