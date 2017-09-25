#include <iostream>
#include <vector>
using namespace std;
void findMaxDiff(vector<int> v, int k);
int main() {
    vector<int> num;
    int window=3,sz,input;
    cout<<"Enter the number of Elements in array: "<<endl;
    cin>>sz;
    for (int i = 0; i < sz ; ++i) {
        cin>>input;
        num.push_back(input);
    }
    findMaxDiff(num, window);
    return 0;
}

// finding max diff in a window where j-i+1 <= window

void findMaxDiff(vector<int> v, int k){
    int stack[v.size()];
    int start=0,top=0,j=0,i=0,max=0,cmax=0;
    stack[top]=0;
    for ( i = 1; i < k-1 ; ++i) {
        if(v[stack[top]]<v[i])
            stack[++top]=i;
        cmax= v[i]-v[stack[start]];
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
        if(stack[top]-stack[start]+1> k)
            start++;

        cmax= v[i]-v[stack[start]];
        if(cmax> max)
            max = cmax;

        i++;
    }

    cout<<max<<endl;
}