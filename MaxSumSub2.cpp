// Max Sum continuous sub-sequence in an array of length atleast l
// Assumption: At least one positive number in the array

#include <iostream>
using namespace std;

int findMaxSum(int a[], int size,int minLength);
int main() {
    int n;
    cin>>n;
    int minLength;
    cin>>minLength;
    int a[n],b[n];
    for (int i = 0; i <n ; ++i) {
        cin>>a[i];
    }
    b[0]=a[0];
    for (int j = 1; j <n ; ++j) {
        b[j]=b[j-1]+a[j];
    }
    cout<<findMaxSum(b, n,minLength)<<"\n";
    return 0;
}
int findMaxSum(int a[], int size,int minLength){
        int i=0,j=minLength-1,max=0,cmax=0;
        max= a[j]-a[i];

        for ( ; j < size ; j++) {

            if(a[i]>a[j-minLength-1]){
                i = j-minLength-1;
            }

            cmax=a[j]-a[i];

            if(cmax>max){
                max = cmax;
            }
        }

        return max;

}