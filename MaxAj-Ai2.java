
//Max Aj-Ai for j>=i+l

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner input= new Scanner(System.in);
        int [] a= new int[5];
        for (int i = 0; i <5 ; i++) {
            a[i]=input.nextInt();
        }
        System.out.println(findMax(a,5,3));
    }


    static int findMax( int [] a, int size,int window){
        int i=0,j=window,max=0,cmax=0;
        max= a[j]-a[i];

        for ( j = window; j < size ; j++) {

            if(a[i]>a[j-window]){
                i = j-window;
            }

            cmax=a[j]-a[i];

            if(cmax>max){
                max = cmax;
            }
        }

        return max;
    }
}
