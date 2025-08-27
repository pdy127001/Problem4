#pragma once
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;
class StockManager
{
public:
    void initializeStock(string potionName);
    bool dispensePotion(string potionName);
    void returnPotion(string potionName);
	int getStock(string potionName);
private:
    unordered_map<string, int> potionStock;
	static const int MAX_STOCK = 3;
};
