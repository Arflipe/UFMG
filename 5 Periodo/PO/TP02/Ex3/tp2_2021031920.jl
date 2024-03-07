mutable struct BacklogLotsizing
	numPeriods::Int
	demand::Array{Int64}
	productionCost::Array{Float64}
	storageCost::Array{Float64}
	fine::Array{Float64}
end

function readData(file)
	numPeriods = 0
	demand = []
	productionCost = []
	storageCost = []
	fine = []
	for l in eachline(file)
		q = split(l, '\t')
		num = parse(Int64, q[2])
		if q[1] == "n"
			numPeriods = num
			demand = [0 for i in 1:numPeriods]
			productionCost = [0.0 for i in 1:numPeriods]
			storageCost = [0.0 for i in 1:numPeriods]
			fine = [0.0 for i in 1:numPeriods]
		elseif q[1] == "d"
			demand[num] = parse(Int64, q[3])
		elseif q[1] == "c"
			productionCost[num] = parse(Float64, q[3])
		elseif q[1] == "s"
			storageCost[num] = parse(Float64, q[3])
		elseif q[1] == "p"
			fine[num] = parse(Float64, q[3])
		end
	end
	return BacklogLotsizing(numPeriods, demand, productionCost, storageCost, fine)
end

function optimize(data)
	producedInPeriod = [0 for i in 1:data.numPeriods]
	totalCost = 0.0

	for i in 1:data.numPeriods
		priceOfProducingInPeriod = [0 for i in 1:data.numPeriods]

		accumulatedStorageCost = 0
		if i > 1	
			for j in (i-1):-1:1
				accumulatedStorageCost += data.storageCost[j]
				priceOfProducingInPeriod[j] = data.productionCost[j] + accumulatedStorageCost
			end 
		end

		priceOfProducingInPeriod[i] = data.productionCost[i]

		accumulatedFine = 0
		if i < data.numPeriods
			for j in (i+1):data.numPeriods
				accumulatedFine += data.fine[j-1]
				priceOfProducingInPeriod[j] = data.productionCost[j] + accumulatedFine
			end
		end
		
		minIndex = argmin(priceOfProducingInPeriod)
		producedInPeriod[minIndex] += data.demand[i]
		totalCost += priceOfProducingInPeriod[minIndex] * data.demand[i]
	end

	println("TP2 2021031920 = ", totalCost)
	print(producedInPeriod[1])
	for i in 2:data.numPeriods
		print("\t", producedInPeriod[i])
	end
end

file = open(ARGS[1], "r")

data = readData(file)

close(file)

optimize(data)