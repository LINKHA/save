mytable = setmetatable({key1 = "value1"}, {
  __index = function(mytable, key)
    if key == "key2" then
      return "metatablevalue"
    else
      return nil
    end
  end
})

print(mytable.key1,mytable.key2)

print("-------------------------------------")

mymetatable = {}
mytable = setmetatable({key1 = "value1"}, { __newindex = mymetatable })

print(mytable.key1)

mytable.newkey = "新值2"
print(mytable.newkey,mymetatable.newkey)

mytable.key1 = "新值1"
print(mytable.key1,mymetatable.key1)

print("-------------------------------------")

mytable = setmetatable({key1 = "value1"}, {
  __newindex = function(mytable, key, value)
      rawset(mytable, key, "\""..value.."\"")
  end
})

mytable.key1 = "new value"
mytable.key2 = 4

print(mytable.key1,mytable.key2)

print("-------------------------------------")

-- 计算表中最大值，table.maxn在Lua5.2以上版本中已无法使用
-- 自定义计算表中最大键值函数 table_maxn，即返回表最大键值
function table_maxn(t)
  local mn = 0
  for k, v in pairs(t) do
      if mn < k then
          mn = k
      end
  end
  return mn
end

-- 两表相加操作
mytable = setmetatable({ 1, 2, 3 }, {
__add = function(mytable, newtable)
  for i = 1, table_maxn(newtable) do
    table.insert(mytable, table_maxn(mytable)+1,newtable[i])
  end
  return mytable
end
})

secondtable = {4,5,6}

mytable = mytable + secondtable
      for k,v in ipairs(mytable) do
print(k,v)
end

print("-------------------------------------")

-- 计算表中最大值，table.maxn在Lua5.2以上版本中已无法使用
-- 自定义计算表中最大键值函数 table_maxn，即计算表的元素个数
function table_maxn(t)
  local mn = 0
  for k, v in pairs(t) do
      if mn < k then
          mn = k
      end
  end
  return mn
end

-- 定义元方法__call
mytable = setmetatable({10}, {
__call = function(mytable, newtable)
      sum = 0
      for i = 1, table_maxn(mytable) do
              sum = sum + mytable[i]
      end
  for i = 1, table_maxn(newtable) do
              sum = sum + newtable[i]
      end
      return sum
end
})
newtable = {10,20,30}
print(mytable(newtable))