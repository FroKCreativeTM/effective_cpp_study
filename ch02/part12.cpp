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