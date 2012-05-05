
sum = 0
(0...1000000).each do |i|
  s10 = i.to_s(10)
  s2 = i.to_s(2)
  if s10[0...(s10.length/2)] == s10[-(s10.length/2)..-1].reverse
    if s2[0...(s2.length/2)] == s2[-(s2.length/2)..-1].reverse
      p s10, s2
    end
  end
end
p sum
