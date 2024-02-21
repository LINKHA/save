-- 使用冒号调用对象方法
local myObject = {
    value = 42,
    multiply = function(self, factor)
        return self.value * factor
    end
}

-- 调用对象方法使用冒号
local result = myObject:multiply(2)
print(result)  -- 输出: 84

-- 使用点调用全局函数或对象字段
local globalFunction = function(x)
    return x * 2
end

-- 调用全局函数使用点
local globalResult = globalFunction(3)
print(globalResult)  -- 输出: 6
  