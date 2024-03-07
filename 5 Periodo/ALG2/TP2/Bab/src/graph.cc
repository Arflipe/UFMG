#include "graph.hpp"
#include "possibleSolution.hpp"

#include <algorithm>
#include <queue>

Graph::Graph(int numCities) {
	this->numCities = numCities;

	this->foundSolution = false;

	this->cities = new Point[numCities];
	this->minDistances = new double[numCities];
	this->secondMinDistances = new double[numCities];

	this->distances = new double*[numCities];
	for (int i = 0; i < numCities; i++) {
		this->distances[i] = new double[numCities];
	}
}

void Graph::AddCity(int index, double x, double y) {
	this->cities[index].SetX(x);
	this->cities[index].SetY(y);

	for(int i = 1; i < index; i++) {
		double distance = this->cities[i].DistanceTo(this->cities[index]);
		this->distances[i][index] = distance;
		this->distances[index][i] = distance;
	}
}

int Graph::GetNumCities() {
	return this->numCities;
}

double Graph::GetDistance(int i, int j) {
	return this->distances[i][j];
}

void Graph::GetMinDistances() {
	for(int i = 0; i < this->numCities; i++) {
		double minDistance;
		double secMinDistance;

		if(this->distances[i][0] < this->distances[i][1]){
			minDistance = this->distances[i][0];
			secMinDistance = this->distances[i][1];
		}
		else{
			minDistance = this->distances[i][1];
			secMinDistance = this->distances[i][0];
		}

		for(int j = 2; j < this->numCities; j++) {
			if(this->distances[i][j] < minDistance){
				secMinDistance = minDistance;
				minDistance = this->distances[i][j];
			}
			else if(this->distances[i][j] < secMinDistance){
				secMinDistance = this->distances[i][j];
			}
		}

		this->minDistances[i] = minDistance;
		this->secondMinDistances[i] = secMinDistance;
	}
}


double Graph::GetSolution() {
	GetMinDistances();
	BFSBranchAndBound();
	return this->lowestFoundCost;
}

void Graph::BFSBranchAndBound() {
	priority_queue<PossibleSolution> queue;
	vector<int> chosenCities;
	double currentCost = 0;
	vector<PossibleSolution> solutions;
	PossibleSolution root = PossibleSolution(currentCost, chosenCities, 0);

	while(!foundSolution){
		if (!IsSolution(root.GetCurrentCost(), root.GetChosenCities())){
			solutions = GetPossibleSolutions(root);

			int lowestLowerBoundIndex = 0;
			for(int i = 0; i < (int) solutions.size(); i++) {
				if(solutions[i].GetLowerBound() < solutions[lowestLowerBoundIndex].GetLowerBound()){
					lowestLowerBoundIndex = i;
				}
			}
			root = solutions[lowestLowerBoundIndex];
			solutions.erase(solutions.begin() + lowestLowerBoundIndex);
			for(int i = 0; i < (int) solutions.size(); i++) {
				queue.push(solutions[i]);
			}
		}
	}
	
	while(!queue.empty()){
		solutions = GetPossibleSolutions(queue.top());
		queue.pop();
		for(int i = 0; i < (int) solutions.size(); i++) {
			if (!IsSolution(solutions[i].GetCurrentCost(), solutions[i].GetChosenCities())){
				queue.push(solutions[i]);
			}
		}
	}
}

vector<PossibleSolution> Graph::GetPossibleSolutions(PossibleSolution currentSolution) {
	vector<PossibleSolution> solutions;
	for(int i = 0; i < this->numCities; i++) {
		double lowerBound;
		if(ShouldPrune(i, currentSolution.GetChosenCities(), currentSolution.GetCurrentCost(), &lowerBound)) continue;

		double newCost = currentSolution.GetCurrentCost();
		if(currentSolution.GetChosenCities().size() != 0){
			int lastCity = currentSolution.GetChosenCities().back();
			newCost += this->distances[lastCity][i];
		}

		vector<int> chosenCities = currentSolution.GetChosenCities();
		chosenCities.push_back(i);

		PossibleSolution possibleSolution = PossibleSolution(newCost, chosenCities, lowerBound);
		solutions.push_back(possibleSolution);
	}
	return solutions;
}


bool Graph::IsSolution(double currentCost, vector<int> chosenCities) {
	if ((int) chosenCities.size() < this->numCities) return false;

	currentCost += this->distances[chosenCities.back()][0];
	if(foundSolution){
		if (currentCost < this->lowestFoundCost) {
			this->lowestFoundCost = currentCost;
			this->bestSolution = chosenCities;
		}
	}
	else{
		this->foundSolution = true;
		this->lowestFoundCost = currentCost;
		this->bestSolution = chosenCities;
	}
	return true;
}

double Graph::GetLowerBound(int newCityIndex, vector<int> chosenCities, double currentCost) {
	double lowerBound = 0;
	if (chosenCities.size() != 0){
		lowerBound += this->minDistances[chosenCities.back()];
	}
	else{
		lowerBound += this->minDistances[newCityIndex];
		lowerBound += this->secondMinDistances[newCityIndex];
	}

	for(int i = 0; i < this->numCities; i++) {
		if(i == newCityIndex || find(chosenCities.begin(), chosenCities.end(), i) != chosenCities.end()) continue;
		lowerBound += this->minDistances[i];
		lowerBound += this->secondMinDistances[i];
	}

	lowerBound /= 2;
	lowerBound += currentCost;

	if (chosenCities.size() != 0){
		lowerBound += this->distances[chosenCities.back()][newCityIndex];
	}

	return lowerBound;
}

bool Graph::ShouldPrune(int newCityIndex, vector<int> chosenCities, double currentCost, double* lowerBound) {
	if (find(chosenCities.begin(), chosenCities.end(), newCityIndex) != chosenCities.end()) return true;

	*lowerBound = GetLowerBound(newCityIndex, chosenCities, currentCost);
	if (foundSolution && *lowerBound > this->lowestFoundCost) return true;

	return false;
}