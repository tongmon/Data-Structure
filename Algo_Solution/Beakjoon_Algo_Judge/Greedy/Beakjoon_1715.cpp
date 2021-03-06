#include <bits/stdc++.h>
using namespace std;

/*
https://www.acmicpc.net/problem/1715
제일 값이 작은 것들 부터 더해가면 되는 그리디 문제다.
이유는 제일 작은 놈들 부터 섞으면 작은 녀석들이 섞인 그 카드뭉치가
또 비교가 될 수 있는데 이 과정에서 거기 섞인 작은 녀석들이 비교가 또 되는 것이다.
이게 말이 어려운데 설명해보면 1,2,7,8 이런 수의 카드 뭉치 수가 있으면
1 + 2를 하고 섞으면 비교가 3번이 되고 이 크기 3의 카드 뭉치는 7이나 8과 비교가 될 수 있다.
만약 7과 비교가 된다고 하면 3 + 7 = 10 이라는 비교 횟수가 도출되는데
이는 3에 1과 2가 포함된 카드 뭉치와 크기 7인 카드 뭉치가 비교가 된 것이고 작은 녀석 1이
포함된 상태로 비교가 더 진행되었다는 것이다.
만약 7 + 8 = 15 이렇게 비교를 끝내고 1과 비교를 또 진행해서 1 + 15 이렇게 비교가 되면
크기가 큰 8이 속한 카드 뭉치가 1과 비교가 되는 것이고 8이 한번 더 비교에 쓰이므로 비효율적이라고 볼 수 있다.
이게 복잡하면 그냥 아무 개수의 카드 3장을 써놓고 비교를 해보면 작은 녀석들부터 비교를 해야 
비교 횟수의 최솟값이 나온다는 것을 알 수 있고 카드가 더 많아도 3개에 대한 최솟값을 만들었기 때문에
계속 최솟값이 나오게 정렬된 상태로 비교하면 되는 것이다.
비교 상태가 일정하려면 우선순위 큐를 사용하면 되는 것이기에 이를 사용해 문제를 풀었다.
이 문제를 통해 그리디적인 사고를 길러간다.
*/

using ll = long long;
int N, In;
ll Ans;
priority_queue<ll, vector<ll>, greater<ll>> Q;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> In;
		Q.push(In);
	}
	while (Q.size() != 1) {
		ll A = Q.top(), B;
		Q.pop();
		B = Q.top(); 
		Q.pop();
		Ans += A + B;
		Q.push(A + B);
	}
	cout << Ans;
}