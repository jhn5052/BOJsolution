//참고 : crocus.co.kr/707
//세그먼트트리 응용
//init과 sum이 약간 다름 -> 작은 값으로 조정하는 것
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;
int N;

//segment tree init
void init(vector<int> &arr, vector<int> &tree, int node, int start, int end){
    if(start == end){//리프노드에 인덱스번호 넣기
        tree[node] = start;
    }
    else{
        int mid = (start + end) / 2;
        init(arr, tree, node*2, start, mid);
        init(arr, tree, node*2+1, mid+1, end);
        
        //트리노드 구간합에서 작은 값으로 트리에 값 저장
        if(arr[tree[node*2]] <= arr[tree[node*2+1]]){
            tree[node] = tree[node*2];
        }
        else{
            tree[node] = tree[node*2+1];
        }
    }
}

//구간에서 최소 높이 막대기값 구하기 - 세그트리의 합 응용
int sum(vector<int> &arr, vector<int> &tree, int start, int end, int node, int left, int right)
{
    //구간 벗어났을 때
    if(left > end || right < start) return -1;

    //구하려고 하는 구간 합구간에 포함될때
    if(left <= start && end <= right)   return tree[node];

    int mid = (start + end) / 2;
    int l = sum(arr, tree, start, mid, node * 2, left, right);
    int r = sum(arr, tree, mid + 1, end, node * 2 + 1, left, right);
    if(l == -1){
        return r;
    }
    else if(r == -1){
        return l;
    }
    else if(arr[l] <= arr[r]){
        return l;
    }
    else{
        return r;
    }
}

ll getMax(vector<int> &arr, vector<int> &tree, int start, int end)
{
    int idx = sum(arr, tree, 0, N-1, 1, start, end);

    //넓이(구간길이 * 최소값)
    ll area = (ll)(end-start+1)*(ll)arr[idx];

    //왼쪽과 오른쪽 있으면 다시 재귀
    if(start <= idx-1){
        area = max(area, getMax(arr, tree, start, idx - 1));
    }
    if(idx+1 <= end){
        area = max(area, getMax(arr, tree, idx + 1, end));
    }
    return area;
}

int main(){
    while(true){
        scanf("%d", &N);
        if(N == 0){
            break;
        }
        //init
        vector<int> arr(N);
        arr = vector<int> (N);
        for(int i = 0; i < N; i++){
            scanf("%d", &arr[i]);
        }
        //트리높이
        int h = (int)(ceil(log2(N)) + 1e-9);
        int tree_s = (1 << (h+1));
        vector<int> tree(tree_s);
        
        //세그트리 init
        init(arr, tree, 1, 0, N-1);
        printf("%lld\n", getMax(arr, tree, 0, N-1));
    }
    return 0;
}
