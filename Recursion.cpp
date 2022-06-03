#include <iostream>
#include <math.h>
using namespace std;

int recursiveSumDownLine(int start, int terms);
float factorial(int number);
long powerFunction(int number, int power);
long optimizedPowerFunction(int number, int power);
float tylorSeries(int x, int terms);
float optimizedTylorSeries(int x, int terms);
float mostOptimizedTylorSeries(int x,int terms);
float nCr(int N, int R);
float nCrPascalTriangle(int n, int r);

int main()
{
    printf("recursiveTylor \n");

    int b = 2;
    // printf("number answer should be 7.389\n ");
    printf("number answer should be 210\n ");
    // swap(&a,&b);
    // printf("answer printed %f \n", tylorSeries(-2, 20));
    // printf("answer printedOptimized %f \n", optimizedTylorSeries(-2, 20));
    // printf("answer printedmostOptimized %f \n", mostOptimizedTylorSeries(-2, 20));
    printf("answer NCR %f \n", nCr(30,4));
    printf("answer NCR %f \n", nCrPascalTriangle(30,4));
    return 0;
}






int recursiveSumDownLine(int start, int terms)
{
    if (terms == 0)
    {
        return 0;
    }
    return start + recursiveSumDownLine(start - 1, terms - 1);
}

float factorial(int number)
{
    if (number == 0)
    {
        return 1;
    }
    else
        return number * factorial(number - 1);
}

long powerFunction(int number, int power)
{
    if (power == 1)
    {
        return number;
    }
    else
    {
        return number * powerFunction(number, power - 1);
    }
}

long optimizedPowerFunction(int number, int power)
{

    if (power == 1)
    {
        return number;
    }

    if (power % 2 == 1)
    {
        return number * optimizedPowerFunction(number * number, power / 2);
    }
    else
    {
        return optimizedPowerFunction(number * number, power / 2);
    }
}



float tylorSeries(int x, int terms)
{
    if(terms==0){
        return 1;
    }else{
        return ((double)pow(x,terms)/((double)factorial(terms))) + tylorSeries(x,terms-1);
    }

}


float optimizedTylorSeries(int x, int terms){
    static float factorial=1,xPow=x,current=0;
    // cout<<"factorial = "<<factorial <<" xPow= "<<xPow <<endl;
    if(terms==0){
        return 0;
    }
    if(terms-current==0){
        return xPow*xPow/(factorial*(factorial+1));
    }

    if(current==0){
        current++;
        return 1+optimizedTylorSeries(x,terms);
    }else
    if(current==1){
         current++;
         return (xPow/factorial)+optimizedTylorSeries(x,terms);
    }
    else
    {
       
        xPow=xPow*x;
        factorial=factorial*(current);
        current++;
        return (xPow/factorial)+optimizedTylorSeries(x,terms);
    }
}




float mostOptimizedTylorSeries(int x,int terms){
    static float current=0;
    if(x==0) return 1;
    if(terms-current==1){
            current++;
            return 1+(x/current);
    }
    current++;
    return 1+(x/current)*mostOptimizedTylorSeries(x,terms);
}





float nCr(int N, int R){
    static float n=N+1,r=R+1,n_r=(N-R+1);
    if(R>N) {
        cout<<"wrong values.. n=>r=>0"<<endl;
        return -1;}

    n--;
    r--;
    n_r--;
    if(n==0)return 1;
    if(r<1)r=1;
    if(n_r<1)n_r=1; 
    return n/(r*n_r)*nCr(N,R);
}

float nCrPascalTriangle(int n, int r){
    if(r==0||n==r)return 1;
    return nCrPascalTriangle(n-1,r-1)+nCrPascalTriangle(n-1,r);
}










