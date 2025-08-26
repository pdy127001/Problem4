#include <iostream>
#include <vector>
#include <string>
#include"SearchRecipe.h"
#include"SearchRecipeByName.h"
#include"SearchRecipeByIngredient.h"
#include"PotionRecipe.h"
// AlchemyWorkshop Ŭ����: ������ ����� ����
class AlchemyWorkshop {
private:
    std::vector<PotionRecipe> recipes;

public:
    // addRecipe �޼���: ��� ���(vector)�� �Ű������� �޵��� ����
    void addRecipe(const std::string& name, const std::vector<std::string>& ingredients) {
        recipes.push_back(PotionRecipe(name, ingredients));
        std::cout << ">> ���ο� ������ '" << name << "'��(��) �߰��Ǿ����ϴ�." << std::endl;
    }

    // ��� ������ ��� �޼���
    void displayAllRecipes() const {
        if (recipes.empty()) {
            std::cout << "���� ��ϵ� �����ǰ� �����ϴ�." << std::endl;
            return;
        }

        std::cout << "\n--- [ ��ü ������ ��� ] ---" << std::endl;
        for (size_t i = 0; i < recipes.size(); ++i) {
            std::cout << "- ���� �̸�: " << recipes[i].potionName << std::endl;
            std::cout << "  > �ʿ� ���: ";

            // ��� ����� ��ȸ�ϸ� ���
            for (size_t j = 0; j < recipes[i].ingredients.size(); ++j) {
                std::cout << recipes[i].ingredients[j];
                // ������ ��ᰡ �ƴϸ� ��ǥ�� ����
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

int main() {
    AlchemyWorkshop myWorkshop;

    while (true) {
        std::cout << "?? ���ݼ� ���� ���� �ý���" << std::endl;
        std::cout << "1. ������ �߰�" << std::endl;
        std::cout << "2. ��� ������ ���" << std::endl;
        std::cout << "3. ����" << std::endl;
        std::cout << "����: ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "�߸��� �Է��Դϴ�. ���ڸ� �Է����ּ���." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) {
            std::string name;
            std::cout << "���� �̸�: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, name);

            // ���� ��Ḧ �Է¹ޱ� ���� ����
            std::vector<std::string> ingredients_input;
            std::string ingredient;
            std::cout << "�ʿ��� ������ �Է��ϼ���. (�Է� �Ϸ� �� '��' �Է�)" << std::endl;

            while (true) {
                std::cout << "��� �Է�: ";
                std::getline(std::cin, ingredient);

                // ����ڰ� '��'�� �Է��ϸ� ��� �Է� ����
                if (ingredient == "��") {
                    break;
                }
                ingredients_input.push_back(ingredient);
            }

            // �Է¹��� ��ᰡ �ϳ� �̻� ���� ���� ������ �߰�
            if (!ingredients_input.empty()) {
                myWorkshop.addRecipe(name, ingredients_input);
            }
            else {
                std::cout << ">> ��ᰡ �Էµ��� �ʾ� ������ �߰��� ����մϴ�." << std::endl;
            }

        }
        else if (choice == 2) {
            myWorkshop.displayAllRecipes();

        }
        else if (choice == 3) {
            std::cout << "���� ���� �ݽ��ϴ�..." << std::endl;
            break;

        }
        else {
            std::cout << "�߸��� �����Դϴ�. �ٽ� �õ��ϼ���." << std::endl;
        }
    }

    return 0;
}