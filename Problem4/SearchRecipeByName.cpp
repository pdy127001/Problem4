#include "SearchRecipeByName.h"
#include <iostream>
SearchRecipeByName::SearchRecipeByName(string name) {
	potionName = name;
};
vector<PotionRecipe> SearchRecipeByName::search(const vector<PotionRecipe>& recipes) const{
    vector<PotionRecipe> recipe;
    if (recipes.empty()) {
        std::cout << "���� ��ϵ� �����ǰ� �����ϴ�." << std::endl;
        return recipe;
    }
    for (size_t i = 0; i < recipes.size(); ++i) {
        if (potionName == recipes[i].potionName) {
            recipe.push_back(recipes[i]);
            return recipe;
        }
        
    }
};