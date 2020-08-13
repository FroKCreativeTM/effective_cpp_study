// 예외가 소멸자를 떠나서는 안 된다.
// 이 말은 무엇이냐, 소멸자로 부터 에러가 발생하여 예외가 터져 나간다면
// 크게 두 방법이 있다. 
// 1. 프로그램 종료(std::abort)
// 2. 예외 삼키기 (좋은 방법이 아님, 

#include <iostream>
#include <exception>

class DBConnection
{
public : 
	static DBConnection create();	// DBConnection 객체 반환
	void close();					// 연결을 닫는다.
};

class DBConn
{
private :
	DBConnection db;

public : 
	// 데이터베이스 연결이 항상 닫히도록 확실히 챙겨주는 함수
	~DBConn()
	{
		try 
		{
			db.close();
		}
		catch (std::exception& err)
		{	// 1. 종료
			std::abort();
		}
		catch (std::out_of_range& err)
		{   // 2. 예외를 삼켜버린다. (이 경우는 로그만 남긴다.)
			std::cerr << err.what() << std::endl;
		}
	}
};