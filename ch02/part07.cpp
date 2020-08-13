// ����ϴ�(������) Ŭ������ �Ҹ��ڴ� �ݵ�� virtual�� �����϶�.
// �� �� �ܴ� ���� �� �ʿ䰡 ���µ�, ������ ���� �Լ� ���̺� ����� ������
// Ŭ���� ũ�Ⱑ Ŀ���� �������� �ȿ� �� �ȵ��� ����!

// �׸��� STL ǥ�� �����̳� ���� ���� �Ҹ��ڰ� �ƴϴ�!��� �κ��� �˰� �Ѿ���Ѵ�.

class TimeKeeper
{
public : 
	TimeKeeper() {}
	// ������ �Ҹ���
	virtual ~TimeKeeper() {}

	// �߻� ���� �Լ��� ����� ���, ������ �ϳ� �ִ�.
	// �� ���� ���� �Ҹ����� ���Ǹ� ���� ������ �� �ȴ�.
	// �� �κ��� ��Ŀ ������ �� ���̴�.
	// virtual ~TimeKeeper() = 0;
};

class AtomicClock : public TimeKeeper {};
class WaterClock : public TimeKeeper {};
class WristClock : public TimeKeeper {};

// ������ ���� ���丮 �Լ��� �ִٰ� ��������.
// �� ��쿡�� �������� �Ҵ�� ��ü�� �����Ͱ� ��ȯ�ȴ�.
TimeKeeper* getTimeKeeper()
{
	return new TimeKeeper();
}

int main()
{
	// TimeKeeper Ŭ���� �������κ��� �������� �Ҵ�� ��ü�� ��´�.
	TimeKeeper* ptk = getTimeKeeper();

	// ���� 

	// �ڿ� ������ ���� ���� �����Ѵ�.
	delete ptk;

	return 0;
}