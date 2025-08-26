#pragma once
#include"SearchRecipe.h"
using namespace std;
class SearchRecipeByIngredient:public SearchRecipe
{
public:
	SearchRecipeByIngredient(string name);
	vector<PotionRecipe> search(const vector<PotionRecipe>& recipes);
private:
	string ingredientName;
};

