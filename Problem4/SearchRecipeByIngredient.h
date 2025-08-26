#pragma once
#include"SearchRecipe.h"
class SearchRecipeByIngredient:public SearchRecipe
{
public:
	SearchRecipeByIngredient(string name);
	vector<PotionRecipe> search(const vector<PotionRecipe>& recipes) const;
private:
	string ingredientName;
};

