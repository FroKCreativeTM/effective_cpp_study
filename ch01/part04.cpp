#include <iostream>
#include <string>
#include <list>
using namespace std;

// ��ü�� ���� ���� �ݵ�� �ʱ�ȭ �ؾ� �Ѵ�!

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
		// �̰� �ʱ�ȭ�� �ƴ϶� �����̴�.
		m_name = _name;
		m_address = _address;
		m_phones = _listPhone;
		m_numTimeConsulted = time;
	}
	*/

	// �̴ϼȶ������� �̿��ؼ� �ʱ�ȭ�� �����Ѵ�.
	// �� ��찡 Ȯ���� ���԰� �ӵ��� �����ϸ�
	// �̴� ���� �����ڰ� ���� ���� �����ں��� ������ �����ϴ� ��Ʈ�⵵ �ϴ�.
	// ����̰ų� �����ڷ� �Ǿ��ִ� ��� �ݵ�� ����Ǿ�� �ϱ⿡ �ʱ�ȭ ����Ʈ�� ���⵵ �Ѵ�.
	// �� �ʱ�ȭ ����Ʈ�� �׻� ����ϴ� ���� ���� ���̴�.
	ABEntry(std::string _name, std::string _address, std::list<PhoneNum> _listPhone,
		int time)  
		: m_name(_name), m_address(_address), m_phones(_listPhone), m_numTimeConsulted(time)
	{
	}

	// �� ��쿡�� ������ ���� �ʱ�ȭ�� ���� �ִ�.
	ABEntry() :
		m_name(),		// ctor�� �̿��ؼ� �ʱ�ȭ�Ѵ�.
		m_address(),	// ctor�� �̿��ؼ� �ʱ�ȭ�Ѵ�.
		m_phones(),		// ctor�� �̿��ؼ� �ʱ�ȭ�Ѵ�. 
		m_numTimeConsulted(0) // int�� ��������� 0
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