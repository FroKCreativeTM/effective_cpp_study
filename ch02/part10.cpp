// 대입 연산자는 *this를 반환하게 하자

#include <iostream>
#include <string>

class Widget
{
public : 
	// 반환 타입은 현재 클래스에 대한 참조자입니다.
	Widget& operator=(const Widget& fhs)
	{
		return *this;	// 좌변 객체(의 참조자)를 반환합니다.
	}

	// 이 좌변 객체의 참조자를 반환하게 만들어라 이 부분으
	// 모든 형태의 대입 연산자가 지키게 만드는 것이 좋다. (*=, -=, += 등등)
	Widget& operator+=(const Widget& rhs)
	{
		return *this;
	}

	// 대입 연산자의 매개변수 타입이 일반적이지 않은 경우에도 동일한 규약!
	Widget& operator=(int rhs)
	{
		return *this;
	}
};

int main()
{

	return 0;
}