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