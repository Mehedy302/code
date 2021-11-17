#include <iostream>
#include <conio.h>
#include <math.h>
#include <fstream>
using namespace std;

int main(){


    ofstream fout;
    fout.open("output.txt");


    int x[10000],n,a,c,m,i,j;
    float r[10000];
    cout<<"Enter the number of random numbers to generate (n): ";
    cin>>n;
    cout<<"Enter the value of seed (x0):";
    cin>>x[0];
    cout<<"\nEnter the value of (a):";
    cin>>a;
    cout<<"\nEnter the value of (c):";
    cin>>c;
    cout<<"\nEnter the value of (m):";
    cin>>m;
    i=0;
    r[0]=(float)x[0]/m;
    if(a==1){

    do{

        x[i+1]=(x[i]+c)% m;
        r[i+1]=(float)x[i+1]/m;
        i++;
        }while(i<=n);
    }
    else if(c==0)
    {

        do{

        x[i+1]=(a*x[i])% m;
        r[i+1]=(float)x[i+1]/m;
        i++;
        }while(i<=n);
    }
    else{

        do{

        x[i+1]=(a*x[i]+c)%m;
         r[i+1]=(float)x[i+1]/m;
        i++;
         }while(i<=n);
    }

 fout<<"The obtained random numbers are \n";
     for(j=0;j<i;j++){
        fout<<"\n"<<r[j];
     }
    return 0;
}
