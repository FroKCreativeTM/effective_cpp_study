// operator=������ �ڱ� ���Կ� ���� ó���� ������ �ʵ��� �Ѵ�!

class Bitmat
{

};

class Widget
{
public : 
	Widget& operator=(const Widget& rhs);
	void swap(Widget& rhs);

private : 
	Bitmat* pb;	// ���� �Ҵ��� ��ü�� ����Ű�� ������
};

class Base {};
class Derived : public Base {};

// �������� ���� operator=
/*
Widget& Widget::operator=(const Widget& rhs)
{
	// ������ �˻�
	if (this == &rhs) return *this;

	delete pb;					// ���� ��Ʈ�� ��� ����
	pb = new Bitmat(*rhs.pb);	// ���� rhs�� ��Ʈ���� ����ϰ� �Ѵ�.
	// ������ this�� rhs�� ���� ��ü���? rhs�� pb�� ���� ���� �ǹ�����!
	// �̸� ���ؼ� this�� rhs�� ���� �ʿ䰡 �ִ�.
	

	return *this;
}
*/

Widget& Widget::operator=(const Widget& rhs)
{
	Bitmat* pOrig = pb;			// �ϴ� �ּҰ��� �ӽ÷� ������ �����͸� �����.
	pb = new Bitmat(*rhs.pb);	// pb���� rhs�� pb�� �����ͼ� �����Ѵ�.
	delete pOrig;				// �ӽ÷� ����� �ּҰ��� �����Ѵ�.

	return *this;
}

Widget& Widget::operator=(const Widget& rhs)
{
	// ���� �� �¹ٲٱ�
	Widget temp(rhs);
	swap(temp);
	return *this;
}

void doSomething(const Base& rb, const Derived* pd);		// rb�� pd�� ���� ��ü���� ���� �ִ�.

int main()
{
	Widget w;
	w = w;		// �ڱ⿡ ���� ����

	int i = 0;
	int j = 0;

	Widget a[2];
	a[i] = a[j];	// �̰͵� �ڱ� �����̴�... �̷� ���� �ߺ� ����(aliasing)�̶� �Ѵ�.
}