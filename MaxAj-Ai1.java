// Max Aj-Ai for j>i

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner input= new Scanner(System.in);
        int [] a= new int[5];
        for (int i = 0; i <5 ; i++) {
            a[i]=input.nextInt();
        }
        System.out.println(findMax(a,5));
    }


    static int findMax( int [] a, int size){
        int i=0,j=1,max=0,cmax=0;
        max= a[j]-a[i];

        for ( j = 2; j < size ; j++) {

            cmax=a[j]-a[i];
            if(a[i]>a[j]){
                i=j;
            }
            if(cmax>max){
                max = cmax;
            }
        }

        return max;
    }
}
