#include "StockManager.h"
bool StockManager::dispensePotion(string potionName) {// 재고 지급
	if(getStock(potionName)) {
		potionStock[potionName]--;
		cout << ">> '" << potionName << "' 물약을 지급합니다. (남은 재고: " << getStock(potionName) << "개)" << endl;
		return true;
	}
	else {
		cout << ">> '" << potionName << "' 물약의 재고가 없습니다." << endl;
		return false;
	}
}

void StockManager::returnPotion(string potionName) {// 재고 반환
	if (potionStock.find(potionName) != potionStock.end()) {
		if (potionStock[potionName] < MAX_STOCK) {
			potionStock[potionName]++;
			cout << ">> '" << potionName << "' 물약을 반환받았습니다. (현재 재고: " << getStock(potionName) << "개)" << endl;
		}
		else {
			cout << ">> '" << potionName << "' 물약의 재고가 가득차서 공병반환이 불가합니다. (재고: " << getStock(potionName) << "개)" << endl;//요구사항에의해 재고 3개면 반환받을수 없음
		}
	}
	else {
		cout << ">> '" << potionName << "' 물약은 존재하지 않는 물약입니다." << endl;
	}
}


int StockManager::getStock(string potionName) {// 재고 확인
	if (potionStock.find(potionName) != potionStock.end()){
		return potionStock[potionName];
	}
	else {
		cout << ">> '" << potionName << "' 물약은 존재하지 않는 물약입니다." << endl;
		return -1;
	}
}
void StockManager::initializeStock(string potionName) {// 재고 초기화
	potionStock[potionName] = MAX_STOCK;

}