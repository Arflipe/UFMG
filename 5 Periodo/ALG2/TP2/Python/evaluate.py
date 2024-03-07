import sys

filename = sys.argv[1]
file = open(filename, "r")
lines = file.readlines()
file.close()

cost = float(lines[1].split()[1])

datasetName = filename.split("/")[-1].split(".")[0]

solutionLocation = sys.argv[2]
solution = open(solutionLocation, "r")
lines = solution.readlines()
solution.close()


for line in lines:
	if line.startswith(datasetName):
		words = line.split()
		optimalSolution = words[-1]
		break

# if optimalSolution is in format "[n0,n1]", calculate solQual1 = cost / n0 and solQual2 = cost / n1 and print (datasetName + " solution quality: [" + str(solQual1) + "," + str(solQual2) + "]")
if optimalSolution.startswith("["):
	optimalSolution = optimalSolution[1:-1]
	optimalSolution = optimalSolution.split(",")
	solutionQuality = []
	for n in optimalSolution:
		solutionQuality.append(cost / float(n))
	print(datasetName + " solution quality: " + str(solutionQuality))
else:
	solutionQuality = cost / float(optimalSolution)
	print(datasetName + " solution quality: " + str(solutionQuality))