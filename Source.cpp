/*
Сгенерировать некоторое количество карт
(динамический массив производных классов),

после чего для разных сумм выполнить
моделирование «оплаты» – из массива случайным образом
выбирается карта (рассеянный покупатель случайно
вытаскивает из кошелька первую попавшуюся карту),

и карта применяется, этот процесс повторяется до тех
пор, пока не будет произведена оплата

(пока не попадётся карта с балансом большим, чем сумма к оплате).
Весь процесс сопровождать выводом соответствующих сообщений.

//// while внутри while будет
Случайно генерировать покупки с некоторыми суммами до тех пор,
пока не попадётся покупка, оплата которой невозможна.
Вывести информацию об общей сумме покупок,
потраченных средствах и остатках на картах.

(не забыть учесть, что должен происходить выход из цикла, если
даже с применением всех карт оплатить не получается!)
*/

#include "Classes.h"
void task1(double amount) {
	srand(time(nullptr));
	const int n = 13;
	elect_card* wallet[n];
	wallet[0] = new discount_card(15);
	wallet[1] = new discount_card(9.5);
	wallet[2] = new discount_card(18.5);
	wallet[3] = new discount_card(10);

	wallet[4] = new debet_card(4700);
	wallet[5] = new debet_card(2600);
	wallet[6] = new debet_card(3606);
	wallet[7] = new debet_card(2800);

	wallet[8] = new gift_card(1500);
	wallet[9] = new gift_card(3000);
	wallet[10] = new gift_card(1000);

	wallet[11] = new cumulative_card(253, 5);
	wallet[12] = new cumulative_card(149, 7.5);

	double amount1 = amount;
	// Часть 1:
	vector<elect_card*> used_cards;
	cout << "Start amount: " << amount1 << endl;
	while (amount1 && used_cards.size() < n) { 
		double temp_amount = amount1;
		// a+rand()%(b-a) для диап. [a,b), a=0, b=13
		int index = rand() % n;
		elect_card* temp = wallet[index]; // взяли случ. карту

		
		if (find(used_cards.begin(), used_cards.end(), temp) == used_cards.end()) {
			temp->Use(amount1);
			used_cards.push_back(temp); 
			cout << "result: " << temp_amount << " -> " << amount1 << endl;
			cout << endl;
		}
		//else cout << "You already used this card." << endl;

	}
	// 13 т.к. проверяем все карты
	if (used_cards.size() >= n && amount1 > 0) cout << "You failed to pay the check..." << endl;
	cout << endl;

	cout << "Your balance:" << endl;
	for (int i = 4; i < n; ++i)
		cout << wallet[i]->get_sum() << endl;

	for (int i = 0; i < n; ++i)
		delete wallet[i];
}

void task2() {
	srand(time(nullptr));
	const int n = 13;
	elect_card* wallet[n];
	wallet[0] = new discount_card(15);
	wallet[1] = new discount_card(9.5);
	wallet[2] = new discount_card(18.5);
	wallet[3] = new discount_card(10);

	wallet[4] = new debet_card(4700);
	wallet[5] = new debet_card(2600);
	wallet[6] = new debet_card(3606);
	wallet[7] = new debet_card(2800);

	wallet[8] = new gift_card(1500);
	wallet[9] = new gift_card(3000);
	wallet[10] = new gift_card(1000);

	wallet[11] = new cumulative_card(253, 5);
	wallet[12] = new cumulative_card(149, 7.5);

	double spent = 0; // потраченные средства

	double res = 0;
	int cnt = 0;
	while (!res) {
		// a+rand()%(b-a) для диап. [a,b), a=0, b=25000
		double amount = rand() % 4000;
		vector<elect_card*> used_cards;
		while (amount && used_cards.size() < n) {
			double temp_amount = amount;
			// a+rand(%(b-a) для диап. [a,b), a=0, b=13
			int index = rand() % n;
			elect_card* temp = wallet[index]; 
			double sum_before = temp->get_sum();

			
			if (find(used_cards.begin(), used_cards.end(), temp) == used_cards.end()) {
				temp->Use(amount);
				used_cards.push_back(temp); 
				cout << "result: " << temp_amount << " -> " << amount << endl;
				cout << endl;
			}
			res = amount;
			spent += sum_before - temp->get_sum(); // sum_before - sum_after
		}
		cout << "End of purchase" << endl;
		cnt++;
	}
	cout << endl; cout << "Number of purchases: " << cnt << " " << endl;
	cout << endl; cout << "You spent: " << spent << endl;
	cout << endl; cout << "Your balance:" << endl;
	for (int i = 4; i < n; ++i)
		cout << wallet[i]->get_sum() << endl;

	for (int i = 0; i < n; ++i)
		delete wallet[i];
}

int main() {
	//task1(32000);
	task2();
	return 0;
}