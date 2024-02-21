-- 示例表
myTable = { "apple", "orange", color="blue", "banana" }

-- 使用 ipairs 迭代数组部分
print("Using ipairs:")
for index, value in ipairs(myTable) do
    print(index, value)
end

-- 输出：
-- 1    apple
-- 2    orange

-- 使用 pairs 迭代所有键值对
print("\nUsing pairs:")
for key, value in pairs(myTa.
ble) do
    print(key, value)
end

-- 输出：
-- 1    apple
-- 2    orange
-- color    blue
-- 3    banana
