// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <stack>
using namespace std;



vector<int> nextgreaterelement(vector<int> arr)
{
    stack<int> s;
    vector<int> nge(arr.size(),-1);
    for(int i=arr.size();i>=0;i--)
    {
        if(!s.empty() && s.top()<arr[i]) s.pop();
        if(!s.empty()) nge[i]=(s.top());
        s.push(arr[i]);
    }
    return nge;
}

int main() {
    // Write C++ code here
    vector<int> arr = {1,2,3,4};
    vector<int> res = nextgreaterelement(arr);
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
    return 0;
}