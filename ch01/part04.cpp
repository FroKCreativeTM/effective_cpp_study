#include <iostream>
#include <string>
#include <list>
using namespace std;

// 객체는 쓰기 전에 반드시 초기화 해야 한다!

class PhoneNum
{

};

class ABEntry
{
public : 
	/*
	ABEntry(std::string _name, std::string _address, std::list<PhoneNum> _listPhone,
		int time)
	{
		// 이건 초기화가 아니라 대입이다.
		m_name = _name;
		m_address = _address;
		m_phones = _listPhone;
		m_numTimeConsulted = time;
	}
	*/

	// 이니셜라이저를 이용해서 초기화를 진행한다.
	// 이 경우가 확실한 대입과 속도를 보장하며
	// 이는 복사 생성자가 복사 대입 연산자보다 빠름을 보장하는 힌트기도 하다.
	// 상수이거나 참조자로 되어있는 경우 반드시 보장되어야 하기에 초기화 리스트를 쓰기도 한다.
	// 즉 초기화 리스트는 항상 사용하는 것이 편할 것이다.
	ABEntry(std::string _name, std::string _address, std::list<PhoneNum> _listPhone,
		int time)  
		: m_name(_name), m_address(_address), m_phones(_listPhone), m_numTimeConsulted(time)
	{
	}

	// 빈 경우에는 다음과 같이 초기화할 수도 있다.
	ABEntry() :
		m_name(),		// ctor을 이용해서 초기화한다.
		m_address(),	// ctor을 이용해서 초기화한다.
		m_phones(),		// ctor을 이용해서 초기화한다. 
		m_numTimeConsulted(0) // int라 명시적으로 0
	{}

private : 
	std::string m_name;
	std::string m_address;
	std::list<PhoneNum> m_phones;
	int m_numTimeConsulted;
};

int main()
{


	return 0;
}