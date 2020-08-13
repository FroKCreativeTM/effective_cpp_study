// C++ 은근슬쩍 만들어 호출해 버리는 함수들에 촉각을 세우자.
// 복사 생성자
// 또는 복사 대입 연산자
// 소멸자
// 이 3개는 코드 상 없다면 컴파일러가 만드는 함수들이다.
// 즉 쓰지 않는다면 막아둘 필요가 있다.

class EmptyClass
{
public : 
	EmptyClass() {}
	EmptyClass(const EmptyClass& rhs) {}
	EmptyClass& operator=(const EmptyClass& rhs) {}
	~EmptyClass() {}
};