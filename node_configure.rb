#!/usr/bin/ruby


print "Number of nodes: "
num_nodes = gets.to_i
pins_reqd = ((1+Math.sqrt(1+4*num_nodes))/2).ceil
puts "You will need #{pins_reqd} pins."
print "Enter their numbers: "
pin_nums = gets.scan(/\d+/).map{|n|n.to_i}

puts "Here is a list of connections you should make:"
pin_map = num_nodes.times.map do |n|
  hi_pin, lo_pin = n.divmod(pins_reqd-1)
  lo_pin +=1 if lo_pin >= hi_pin
  [hi_pin, lo_pin]
end
pin_nums.each_with_index do |n,i|
  nodelist = []
  pin_map.each_with_index do |(hi,lo),node|
    if hi == i
      nodelist << [node,1]
    elsif lo == i
      nodelist << [node,-1]
    end
  end
  list = nodelist.map{|node, p| "#{node}#{p<0?"+":"-"}"}.join " "
  puts "Pin #{n}: #{list}"
end
puts
puts "Make sure to use one resistor per pin!"