// C++ 은근슬쩍 만들어 호출해 버리는 함수들에 촉각을 세우자.
// 복사 생성자
// 또는 복사 대입 연산자
// 소멸자
// 이 3개는 코드 상 없다면 컴파일러가 만드는 함수들이다.
// 즉 쓰지 않는다면 막아둘 필요가 있다.

#include <iostream>
#include <string>

class EmptyClass
{
public : 
	EmptyClass() {}
	EmptyClass(const EmptyClass& rhs) {}
	EmptyClass& operator=(const EmptyClass& rhs) {}
	~EmptyClass() {}
};

template <typename T>
class NamedObject
{
public : 
	// 멤버 변수 name이 참조자이기 때문에, char 배열로 선언하는 것은 막았다.
	// NamedObject(const char* name, const T& value) :
	// 	m_Name(name), objectValue(value) {}
	NamedObject(const std::string name, const T& value) :
		m_Name(name), objectValue(value) {} 
	// 이 방법도 컴파일러가 멋대로 만들지 못하게 막는 방법!
	// NamedObject(const NamedObject& rhs) = delete;
	// NamedObject& operator=(const NamedObject& rhs) = delete;

private : 
	// 막는 방법!
	NamedObject(const NamedObject& rhs);
	NamedObject& operator=(const NamedObject& rhs);

private : 
	std::string& m_Name;
	const T objectValue;
};

int wmain()
{
	NamedObject<int> no1("test", 10); 

	// 선언하지도 않았는데 컴퍼일러가 자동으로 생성한 복사 생성자.
	//NamedObject<int> no2(no1);			

	return 0;
}