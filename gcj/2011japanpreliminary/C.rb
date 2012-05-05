t = gets().to_i
t.times do |i|
  b_in = gets().to_i.to_s(2)
  if b_in == "1"
    ret = 1
  else
    ret = b_in.length() - 1
    b_in = b_in[1..-1]
    b_in = (b_in.to_i(2) + 1).to_s(2)
    b_in.each_char do |c|
      ret += 1 if c == "1" 
    end
  end
  puts "Case \##{i+1}: #{ret.to_s}"
end
