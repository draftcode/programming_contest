def count(i)
  ret = 0
  i.to_s(2).each_char do |c|
    ret += 1 if c == "1" 
  end
  ret
end

t = gets().to_i
t.times do |i|
  a = gets().to_i
  b = 0
  max = 0
  while a >= b
    temp = count(a) + count(b)
    if temp > max
      max = temp
    end
    a -= 1
    b += 1
  end
  puts "Case \##{i+1}: #{max.to_s}"
end
