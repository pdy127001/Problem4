#include <iostream>
#include <vector>
#include <string>
#include"SearchRecipe.h"
#include"SearchRecipeByName.h"
#include"SearchRecipeByIngredient.h"
#include"PotionRecipe.h"
#include"StockManager.h"
// AlchemyWorkshop 클래스: 레시피 목록을 관리
class AlchemyWorkshop {
private:
    std::vector<PotionRecipe> recipes;

public:
    // addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
    void addRecipe(const std::string& name, const std::vector<std::string>& ingredients) {
        recipes.push_back(PotionRecipe(name, ingredients));
        std::cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << std::endl;
    }
    // 모든 레시피 출력 메서드
    void displayAllRecipes() const {
        if (recipes.empty()) {
            std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
            return;
        }

        std::cout << "\n--- [ 전체 레시피 목록 ] ---" << std::endl;
        for (size_t i = 0; i < recipes.size(); ++i) {
            std::cout << "- 물약 이름: " << recipes[i].potionName << std::endl;
            std::cout << "  > 필요 재료: ";

            // 재료 목록을 순회하며 출력
            for (size_t j = 0; j < recipes[i].ingredients.size(); ++j) {
                std::cout << recipes[i].ingredients[j];
                // 마지막 재료가 아니면 쉼표로 구분
                if (j < recipes[i].ingredients.size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << "---------------------------\n";
    }
    std::vector<PotionRecipe> searchRecipe(const SearchRecipe& search) {
        return search.search(recipes);
    }
};
void printRecipes(const vector<PotionRecipe>& foundRecipes) {
    std::cout << "검색 결과:" << std::endl;
    for (const auto& recipe : foundRecipes) {
        std::cout << "- 물약 이름: " << recipe.potionName << std::endl;
        std::cout << "  > 필요 재료: ";
        for (size_t j = 0; j < recipe.ingredients.size(); ++j) {
            std::cout << recipe.ingredients[j];
            if (j < recipe.ingredients.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
}
int main() {
    AlchemyWorkshop myWorkshop;
    StockManager stockManager;
    while (true) {
        std::cout << "?? 연금술 공방 관리 시스템" << std::endl;
        std::cout << "1. 레시피 추가" << std::endl;
        std::cout << "2. 모든 레시피 출력" << std::endl;
        std::cout << "3. 물약 이름으로 검색 및 지급" << std::endl;
        std::cout << "4. 물약 재료로 검색" << std::endl;
        std::cout << "5. 공병 반환" << std::endl;
        std::cout << "6. 물약 재고 조회" << std::endl;
        std::cout << "7. 종료" << std::endl;
        std::cout << "선택: ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "잘못된 입력입니다. 숫자를 입력해주세요." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) {
            std::string name;
            std::cout << "물약 이름: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, name);

            // 여러 재료를 입력받기 위한 로직
            std::vector<std::string> ingredients_input;
            std::string ingredient;
            std::cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)" << std::endl;

            while (true) {
                std::cout << "재료 입력: ";
                std::getline(std::cin, ingredient);

                // 사용자가 '끝'을 입력하면 재료 입력 종료
                if (ingredient == "끝") {
                    break;
                }
                ingredients_input.push_back(ingredient);
            }

            // 입력받은 재료가 하나 이상 있을 때만 레시피 추가
            if (!ingredients_input.empty()) {
                myWorkshop.addRecipe(name, ingredients_input);
                stockManager.initializeStock(name);
            }
            else {
                std::cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << std::endl;
            }

        }
        else if (choice == 2) {
            myWorkshop.displayAllRecipes();

        }
        else if (choice == 3) {
            std::string potionName;
            std::cout << "물약 이름을 입력>>";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, potionName);
            SearchRecipeByName searchByName(potionName);
            if (myWorkshop.searchRecipe(searchByName).empty()) {
                cout << "검색 결과 없음" << endl;
            }
            else {
                printRecipes(myWorkshop.searchRecipe(searchByName));
				stockManager.dispensePotion(potionName);
            }
        }
        else if (choice == 4) {
            std::string ingredientName;
            std::cout << "물약 재료를 입력>>";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, ingredientName);
            SearchRecipeByIngredient searchByIngredient(ingredientName);
            if (myWorkshop.searchRecipe(searchByIngredient).empty()){
				cout << "검색 결과 없음" << endl;
            }
            else {
                printRecipes(myWorkshop.searchRecipe(searchByIngredient));
            }
        }
        else if (choice == 5) {
            std::string potionName;
            std::cout << "반환할 물약 이름 입력>>";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, potionName);
			stockManager.returnPotion(potionName);
        }
        else if (choice == 6) {
            std::string potionName;
            std::cout << "조회할 물약 이름 입력>>";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, potionName);
            if (-1 != stockManager.getStock(potionName)) {
				cout << ">> '" << potionName << "' 물약의 현재 재고: " << stockManager.getStock(potionName) << "개" << endl;
            }
        }
        else if (choice == 7) {
            std::cout << "공방 문을 닫습니다..." << std::endl;
            break;

        }
        else {
            std::cout << "잘못된 선택입니다. 다시 시도하세요." << std::endl;
        }
    }

    return 0;
}