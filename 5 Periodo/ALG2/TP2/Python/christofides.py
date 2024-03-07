import sys
import networkx as nx

def readDataset(filename):
	file = open(filename, 'r')
	lines = file.readlines()
	file.close()

	G = nx.Graph()

	# set variable startLine to the line after "NODE_COORD_SECTION"
	startLine = lines.index("NODE_COORD_SECTION\n") + 1
	# set variable endLine to the line before "EOF" or the last line if "EOF" is not present
	if "EOF\n" in lines:
		endLine = lines.index("EOF\n") - 1
	else:
		endLine = len(lines) - 1
	# iterate over lines from startLine to endLine
	for line in lines[startLine:endLine]:
		# split line into words
		words = line.split()
		# add node to graph
		G.add_node(int(words[0]), x=float(words[1]), y=float(words[2]))

	for i in G.nodes():
		for j in G.nodes():
			node1 = G.nodes[i]
			node2 = G.nodes[j]
			# calculate distance between nodes
			distance = ((node1['x'] - node2['x'])**2 + (node1['y'] - node2['y'])**2)**0.5
			# add edge to graph
			G.add_edge(i, j, weight=distance)

	return G


def Christofides(G):
	# get minimum spanning tree of graph
	T = nx.minimum_spanning_tree(G)

	# get odd degree nodes of minimum spanning tree
	oddDegreeNodes = [node for node, degree in T.degree() if degree % 2 == 1]

	subgraph = G.subgraph(oddDegreeNodes)

	# get minimum weight matching of odd degree nodes
	matching = nx.min_weight_matching(subgraph)

	# create multigraph from minimum spanning tree and minimum weight matching
	multigraph = nx.MultiGraph(T)
	multigraph.add_edges_from([(u, v, {'weight': G[u][v]['weight']}) for u, v in matching])

	path = [u for u, _ in nx.eulerian_circuit(multigraph)]

	# create list of nodes in hamiltonian circuit
	hamiltonianPath = [path[0]]
	for node in path:
		if node not in hamiltonianPath:
			hamiltonianPath.append(node)

	# calculate cost of hamiltonian circuit
	cost = 0
	for i in range(len(hamiltonianPath) - 1):
		cost += G[hamiltonianPath[i]][hamiltonianPath[i + 1]]['weight']
	cost += G[hamiltonianPath[-1]][hamiltonianPath[0]]['weight']

	return (cost, hamiltonianPath)
	

# get filename from command line argument
filename = sys.argv[1]

# read dataset from file passed as argument
G = readDataset(filename)

(cost, path) = Christofides(G)

# print nodes in hamiltonian circuit
print("Solution:", path)
# print cost of hamiltonian circuit
print("Cost:", cost)
