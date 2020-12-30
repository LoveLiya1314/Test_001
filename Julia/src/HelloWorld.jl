#=
HelloWorld:
- Julia version: 1.4.2
- Author: Lambert
- Date: 2020-06-03
=#
println("Hello World")

###============================================================================================================###
###============================================================================================================###
###============================================================================================================###

#=
Generate one million random data,
the data is height and weight,
calculate the physical condition through the BMI formula
Finally through classification, the obtained data is classified!!!
=#


heights =rand(Float64,100000000)
weights=rand(Float64,100000000)
heights=heights .* (1.8-1.5) .+1.5
weights=weights .* (100-30) .+30
bmi(w,h)=w/(h^2)
indexes= broadcast(bmi,weights,heights)
function bmi_category(index::Float64)
    class=0
    if index<18.5
        class=1
    elseif index < 24
        class=2
    elseif index <28
        class=3
    elseif index <30
        class=4
    elseif index <40
        class=5
    else
        class=6
    end
    class
end
classes=bmi_category.(indexes)
for c in [1 2 3 4 5 6]
    n =count(x->(x==c),classes)
    println("category",c," ",n)
end


###============================================================================================================###
###============================================================================================================###
###============================================================================================================###

