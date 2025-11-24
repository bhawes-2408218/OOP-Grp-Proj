#pragma once
#include <iostream>

using namespace std;

class PaymentProcessor {
public:
	virtual bool processPayment(float amount) = 0;
	virtual void generateReceipt(float amount) = 0;

	virtual ~PaymentProcessor() {};
};
