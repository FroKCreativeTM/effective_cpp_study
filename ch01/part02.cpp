#include <iostream>

#include "part02.h"

using namespace std;

// #define ��� const�� inline�� �������
// ������ �ܼ��ϴ�. �����Ϸ��� #define �� ��ó���⸦ �� �� ���� ������
// �׷���.
// �� const�� ����ϰ�, string�� ����ϸ� ��� ���ڿ��� �� �� ���� ������ �� �ִٴ� ������ �ִ�.

// ���
#define TEST_DEFINE 10
const int TEST_CONST = 10;

// �Լ�
#define SWAP_DEFINE(x, y) { t = x; x = y; y = t; }
inline void swap_inline(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// ��� ���ڿ�
const char* const writerNick = "Frok const char* const";
const std::string writerNickWithString = "Frok with string";

class CGamePlayer
{
private : 
	enum { eNumTurn = 5 };				// �� �ٸ� ��� ���� ����Դϴ�.
	static const int numTurns = 5;		// ��� ����
	int scores[numTurns];				// ����� ����ϴ� �κ�

};

const double CCostEstimate::m_FudgeFactor = 1.35;	// �� �κ��� ���� ���Ͽ��� �����մϴ�.

int main()
{


	return 0;
}