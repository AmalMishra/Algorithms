#include <iostream>
#include <vector>
using namespace std;
void printSmallest(vector<int> v,int k);
int main() {
    vector<int> num;
    int k=3,sz,input;
    cout<<"Enter the number of Elements in array: "<<endl;
    cin>>sz;
    for (int i = 0; i < sz ; ++i) {
        cin>>input;
        num.push_back(input);
    }
    printSmallest(num,k);
    return 0;
}

void printSmallest(vector<int> v,int k){
    int stack[v.size()];
    int start=0,top=0,j=0,i=0;
    stack[top]=0;
    for ( i = 1; i < k-1 ; ++i) {
        if(v[stack[top]]<v[i])
            stack[++top]=i;
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
        if(stack[top]-stack[start]+1> k)
            start++;

        cout<<v[stack[start]]<<endl;
            i++;
    }
}