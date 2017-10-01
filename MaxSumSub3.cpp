// Max Sum continuous sub-sequence in an array of length at most l
// Assumption: At least one positive number in the array

#include <iostream>
#include <vector>

using namespace std;

void findMaxSum(vector <int> v,int maxlength);
int main() {
    int n;
    cin>>n;
    int maxLength;
    cin>>maxLength;
    int a[n];
    vector <int> b;
    for (int i = 0; i <n ; ++i) {
        cin>>a[i];
    }
    b.push_back(a[0]);
    for (int j = 1; j <n ; ++j) {
        b.push_back(b[j-1]+a[j]);
    }
    findMaxSum(b,maxLength);
    return 0;
}

void findMaxSum( vector<int> v, int maxlength){
    int stack[v.size()];
    int start=0,top=0,i=0,max=0,cmax=0;
    stack[top]=0;
    for ( i = 1; i <= maxlength ; ++i) {

        if(v[stack[top]]<v[i])
            stack[++top]=i;

        cmax= v[i]-v[stack[start]];    // stack start holds the min value at any given point of time
                                       // so current value - min will give max in current window
        if(cmax> max)
            max = cmax;
    }

    while (i<v.size()){

        if(v[i]>= v[stack[top]])
            stack[++top]=i;
        else{
            while(v[i]<v[stack[top]] && top>(start-1)){
                top--;
            }
            stack[++top]=i;
        }

        if(stack[top]-stack[start]+1> maxlength)
            start++;

        cmax= v[i]-v[stack[start]];

        if(cmax> max)
            max = cmax;

        i++;
    }

    cout<<max<<endl;
}