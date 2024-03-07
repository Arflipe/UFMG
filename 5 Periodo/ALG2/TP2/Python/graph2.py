import pandas as pd
import sys
import os
import matplotlib.pyplot as plt
import matplotlib.pyplot as plt

folderName1 = sys.argv[1]
folderName2 = sys.argv[2]

solutionQualityFile1 = sys.argv[3]
solutionQualityFile2 = sys.argv[4]

optimalSolutionsFile = sys.argv[5]

file = open(optimalSolutionsFile, "r")
lines = file.readlines()
file.close()

fileNames = []

for line in lines:
	fileNames.append(line.split()[0])

# remove first fileName, which is the header
fileNames = fileNames[1:]

fileNames.sort(key=lambda x: int(''.join(filter(str.isdigit, x))))

# Process each file in the first folder
residentSetSizes1 = []
userTimes1 = []
vertexCounts1 = []
quality1 = []

for filename in fileNames:
	filePath = os.path.join(folderName1, filename + '.tsp.time')
	vertexCount = int(''.join(filter(str.isdigit, filename)))
	try:
		with open(filePath, 'r') as file:
			lines = file.readlines()
			# if empty, throw FileNotFoundError
			if len(lines) == 0:
				raise FileNotFoundError
			userTime = None
			residentSetSize = None
			# remove the extension
			filename = filename.split('.')[0]
			for line in lines:
				if 'User time (seconds):' in line:
					userTime = float(line.split(':')[1].strip())
				elif 'Maximum resident set size (kbytes):' in line:
					residentSetSize = int(line.split(':')[1].strip())
				if userTime is not None and residentSetSize is not None:
					break

			# Separate the data for memory usage and user time
			residentSetSize = residentSetSize / 1024  # get the memory as megabytes
			userTime = userTime / 60  # get time as minutes
			# round seconds
			userTime = round(userTime, 2)

			residentSetSizes1.append(residentSetSize)
			userTimes1.append(userTime)
			vertexCounts1.append(vertexCount)

	except FileNotFoundError:
		residentSetSizes1.append(-1)
		userTimes1.append(-1)
		vertexCounts1.append(vertexCount)

# Get the solution quality data for the first folder
with open(solutionQualityFile1, 'r') as file:
	lines = file.readlines()
	for name in fileNames:
		# find the line with the dataset name, if not found, set quality to None
		for line in lines:
			if line.startswith(name):
				words = line.split()
				optimalSolution = words[-1]
				if optimalSolution.endswith(']'):
					optimalSolution = optimalSolution[:-1]
				break
		else:
			optimalSolution = -1
		quality1.append(optimalSolution)


# Process each file in the second folder
residentSetSizes2 = []
userTimes2 = []
vertexCounts2 = []
quality2 = []

for filename in fileNames:
	filePath = os.path.join(folderName2, filename + '.tsp.time')
	vertexCount = int(''.join(filter(str.isdigit, filename)))
	try:
		with open(filePath, 'r') as file:
			lines = file.readlines()
			if len(lines) == 0:
				raise FileNotFoundError
			userTime = None
			residentSetSize = None
			# remove the extension
			filename = filename.split('.')[0]
			for line in lines:
				if 'User time (seconds):' in line:
					userTime = float(line.split(':')[1].strip())
				elif 'Maximum resident set size (kbytes):' in line:
					residentSetSize = int(line.split(':')[1].strip())
				if userTime is not None and residentSetSize is not None:
					break

			# Separate the data for memory usage and user time
			residentSetSize = residentSetSize / 1024  # get the memory as megabytes
			userTime = userTime / 60  # get time as minutes
			# round seconds
			userTime = round(userTime, 2)

			residentSetSizes2.append(residentSetSize)
			userTimes2.append(userTime)
			vertexCounts2.append(vertexCount)

			# if userTime is None or residentSetSize is None:
			# 	quality2.append("None")
	except FileNotFoundError:
		residentSetSizes2.append(-1)
		userTimes2.append(-1)
		vertexCounts2.append(vertexCount)

# print all arrays

# Get the solution quality data for the second folder
with open(solutionQualityFile2, 'r') as file:
	lines = file.readlines()
	for name in fileNames:
		# find the line with the dataset name, if not found, set quality to None
		for line in lines:
			if line.startswith(name):
				words = line.split()
				optimalSolution = words[-1]
				if optimalSolution.endswith(']'):
					optimalSolution = optimalSolution[:-1]
				break
		else:
			optimalSolution = -1
		quality2.append(optimalSolution)

quality1 = [round(float(x), 2) for x in quality1]
quality2 = [round(float(x), 2) for x in quality2]

# Create a DataFrame for the data in the first folder
data1 = pd.DataFrame({'Dataset': fileNames, 'Vertex Count': vertexCounts1, 'Memory Usage (MB)': residentSetSizes1, 'User Time (Min)': userTimes1, 'Quality': quality1})

# Save the data from the first folder as a table
data1.to_csv(sys.argv[6] + 'Table1.csv', index=False)


# Create a DataFrame for the data in the second folder
data2 = pd.DataFrame({'Dataset': fileNames, 'Vertex Count': vertexCounts2, 'Memory Usage (MB)': residentSetSizes2, 'User Time (Min)': userTimes2, 'Quality': quality2})

# Save the data from the second folder as a table
data2.to_csv(sys.argv[6] + 'Table2.csv', index=False)


# x is log scale
plt.xscale('log')

# Create and save the graph of memory usage by vertex count for both folders
plt.plot(vertexCounts1, residentSetSizes1, 'bo-', label='Twice-Around-the-Tree')
plt.plot(vertexCounts2, residentSetSizes2, 'ro-', label='Christofides')
plt.xlabel('Vertex Count')
plt.ylabel('Memory Usage (MB)')
plt.title('Memory Usage by Vertex Count')
plt.legend()
plt.savefig(sys.argv[6] + 'Mem.png')
plt.close()


# x is log scale
plt.xscale('log')

# Create and save the graph of user time by vertex count for both folders
plt.plot(vertexCounts1, userTimes1, 'bo-', label='Twice-Around-the-Tree')
plt.plot(vertexCounts2, userTimes2, 'ro-', label='Christofides')
plt.xlabel('Vertex Count')
plt.ylabel('User Time (minutes)')
plt.title('User Time by Vertex Count')
plt.legend()
plt.savefig(sys.argv[6] + 'Time.png')
plt.close()

# limit from 1 to 1.1 * max(quality1) and 1.1 * max(quality2)
plt.ylim(1, 1.1 * max(max(quality1), max(quality2)))


plt.xscale('log')

# Create and save the graph of solution quality by vertex count for both folders
plt.plot(vertexCounts1, quality1, 'bo-', label='Twice-Around-the-Tree')
plt.plot(vertexCounts2, quality2, 'ro-', label='Christofides')
plt.xlabel('Vertex Count')
plt.ylabel('Solution Quality')
plt.title('Solution Quality by Vertex Count')
plt.legend()
plt.savefig(sys.argv[6] + 'Quality.png')
plt.close()

