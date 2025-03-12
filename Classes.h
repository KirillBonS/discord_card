#pragma once
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;


class elect_card {
public:
	virtual bool Use(double& amount) { return false; }
	virtual double get_sum() { return 0; }
	//virtual ~elect_card() = 0;
};

class discount_card : public elect_card {
private:
	double discount; // скидка в %
public:
	discount_card(double discount) : discount(discount) {};
	discount_card() : discount(0) {};
	bool Use(double& amount) override;
};

class debet_card :public elect_card {
private:
	double sum; // в рублях
public:
	void append_sum(double sum) { this->sum += sum; }

	debet_card(double sum) :sum(sum) {};
	debet_card() : sum(0) {};
	double get_sum() { return sum; }
	bool Use(double& amount) override;

};

class gift_card : public elect_card {
private:
	double sum; // в рублях
public:
	gift_card(double sum) :sum(sum) {};
	double get_sum() { return sum; }
	bool Use(double& amount) override;
};

class cumulative_card : public elect_card {
private:
	double bonus; // бонусы == рублям
	double discount; // скидка в %
public:
	cumulative_card(double bonus, double discount) :
		bonus(bonus), discount(discount) {};
	double get_sum() { return bonus; }
	bool Use(double& amount) override;
};