#include <iostream>

#include "part02.h"

using namespace std;

// #define 대신 const와 inline을 사용하자
// 이유는 단순하다. 컴파일러가 #define 즉 전처리기를 볼 수 없기 때문에
// 그렇다.
// 또 const를 사용하고, string을 사용하면 상수 문자열을 좀 더 쉽게 저장할 수 있다는 이점도 있다.

// 상수
#define TEST_DEFINE 10
const int TEST_CONST = 10;

// 함수
#define SWAP_DEFINE(x, y) { t = x; x = y; y = t; }
inline void swap_inline(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// 상수 문자열
const char* const writerNick = "Frok const char* const";
const std::string writerNickWithString = "Frok with string";

class CGamePlayer
{
private : 
	enum { eNumTurn = 5 };				// 또 다른 상수 선언 방식입니다.
	static const int numTurns = 5;		// 상수 선언
	int scores[numTurns];				// 상수를 사용하는 부분

};

const double CCostEstimate::m_FudgeFactor = 1.35;	// 이 부분은 구현 파일에서 정의합니다.

int main()
{


	return 0;
}