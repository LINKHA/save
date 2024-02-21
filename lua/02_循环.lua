-- while
a=10
while( a < 20 )
do
   print("a 的值为:", a)
   a = a+1
end
print("-------------------------------------")

function f(x)
    print("function")
    return x*2
end

for i=1,f(5) do 
    print(i)
end
print("-------------------------------------")
-- for var=exp1,exp2,exp3 do  
--     <执行体>  
-- end  
-- var 从 exp1 变化到 exp2，每次变化以 exp3 为步长递增 var，并执行一次 "执行体"。exp3 是可选的，如果不指定，默认为1。
for i=10,1,-1 do
    print(i)
end
print("-------------------------------------")
--打印数组a的所有值  
a = {"one", "two", "three"}
for i, v in ipairs(a) do
	print(i, v)
end 

print("-------------------------------------")
--[ 变量定义 --]
a = 10
--[ 执行循环 --]
repeat
   print("a的值为:", a)
   a = a + 1
until( a > 15 )