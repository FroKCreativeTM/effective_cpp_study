// ���ܰ� �Ҹ��ڸ� �������� �� �ȴ�.
// �� ���� �����̳�, �Ҹ��ڷ� ���� ������ �߻��Ͽ� ���ܰ� ���� �����ٸ�
// ũ�� �� ����� �ִ�. 
// 1. ���α׷� ����(std::abort)
// 2. ���� ��Ű�� (���� ����� �ƴ�, 

#include <iostream>
#include <exception>

class DBConnection
{
public : 
	static DBConnection create();	// DBConnection ��ü ��ȯ
	void close();					// ������ �ݴ´�.
};

class DBConn
{
private :
	DBConnection db;

public : 
	// �����ͺ��̽� ������ �׻� �������� Ȯ���� ì���ִ� �Լ�
	~DBConn()
	{
		try 
		{
			db.close();
		}
		catch (std::exception& err)
		{	// 1. ����
			std::abort();
		}
		catch (std::out_of_range& err)
		{   // 2. ���ܸ� ���ѹ�����. (�� ���� �α׸� �����.)
			std::cerr << err.what() << std::endl;
		}
	}
};