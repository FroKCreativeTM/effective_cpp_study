// ��ü�� ��� �κ��� �������� ��������!

#include <iostream>
#include <string>

void logCall(const std::string& functionName);	// �α� ����� �����.

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
	// ���� ���� �������� ���
	Customer::operator=(rhs);
}

Customer::Customer(const Customer& rhs)
{
}

Customer& Customer::operator=(const Customer& rhs)
{
	// TODO: ���⿡ return ���� �����մϴ�.
}
