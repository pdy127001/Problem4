#pragma once
#include <vector>
#include <string>
#include "PotionRecipe.h"

using namespace std;
class SearchRecipe
{
public:
	SearchRecipe() {};
	~SearchRecipe() {};
	virtual vector<PotionRecipe>search(const vector<PotionRecipe>& recipes) const=0;
};

