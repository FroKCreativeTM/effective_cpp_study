// 객체 생성 및 소멸 과정 중에는 절대로 가상 함수를 호출하지 말라1
// 1. 호출 결과가 여러분이 원하는 대로 돌아가지 않을 것!
// 2. 그 외에도 언제 터질 지 모르기 때문

#include <string>

// 모든 거래에 대한 클래스
class Transaction
{
public : 
	explicit Transaction(const std::string& logInfo);	// 
	// virtual void logTransaction() const = 0;		// 가상 함수(타입에 따라 로그가 달라진다.)
	void logTransaction(const std::string& logInfo) const;

private :
	void init();
};

Transaction::Transaction(const std::string& logInfo)
{
//	logTransaction();		// 마지막 동작으로 이 거래를 로깅한다.
	init();	// 비가상 함수를 호출
}

void Transaction::init()
{
	// logTransaction();		// 근데 여기서 가상 함수를 호출!(이것이 더 위험하다.)
}

class BuyTransaction : public Transaction
{
public:
	BuyTransaction(const std::string& logInfo);
	virtual void logTransaction() const;

private : 
	static std::string createLogString(const std::string& logInfo);
};

// 로그 기본 정보를 상위 클래스 생성자로 넘긴다!
BuyTransaction::BuyTransaction(const std::string& logInfo) : 
	Transaction(createLogString(logInfo))
{
}

void BuyTransaction::logTransaction() const
{

}

std::string BuyTransaction::createLogString(const std::string& logInfo)
{
	return std::string();
}

int main()
{
	// 만약 이 경우 
	// Transaction의 생성자가 실행될 것인데
	// 이 때 실행되는 logTransaction의 경우 BuyTransaction의 메소드가 아니라
	// Transaction의 BuyTransaction이다!
	// 즉 내가 원하는대로 실행되지 않는다는 것이다!
	BuyTransaction b("Test");
}
