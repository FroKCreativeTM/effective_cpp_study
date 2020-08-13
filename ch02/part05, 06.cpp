// C++ ���ٽ�½ ����� ȣ���� ������ �Լ��鿡 �˰��� ������.
// ���� ������
// �Ǵ� ���� ���� ������
// �Ҹ���
// �� 3���� �ڵ� �� ���ٸ� �����Ϸ��� ����� �Լ����̴�.
// �� ���� �ʴ´ٸ� ���Ƶ� �ʿ䰡 �ִ�.

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
	// ��� ���� name�� �������̱� ������, char �迭�� �����ϴ� ���� ���Ҵ�.
	// NamedObject(const char* name, const T& value) :
	// 	m_Name(name), objectValue(value) {}
	NamedObject(const std::string name, const T& value) :
		m_Name(name), objectValue(value) {} 
	// �� ����� �����Ϸ��� �ڴ�� ������ ���ϰ� ���� ���!
	// NamedObject(const NamedObject& rhs) = delete;
	// NamedObject& operator=(const NamedObject& rhs) = delete;

private : 
	// ���� ���!
	NamedObject(const NamedObject& rhs);
	NamedObject& operator=(const NamedObject& rhs);

private : 
	std::string& m_Name;
	const T objectValue;
};

int wmain()
{
	NamedObject<int> no1("test", 10); 

	// ���������� �ʾҴµ� �����Ϸ��� �ڵ����� ������ ���� ������.
	//NamedObject<int> no2(no1);			

	return 0;
}