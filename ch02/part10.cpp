// ���� �����ڴ� *this�� ��ȯ�ϰ� ����

#include <iostream>
#include <string>

class Widget
{
public : 
	// ��ȯ Ÿ���� ���� Ŭ������ ���� �������Դϴ�.
	Widget& operator=(const Widget& fhs)
	{
		return *this;	// �º� ��ü(�� ������)�� ��ȯ�մϴ�.
	}

	// �� �º� ��ü�� �����ڸ� ��ȯ�ϰ� ������ �� �κ���
	// ��� ������ ���� �����ڰ� ��Ű�� ����� ���� ����. (*=, -=, += ���)
	Widget& operator+=(const Widget& rhs)
	{
		return *this;
	}

	// ���� �������� �Ű����� Ÿ���� �Ϲ������� ���� ��쿡�� ������ �Ծ�!
	Widget& operator=(int rhs)
	{
		return *this;
	}
};

int main()
{

	return 0;
}