// Authored by : haneulkimdev
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/d98aedfde0e444509de83f1a21c8ef7e
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while(true){
        long long ans = 0;
        stack<pair<long long, long long>> s;
        int n;
        cin >> n;
        if(n==0) return 0;
        for(int i=0;i<n;i++){
            int x;
            int index = i;
            cin >> x;
            while(!s.empty() && s.top().first >= x){
                ans = max(ans, (i - s.top().second) * s.top().first);
                index = s.top().second;
                s.pop();
            }
            s.push({x, index});
        }
        while(!s.empty()){
            ans = max(ans, (n - s.top().second) * s.top().first);
            s.pop();
        }
        cout << ans << "\n";
    }
}

/*
스택에는 (높이, 해당 높이가 최초로 등장한 위치)가 저장된다. 기본적으로 스택은
높이에 대한 monotone stack으로 관리된다. 스택에서 pop이 발생할 때 마다 현재
스택의 top을 가지고 만들 수 있는 직사각형의 넓이를 계산할 수 있다.
long long으로의 형변환을 편하게 처리하기 위해 1LL을 매번 곱했고, 그냥 스택
자체를 pair<long long, long long>으로 선언해도 크게 상관 없다.
*/
