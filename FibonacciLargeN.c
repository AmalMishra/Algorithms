#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

int main() {
    printf("Hello, World!\n");
    int a[5]={3,2,3,4,5};
    int b[5]={1,2,3,4,4};
    int *result=(int *)malloc(sizeof(int)*5);
    int resultSize= addNum(a,b,5,5,result);
    print(result,resultSize);
    resultSize=subtractNum(a,b,5,5,result);
    print(result,resultSize);
    int modresult=0;
    mod(a,5,10,&modresult);
    printf("%d",modresult);
    return 0;
}

void print(int *a,int size){
    for (int i =size-1 ; i >=0 ; i--) {
        printf("%d",a[i]);
    }
    printf("\n");
}



//Function to calculate sum of two large numbers

int addNum(int* num1, int* num2,int m,int n,int* res ){

    int i,j,k=0,carry=0;
    i=m-1;
    j=n-1;

    while(i>=0 && j>=0){
        res[k++]= (num1[i]+ num2[j] + carry) % 10;

        carry=(num1[i]+ num2[j]+carry) / 10;
        i--;j--;
    }

    //in case first number is large
    if(i>=0){
        while(i>=0){
            res[k++]=(num1[i] + carry)%10;
            carry=(num1[i] +carry)/10;
            i--;
        }
    }

    //second number is large
    if(j>=0){
        while(j>=0){
            res[k++]=(num2[j]+ carry)%10;
            carry = (num2[j] + carry)/10;
            j--;
        }
    }
    if(carry){             //overflow check
        res[k++]=carry;
    }
    return k;
}


// Function to find difference of two large numbers

int subtractNum (int * num1, int * num2,int m,int n,int* res ){
//assumption : I am assuming that num1>=num2
    int i,j,k=0,borrow=0;
    i=m-1,j=n-1;
    while(i>=0 && j>=0){
        res[k]= num1[i]-num2[i]+borrow;
        if(res[k]<0){
            res[k]+=10;
/* suppose numbers are 123-29 then 3-9 will be -6 so we need to add 10 to it to make it 4 and
set borrow flag to 1 */
            borrow=1;
        }
        else{            //yes this is necessary because you need to check for each case
            borrow=0; }
        k++;i--;j--;
    }

//checks for larger number
    while(i>=0){
        res[k]= num1[i] + borrow;
        if(res[k]<0){
            res[k]+=10;
            borrow=1;}
        else{
            borrow=0;}
        k++;i--;
    }
    k--;
    while(res[k]==0 && k!=0)
        k--;
    return k+1;
}


//Function to calculate modulus of large number

void mod(int * string,int n, int a,int *res)
{

    // One by one process all digits of 'num'
    for (int i = 0; i < n; i++)
        (*res) = ((*res)*10 + string[i]) %a;
}

int findPeriod(int n)
{  long int a,b,c;
    c=0;
    a=0;
    b=1;
    for(int i=1; i< 6*n; i++){
        c=(a+b)%n;
        a=b;
        b=c;
        if(c==1&&b==0){
            c=i;
            break;
        }
    }

    return c;

}