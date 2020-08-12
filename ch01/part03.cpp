#include <iostream>
#include <vector>
using namespace std;

// 낌새가 보인다면 const를 들이미는 습관 또한 좋은 습관입니다.
// const는 코드 상에서 의미적인 제약을 둘 수 있다는 장점이 있는 키워드입니다.
// 심지어 static하고도 쓸 수 있는 놈이기도 하다.

// 일반 변수
char greeting[] = "Hello";

// 비상수 포인터
// 비상수 데이터
char* p = greeting;

// 비상수 포인터
// 상수 데이터
const char* cp = greeting;

// 상수 포인터
// 비상수 데이터
char* const pc = greeting;

// 상수 포인터, 데이터
const char* const cpc = greeting;

struct Widget {};

// f1은 상수 widget 객체에 대한 포인터를 매개변수로 취한다.
void f1(const Widget* pw);
// 이 경우도 마찬가지다.
void f2(Widget const* pw);


std::vector<int> vec;
class Rational {
};

// 이건 안정성을 가져다 주는 효과를 줄 수도 있다.
const Rational operator*(const Rational& lhs, const Rational& rhs)
{

}

class CTextBlock
{
public : 
	const char& operator[] (std::size_t position) const { return text[position]; }	// 상수 객체에 대한 operator
	char& operator[] (std::size_t position) 
	{ // 비상수 객체에 대한 operator

		// op[]의 반환 타입에 캐스팅을 적용
		// const를 때어낸다. (const_cast밖에 없기 때문에 이를 쓴다.)
		// 단 const_cast는 재앙의 씨앗이 되기 때문에 이는 조심해서 써야한다.
		// *this의  타입에 const를 붙인다. op[]의 상수 버전을 호출한다.
		// 이는 안정성을 유지하면서 코드 중복을 피한다.
		return const_cast<char&>(static_cast<const CTextBlock&>(*this)[position]);
	}				

	// 부적절한 하지만 비트 수준 상수성에 있어서 허용되는 방식
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

// 이 const는 에러를 일으킨다. 
// 왜냐면 textLength 및 lengthIsValid가 대입되는 상황이 발생하기 때문이다.
// 즉 이 부분은 대놓고 비트수준 상수성을 벗어난다.
// 하지만 상수객체에 대해서는 문제가 없어야할 코드이기도 하다.
// 논리적 상수성만 맞춰주면 그만인 부분
// 즉 비정적 데이터 멤버의 비트수준 상수성을 풀어주는 키워드를 사용하자
// 이것이 바로 mutable이다.
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
	// STL iterator는 포인터를 본뜬 것이다.
	// 그렇기에 T*와 사용 방법은 굉장히 흡사하다.
	const std::vector<int>::iterator iter = vec.begin();	// T*와 흡사하다.
	*iter = 10;	// 이건 된다. 왜냐면 iter의 주소값이 변경되는 점은 아니다.
	// ++iter;		// 에러! iter의 주소값이 변경된다.

	std::vector<int>::const_iterator cIter = vec.begin();
	// cIter = 20;		// 데이터가 상수라 변경 불가!
	cIter++;			// 이건 가능하다. 포인터가 상수는 아니니까!

	// 위의 함수가 어떤 효과를 가져오는가.
	Rational a, b, c;
	// 우리가 만약 ==를 쓰려고 했다가 다음과 같은 실수가 나는 경우 이를 방지할 수 있는 것이
	// 바로 위의 함수이다.
	// if ((a * b) = c) {}

	// 이제 위에서 만든 CTextBlock 클래스를 사용해보자
	CTextBlock tb("Hello");
	std::cout << tb[0];

	const CTextBlock ctb("World");
	std::cout << tb[0];

	tb[0] = 'x';		// 가능하다. 비상수 객체라서!
	//ctb[0] = 'x';		// 불가능! 상수 객체는 읽기만 가능하다.!

	return 0;
}