// Max Sum continuous sub-sequence in an array
// Assumption: At least one positive number in the array

#include <iostream>
using namespace std;

int findMaxSum(int a[], int size);
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i <n ; ++i) {
        cin>>a[i];
    }
    cout<<findMaxSum(a, n)<<"\n";
    return 0;
}
int findMaxSum(int a[], int size){
    int maxSum=0,sum=0;
    int i=0;
    while(i<size){
        sum+=a[i];
        if(sum<0)
            sum=0;
        if(sum>maxSum)
            maxSum=sum;
        i++;
    }

    return maxSum;
}