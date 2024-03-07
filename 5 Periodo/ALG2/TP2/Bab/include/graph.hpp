#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "point.hpp"
#include "possibleSolution.hpp"
#include <vector>

using namespace std;

class Graph {
	private:
	int numCities;

	bool foundSolution;
	
	double lowestFoundCost;
	vector<int> bestSolution;

	Point* cities;
	double** distances;
	double* minDistances;
	double* secondMinDistances;

	public:
	Graph(int numCities);
	void AddCity(int index, double x, double y);
	int GetNumCities();
	double GetDistance(int i, int j);
	double GetSolution();

	bool IsSolution(double currentCost, vector<int> chosenCities);
	bool ShouldPrune(int newCityIndex, vector<int> chosenCities, double currentCost, double* lowerBound);
	double GetLowerBound(int newCityIndex, vector<int> chosenCities, double currentCost);
	vector<PossibleSolution> GetPossibleSolutions(PossibleSolution currentSolution);

	void GetMinDistances();
	void BFSBranchAndBound();
};

#endif