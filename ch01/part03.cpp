#include <iostream>
#include <vector>
using namespace std;

// ������ ���δٸ� const�� ���̴̹� ���� ���� ���� �����Դϴ�.
// const�� �ڵ� �󿡼� �ǹ����� ������ �� �� �ִٴ� ������ �ִ� Ű�����Դϴ�.
// ������ static�ϰ� �� �� �ִ� ���̱⵵ �ϴ�.

// �Ϲ� ����
char greeting[] = "Hello";

// ���� ������
// ���� ������
char* p = greeting;

// ���� ������
// ��� ������
const char* cp = greeting;

// ��� ������
// ���� ������
char* const pc = greeting;

// ��� ������, ������
const char* const cpc = greeting;

struct Widget {};

// f1�� ��� widget ��ü�� ���� �����͸� �Ű������� ���Ѵ�.
void f1(const Widget* pw);
// �� ��쵵 ����������.
void f2(Widget const* pw);


std::vector<int> vec;
class Rational {
};

// �̰� �������� ������ �ִ� ȿ���� �� ���� �ִ�.
const Rational operator*(const Rational& lhs, const Rational& rhs)
{

}

class CTextBlock
{
public : 
	const char& operator[] (std::size_t position) const { return text[position]; }	// ��� ��ü�� ���� operator
	char& operator[] (std::size_t position) 
	{ // ���� ��ü�� ���� operator

		// op[]�� ��ȯ Ÿ�Կ� ĳ������ ����
		// const�� �����. (const_cast�ۿ� ���� ������ �̸� ����.)
		// �� const_cast�� ����� ������ �Ǳ� ������ �̴� �����ؼ� ����Ѵ�.
		// *this��  Ÿ�Կ� const�� ���δ�. op[]�� ��� ������ ȣ���Ѵ�.
		// �̴� �������� �����ϸ鼭 �ڵ� �ߺ��� ���Ѵ�.
		return const_cast<char&>(static_cast<const CTextBlock&>(*this)[position]);
	}				

	// �������� ������ ��Ʈ ���� ������� �־ ���Ǵ� ���
	// char& operator[] (std::size_t position) const { return text[position]; }		

	CTextBlock(char* _text)
	{
		text = _text;
	}

	std::size_t length() const;

private : 
	char* text;
	mutable std::size_t textLength;
	mutable bool lengthIsValid;
};

// �� const�� ������ ����Ų��. 
// �ֳĸ� textLength �� lengthIsValid�� ���ԵǴ� ��Ȳ�� �߻��ϱ� �����̴�.
// �� �� �κ��� ����� ��Ʈ���� ������� �����.
// ������ �����ü�� ���ؼ��� ������ ������� �ڵ��̱⵵ �ϴ�.
// ���� ������� �����ָ� �׸��� �κ�
// �� ������ ������ ����� ��Ʈ���� ������� Ǯ���ִ� Ű���带 �������
// �̰��� �ٷ� mutable�̴�.
std::size_t CTextBlock::length() const
{
	if (!lengthIsValid)
	{
		textLength = std::strlen(text);		
		lengthIsValid = true;
	}
	return textLength;
}

void print(const CTextBlock& ct)
{
	std::cout << ct[0];
}

int main()
{
	// STL iterator�� �����͸� ���� ���̴�.
	// �׷��⿡ T*�� ��� ����� ������ ����ϴ�.
	const std::vector<int>::iterator iter = vec.begin();	// T*�� ����ϴ�.
	*iter = 10;	// �̰� �ȴ�. �ֳĸ� iter�� �ּҰ��� ����Ǵ� ���� �ƴϴ�.
	// ++iter;		// ����! iter�� �ּҰ��� ����ȴ�.

	std::vector<int>::const_iterator cIter = vec.begin();
	// cIter = 20;		// �����Ͱ� ����� ���� �Ұ�!
	cIter++;			// �̰� �����ϴ�. �����Ͱ� ����� �ƴϴϱ�!

	// ���� �Լ��� � ȿ���� �������°�.
	Rational a, b, c;
	// �츮�� ���� ==�� ������ �ߴٰ� ������ ���� �Ǽ��� ���� ��� �̸� ������ �� �ִ� ����
	// �ٷ� ���� �Լ��̴�.
	// if ((a * b) = c) {}

	// ���� ������ ���� CTextBlock Ŭ������ ����غ���
	CTextBlock tb("Hello");
	std::cout << tb[0];

	const CTextBlock ctb("World");
	std::cout << tb[0];

	tb[0] = 'x';		// �����ϴ�. ���� ��ü��!
	//ctb[0] = 'x';		// �Ұ���! ��� ��ü�� �б⸸ �����ϴ�.!

	return 0;
}