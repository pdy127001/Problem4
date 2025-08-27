#include "StockManager.h"
bool StockManager::dispensePotion(string potionName) {// ��� ����
	if(getStock(potionName)) {
		potionStock[potionName]--;
		cout << ">> '" << potionName << "' ������ �����մϴ�. (���� ���: " << getStock(potionName) << "��)" << endl;
		return true;
	}
	else {
		cout << ">> '" << potionName << "' ������ ��� �����ϴ�." << endl;
		return false;
	}
}

void StockManager::returnPotion(string potionName) {// ��� ��ȯ
	if (potionStock.find(potionName) != potionStock.end()) {
		if (potionStock[potionName] < MAX_STOCK) {
			potionStock[potionName]++;
			cout << ">> '" << potionName << "' ������ ��ȯ�޾ҽ��ϴ�. (���� ���: " << getStock(potionName) << "��)" << endl;
		}
		else {
			cout << ">> '" << potionName << "' ������ ��� �������� ������ȯ�� �Ұ��մϴ�. (���: " << getStock(potionName) << "��)" << endl;//�䱸���׿����� ��� 3���� ��ȯ������ ����
		}
	}
	else {
		cout << ">> '" << potionName << "' ������ �������� �ʴ� �����Դϴ�." << endl;
	}
}


int StockManager::getStock(string potionName) {// ��� Ȯ��
	if (potionStock.find(potionName) != potionStock.end()){
		return potionStock[potionName];
	}
	else {
		cout << ">> '" << potionName << "' ������ �������� �ʴ� �����Դϴ�." << endl;
		return -1;
	}
}
void StockManager::initializeStock(string potionName) {// ��� �ʱ�ȭ
	potionStock[potionName] = MAX_STOCK;

}