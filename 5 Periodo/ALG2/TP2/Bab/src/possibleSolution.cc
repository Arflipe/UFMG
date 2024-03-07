#include "possibleSolution.hpp"

PossibleSolution::PossibleSolution(double currentCost, vector<int> chosenCities, double lowerBound) {
	this->currentCost = currentCost;
	this->chosenCities = chosenCities;
	this->lowerBound = lowerBound;
}

vector<int> PossibleSolution::GetChosenCities() {
	return this->chosenCities;
}

double PossibleSolution::GetCurrentCost() {
	return this->currentCost;
}

double PossibleSolution::GetLowerBound() const {
	return this->lowerBound;
}