#include "SearchRecipeByIngredient.h"
#include <iostream>
SearchRecipeByIngredient::SearchRecipeByIngredient(string name) {
	ingredientName = name;
};
vector<PotionRecipe> SearchRecipeByIngredient::search(const vector<PotionRecipe>& recipes) const{
    vector<PotionRecipe> recipe;
    if (recipes.empty()) {
        std::cout << "���� ��ϵ� �����ǰ� �����ϴ�." << std::endl;
        return recipe;
    }
    for (size_t i = 0; i < recipes.size(); ++i) {
        for (size_t j = 0; j < recipes[i].ingredients.size(); ++j) {
            if (ingredientName == recipes[i].ingredients[j]) {
                recipe.push_back(recipes[i]);
                j = recipes[i].ingredients.size();
            }
        }
    }
    return recipe;
}