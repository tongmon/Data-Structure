#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define Moded 1000000000

/*
https://www.acmicpc.net/problem/2225
분해합 문제이다.
개인적으로 점화식 생각해내기가 초짜인 나한테 너무 까다로웠다..
결과 도출할 때 필요한 값이 2개이므로 일단 Dp배열이 2차원이 아닌가 의심을 해본다.
2차원이 맞다면 이제 Dp식을 세워야 하는데 이 문제의 점화식은 이런 방식이다.
20을 2개를 선택해서 나누게 되면 (0, 20) (1, 19) (2, 18)... 이러한 방법이 나오는데
여기서 (0, 20)을 잡고 보면 얘는 20을 어떻게 더 쪼개는지에 따라 3개를 더해서 20만들기, 4개를 더해서 20만들기... 무한확장이 가능하다.
결국 20을 3개를 선택해서 더하기는 (0, 20)에서의 Dp[20][2], (1, 19)에서의 Dp[19][2].. 이렇게 나타낼 수 있는 것이다.
이 위의 방식은 3중 포문을 돌려야하나 약간 더 효율적으로 만들 수가 있는데
어짜피 Dp[20][3]을 구하는 경우를 예로 들어보면 (0, 20)에서 20을 2개로 쪼개고, (1, 19)에서 19을 2개로 쪼개고.. 이러한 방법이 나오는데
Dp[19][3]을 구하는 경우를 보면 (0, 19)에서 19을 2개로 쪼개고, (1, 18)에서 18을 2개로 쪼개고... 결국 보면 Dp[20][3]은 2개로 쪼개는 것에 있어서
Dp[19][3]를 포함한다. 새로 추가 되는 것은 20을 2개로 쪼개는 경우 뿐이다. 
Dp[20][3] = Dp[19][3] + Dp[20][2] 이러한 점화식이 성립하는 것이다.
이 문제를 통해 초반에 감이 잡히지 않더라도 차근차근 문제를 쪼개다 보면 특히 Dp 문제에서는 답이 서서히 보이기 시작한다는 교훈을 얻을 수가 있다.
*/

int Dp[1000][1000]; // Dp[i][j]라면 i는 더해지게 되는 최종 수 N, j는 j개를 사용해서 i를 더하게 되는 갯수이다.

int SumNum(int N, int K)
{
	for (int i = 0; i <= N; i++)
	{
		Dp[i][1] = 1; Dp[i][2] = i + 1;
	}
	for (int i = 3; i <= K; i++)
	{
		for (int j = 0; j <= N; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				Dp[j][i] = (Dp[j][i] + Dp[j - k][i - 1]) % Moded;
			}
		}
	}
	return Dp[N][K];
}

int SumNum_improved(int N, int K)
{
	for (int i = 0; i <= N; i++)
	{
		Dp[i][1] = 1; Dp[i][2] = i + 1;
	}
	for (int i = 0; i <= K; i++)
	{
		Dp[0][i] = 1; // 0은 몇개를 고르던 방법은 1가지 뿐이다.
	}
	for (int i = 3; i <= K; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			Dp[j][i] = (Dp[j - 1][i] + Dp[j][i - 1]) % Moded;
		}
	}
	return Dp[N][K];
}

int main()
{
	int N, K;
	scanf_s("%d %d", &N, &K);
	cout << SumNum_improved(N, K);
}