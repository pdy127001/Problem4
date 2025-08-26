#pragma once
#include"SearchRecipe.h"
class SearchRecipeByName :public SearchRecipe
{
public:
	SearchRecipeByName(string name);
	vector<PotionRecipe> search(const vector<PotionRecipe>& recipes) const;
private:
	string potionName;
};

