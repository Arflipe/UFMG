#= 
=#

using JuMP
using HiGHS

mutable struct 
end

function readData(file)
end

model = Model(HiGHS.Optimizer)
set_silent(model)

file = open(ARGS[1], "r")

data = readData(file)

optimize!(model)

sol = objective_value(model)
println("TP1 2021031920 = ", sol)