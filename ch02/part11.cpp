// operator=에서는 자기 대입에 대한 처리가 빠지지 않도록 한다!

class Bitmat
{

};

class Widget
{
public : 
	Widget& operator=(const Widget& rhs);
	void swap(Widget& rhs);

private : 
	Bitmat* pb;	// 힙에 할당한 객체를 가리키는 포인터
};

class Base {};
class Derived : public Base {};

// 안전하지 않은 operator=
/*
Widget& Widget::operator=(const Widget& rhs)
{
	// 일차성 검사
	if (this == &rhs) return *this;

	delete pb;					// 현재 비트맵 사용 중지
	pb = new Bitmat(*rhs.pb);	// 이제 rhs의 비트맵을 사용하게 한다.
	// 문제는 this와 rhs가 같은 객체라면? rhs의 pb는 없는 것이 되버린다!
	// 이를 위해서 this와 rhs를 비교할 필요가 있다.
	

	return *this;
}
*/

Widget& Widget::operator=(const Widget& rhs)
{
	Bitmat* pOrig = pb;			// 일단 주소값을 임시로 저장할 포인터를 만든다.
	pb = new Bitmat(*rhs.pb);	// pb에는 rhs의 pb를 가져와서 생성한다.
	delete pOrig;				// 임시로 저장된 주소값을 삭제한다.

	return *this;
}

Widget& Widget::operator=(const Widget& rhs)
{
	// 복사 후 맞바꾸기
	Widget temp(rhs);
	swap(temp);
	return *this;
}

void doSomething(const Base& rb, const Derived* pd);		// rb와 pd는 같은 객체였을 수도 있다.

int main()
{
	Widget w;
	w = w;		// 자기에 대한 대입

	int i = 0;
	int j = 0;

	Widget a[2];
	a[i] = a[j];	// 이것도 자기 대입이다... 이런 것을 중복 대입(aliasing)이라 한다.
}