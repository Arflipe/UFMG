import sys
import os
import pandas as pd
import matplotlib.pyplot as plt

folderName = sys.argv[1]

solutionQualityFile = sys.argv[2]

# Get all filenames in the folder
filenames = os.listdir(folderName)

# Sort the filenames by number, this is the vertex count
filenames.sort(key=lambda x: int(''.join(filter(str.isdigit, x))))


# Process each file
residentSetSizes = []
userTimes = []
vertexCounts = []
names = []
quality = []

for filename in filenames:
	filePath = os.path.join(folderName, filename)
	with open(filePath, 'r') as file:
		lines = file.readlines()
		userTime = None
		residentSetSize = None
		vertexCount = int(''.join(filter(str.isdigit, filename)))
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

		residentSetSizes.append(residentSetSize)
		userTimes.append(userTime)
		vertexCounts.append(vertexCount)
		names.append(filename)

# Get the solution quality data
with open(solutionQualityFile, 'r') as file:
	lines = file.readlines()
	for name in names:
		# find the line with the dataset name, if not found, set quality to None
		for line in lines:
			if line.startswith(name):
				words = line.split()
				optimalSolution = words[-1]
				break
		else:
			optimalSolution = "None"
		quality.append(optimalSolution)
		

# Create a DataFrame for the data
data = pd.DataFrame({'Dataset': names, 'Vertex Count': vertexCounts, 'Memory Usage (MB)': residentSetSizes, 'User Time (Min)': userTimes, 'Quality': quality})


# Save the data as a table
data.to_csv(sys.argv[3] + 'Table.csv', index=False)

# x is log scale
plt.xscale('log')

# Create and save the graph of memory usage by vertex count
plt.plot(vertexCounts, residentSetSizes, 'bo-', label='Memory Usage')
plt.xlabel('Vertex Count')
plt.ylabel('Memory Usage (MB)')
plt.title('Memory Usage by Vertex Count')
plt.legend()
plt.savefig(sys.argv[3] + 'Mem.png')
plt.close()

# x is log scale
plt.xscale('log')

# y axis goes from 0 to 1.1 * max(userTimes)
plt.ylim(0, 1.1 * max(userTimes))

# Create and save the graph of user time by vertex count
plt.plot(vertexCounts, userTimes, 'bo-', label='User Time')
plt.xlabel('Vertex Count')
plt.ylabel('User Time (minutes)')
plt.title('User Time by Vertex Count')
plt.legend()
plt.savefig(sys.argv[3] + 'Time.png')
plt.close()



