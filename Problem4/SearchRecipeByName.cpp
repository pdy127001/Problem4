#include "SearchRecipeByName.h"
#include <iostream>
SearchRecipeByName::SearchRecipeByName(string name) {
	potionName = name;
};
vector<PotionRecipe> SearchRecipeByName::search(const vector<PotionRecipe>& recipes) const{
    vector<PotionRecipe> recipe;
    if (recipes.empty()) {
        std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
        return recipe;
    }
    for (size_t i = 0; i < recipes.size(); ++i) {
        if (potionName == recipes[i].potionName) {
            recipe.push_back(recipes[i]);
            return recipe;
        }
        
    }
};