#include <bits/stdc++.h>
using namespace std;

/*
https://www.acmicpc.net/problem/9251
내가 짜서 풀긴 했는데 풀고 나서도 아직 아리송하여 다른 사람의 풀이를 봤다.
내가 짠 풀이는 정석적인 방식과 거의 비슷하지만 조금 다르다.
일단 현재 Dp[][] 배열이 현 상태 값을 명확히 담고 있지 않는 조금 이상한 방식이다.
두 문자열이 주어지니 A의 특정 범위까지 문자열에서 B 문자열 전체에 대한
LCS를 구해보자라는 생각으로 짰다.
일단 문자열이 같으면 LCS 길이가 하나 늘어나는 것은 당연하다.
매칭이 되었으니까 그 인덱스 전까지 최장 길이에서 1이 더해지는 것이다.
문자열이 다르면? 이 경우가 정석적인 방식이랑 다른데 나는 그냥 위쪽 칸에 있는
값을 그대로 박았다. 이것 때문에 Dp배열이 현 상태 값을 정확히 반영하지 못한다.
뭐 풀리긴 했지만 좋은 방식은 아닌 것 같다.
정석적인 방식으로 푼다면 일단 문자가 같은 경우에는 내 방식과 같다.
왼쪽 사선에 있는 칸에 매칭 된 문자가 추가되니 +1을 해준다.
문자가 다르다면 왼쪽 칸와 위쪽 칸을 비교하여 더 큰녀석이 현재 칸에 들어간다.
이게 왜 그러냐면 예시를 통해 이해하면 쉽다.
같은 경우라면 "ABCD","AEBD" 이렇게 비교가 된다하고 "ABCD" 여기서 D의 차례이고
"AEBD" 여기서도 D의 비교 차례이다. 이러면 D가 같으니 D가 같아 +1이고 "ABC"까지의
LCS에 +1을 해주면 된다.
근데 다른 경우를 보면 "ABC","AEB" 여기서 C가 선택되고 B랑 비교할 차례라고 해보자.
문자가 같이 않아서 그냥 +1을 할 수가 없고 다른 비교대상이 필요하다.
여태까지 쌓인 값들을 보면 "AB", "AEB"의 LCS와 "ABC", "AE"의 LCS는 Dp배열에 저장이 되어있다.
이 둘을 비교하여 더 큰 녀석을 집어넣으면 된다.
즉 문자가 다르면 Dp[3][3] = max(Dp[2][3], Dp[3][2])이렇게 되는 것이다.
이러면 최장의 상태가 Dp배열에 항상 들어가게 된다.
자세한 설명은 밑의 링크 블로그 주인분이 잘 해주셨다.
https://twinw.tistory.com/126
이 문제를 통해 기본적인 LCS 알고리즘을 알아간다.
*/

string A, B;
int Dp[1001][1001], Ans;

/*
int main() // 처음에 접근한 방식, 막연하게 될 거라고 제출했는데 맞았다....
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> A >> B;
	for (int i = 1; i <= A.size(); i++) {
		int Max = 0;
		for (int j = 1; j <= B.size(); j++) {
			Dp[i][j] = Dp[i - 1][j];
			if (A[i - 1] == B[j - 1]) {
				Dp[i][j] = Max + 1;
				Ans = max(Dp[i][j], Ans);
			}
			Max = max(Max, Dp[i - 1][j]);
		}
	}
	cout << Ans;
}
*/

int main() // 정석적인 방식
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> A >> B;
	for (int i = 1; i <= A.size(); i++) {
		for (int j = 1; j <= B.size(); j++) {
			if (A[i - 1] == B[j - 1])
				Dp[i][j] = Dp[i - 1][j - 1] + 1;
			else
				Dp[i][j] = max(Dp[i][j - 1], Dp[i - 1][j]);
		}
	}
	cout << Dp[A.size()][B.size()];
}