#ifndef PS_HPP
#define PS_HPP

#include <vector>

using namespace std;

class PossibleSolution{
	private:
	vector<int> chosenCities;
	double currentCost;
	double lowerBound;

	public:
	PossibleSolution(double currentCost, vector<int> chosenCities, double lowerBound);
	vector<int> GetChosenCities();
	double GetCurrentCost();
	double GetLowerBound() const;

	bool operator<(const PossibleSolution& other) const {
		return lowerBound > other.lowerBound;
	}
};

#endif