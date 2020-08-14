// ��ü ���� �� �Ҹ� ���� �߿��� ����� ���� �Լ��� ȣ������ ����1
// 1. ȣ�� ����� �������� ���ϴ� ��� ���ư��� ���� ��!
// 2. �� �ܿ��� ���� ���� �� �𸣱� ����

#include <string>

// ��� �ŷ��� ���� Ŭ����
class Transaction
{
public : 
	explicit Transaction(const std::string& logInfo);	// 
	// virtual void logTransaction() const = 0;		// ���� �Լ�(Ÿ�Կ� ���� �αװ� �޶�����.)
	void logTransaction(const std::string& logInfo) const;

private :
	void init();
};

Transaction::Transaction(const std::string& logInfo)
{
//	logTransaction();		// ������ �������� �� �ŷ��� �α��Ѵ�.
	init();	// �񰡻� �Լ��� ȣ��
}

void Transaction::init()
{
	// logTransaction();		// �ٵ� ���⼭ ���� �Լ��� ȣ��!(�̰��� �� �����ϴ�.)
}

class BuyTransaction : public Transaction
{
public:
	BuyTransaction(const std::string& logInfo);
	virtual void logTransaction() const;

private : 
	static std::string createLogString(const std::string& logInfo);
};

// �α� �⺻ ������ ���� Ŭ���� �����ڷ� �ѱ��!
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
	// ���� �� ��� 
	// Transaction�� �����ڰ� ����� ���ε�
	// �� �� ����Ǵ� logTransaction�� ��� BuyTransaction�� �޼ҵ尡 �ƴ϶�
	// Transaction�� BuyTransaction�̴�!
	// �� ���� ���ϴ´�� ������� �ʴ´ٴ� ���̴�!
	BuyTransaction b("Test");
}
