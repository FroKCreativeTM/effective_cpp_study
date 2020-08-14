// 객체의 모든 부분을 빠짐없이 복사하자!

#include <iostream>
#include <string>

void logCall(const std::string& functionName);	// 로그 기록을 만든다.

class Customer
{
public : 
	Customer(const Customer& rhs);
	Customer& operator=(const Customer& rhs);

private : 
	std::string name;
};

class PriorityCustomer : public Customer
{
public:
	PriorityCustomer(const Customer& rhs);
	PriorityCustomer& operator=(const Customer& rhs);

};

PriorityCustomer::PriorityCustomer(const Customer& rhs) : 
	Customer(rhs)
{
	// 
}

PriorityCustomer& PriorityCustomer::operator=(const Customer& rhs)
{
	// 복사 대입 연산자의 경우
	Customer::operator=(rhs);
}

Customer::Customer(const Customer& rhs)
{
}

Customer& Customer::operator=(const Customer& rhs)
{
	// TODO: 여기에 return 문을 삽입합니다.
}
