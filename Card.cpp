#include "Classes.h"

// дисконтная
bool discount_card::Use(double& amount) {
	// if (discount > 100) cout << "U were tricked(" << endl;
	if (amount <= 0 or discount == 0) {
		cout << "You can't use this discount card." << endl;
		return false;
	}
	else {
		amount *= (1 - discount / 100);
		cout << "Discount card was used successfully!" << endl;
		return true;
	}
}

// дебетовая
bool debet_card::Use(double& amount) {
	if (amount < 0 || sum <= 0) {
		cout << "You can't use this debet card." << endl;
		return false;
	}
	else {
		if (amount > sum) {
			amount -= sum;
			sum = 0;
		}
		else {
			sum -= amount;
			amount = 0;
		}
		cout << "Debet card was used successfully!" << endl;
		return true;
	}
}

// подарочная
bool gift_card::Use(double& amount) {
	if (amount < 0 || sum <= 0) {
		cout << "You can't use this gift card." << endl;
		return false;
	}
	else {
		if (amount > sum) {
			amount -= sum;
			sum = 0;
		}
		else {
			sum -= amount;
			amount = 0;
		}
		cout << "Gift card was used successfully!" << endl;
		return true;
	}
}

// накопительная скидочная
bool cumulative_card::Use(double& amount) {
	if (amount < 0) {
		cout << "You can't use this cumulative card." << endl;
		return false;
	}
	amount *= (1 - discount / 100);
	cout << "Cumulative card was used successfully! (for discount)" << endl;
	//вообще, бонусы можно добавлять и по другому правилу
	bonus += amount * discount / 1000;
	cout << "We added the bonuses. Now you have: ";
	cout << bonus << endl;
	if (bonus > 0) {
		if (amount > bonus) {
			amount -= bonus;
			bonus = 0;
		}
		else {
			bonus -= amount;
			amount = 0;
		}
		cout << "Cumulative card was used successfully! (for paying wiht bonuses)" << endl;
	}
	return true;
}