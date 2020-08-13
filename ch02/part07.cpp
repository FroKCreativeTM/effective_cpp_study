// 상속하는(다형성) 클래스의 소멸자는 반드시 virtual로 선언하라.
// 단 그 외는 굳이 할 필요가 없는데, 이유는 가상 함수 테이블 등등의 문제로
// 클래스 크기가 커져서 레지스터 안에 다 안들어가기 때문!

// 그리고 STL 표준 컨테이너 등은 가상 소멸자가 아니다!라는 부분은 알고 넘어가야한다.

class TimeKeeper
{
public : 
	TimeKeeper() {}
	// 안전한 소멸자
	virtual ~TimeKeeper() {}

	// 추상 가상 함수를 만드는 경우, 복병이 하나 있다.
	// 이 순수 가상 소멸자의 정의를 두지 않으면 안 된다.
	// 이 부분을 링커 에러가 날 것이다.
	// virtual ~TimeKeeper() = 0;
};

class AtomicClock : public TimeKeeper {};
class WaterClock : public TimeKeeper {};
class WristClock : public TimeKeeper {};

// 다음과 같은 팩토리 함수가 있다고 가정하자.
// 이 경우에는 동적으로 할당된 객체의 포인터가 반환된다.
TimeKeeper* getTimeKeeper()
{
	return new TimeKeeper();
}

int main()
{
	// TimeKeeper 클래스 계통으로부터 동적으로 할당된 객체를 얻는다.
	TimeKeeper* ptk = getTimeKeeper();

	// 만약 

	// 자원 누출을 막기 위해 해제한다.
	delete ptk;

	return 0;
}