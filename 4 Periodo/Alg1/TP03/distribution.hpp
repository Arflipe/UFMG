#ifndef DISTRIBUTION_HPP
#define DISTRIBUTION_HPP

#define INF 0x3f3f3f3f

#include <vector>
#include <bits/stdc++.h>

using namespace std;

class DistributionCenter{
	private:
	vector<int> alloyLength;
	int* lAlloys;

	public:
	DistributionCenter();
	~DistributionCenter();
	void addType(int length);
	int distribute(int request);
	void findLeastAlloys(int request);
};

#endif