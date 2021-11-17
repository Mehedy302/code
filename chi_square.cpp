#include<stdio.h>
#include<iostream>
#include <fstream>
#include<stdlib.h>

using namespace std;
int r_number[5000];
int main()

{
   int get_input_from_lcm(int n);//it wiil generae random number Using LCM
  int get_input_from_rnd(int n);//it wiil generae random number Using Rand function
  int expect;

  int n;
  printf("Enter the amount of random numbers N:");
  scanf("%d",&n);

  int choice;

  printf("Enter choice: 2 for Random function and 1 for LCM : ");
  scanf("%d",&choice);
  if(choice==2){
    get_input_from_rnd(n);
  }
  else
  {



    get_input_from_lcm(n);

  }


 expect = n/10;

    fstream my_file;
	my_file.open("input.txt", ios::in);
	if (!my_file) {
		cout << "No such file";
	}
	else {
		int ch;
		int i=0;

		while (1) {
			my_file >> ch;
			if (my_file.eof())
				break;

			r_number[i]= ch;
			i++;
		}

	}
	my_file.close();



    int group[10]={0,0,0,0,0,0,0,0,0, 0 };

    for(int i = 0; i<n;i++)
    {
        if(r_number[i]>=900 )
             group[9]++;

       else if(r_number[i]>=800 )
            group[8]++;

       else if(r_number[i]>=700 )
            group[7]++;
       else if(r_number[i]>=600 )
            group[6]++;

       else if(r_number[i]>=500 )
            group[5]++;
       else if(r_number[i]>=400 )
            group[4]++;
       else if(r_number[i]>=300 )
            group[3]++;

       else if(r_number[i]>=200 )
            group[2]++;
       else if(r_number[i]>=100 )
            group[1]++;
       else
            group[0]++;


    }


    double chi_squre=0.0;

    freopen("output.txt","w",stdout);
    printf("---------------------------------------------------------------------------\n");
    printf("Sl\t| Expected Value | Observed Value |(Expected-Observed)^2/Expected  \n");
    printf("---------------------------------------------------------------------------\n");


    for(int i = 0;i<10;i++)
    {

        chi_squre =chi_squre+ (float)( ((group[i]-expect)*(group[i]-expect))*1.0)/expect;
        printf("%d\t|\t %d\t|\t %d\t|\t %lf\t|\n",i+1,expect,group[i],chi_squre);


    }
    printf("----------------------------------------------------------------------------\n");
    printf("\t\t\t\tChi-Square Value = %llf\n",chi_squre);

    if(chi_squre>= 1.73 && chi_squre<= 23.6)

    printf("\nResult : Accepted");
    else
        printf("\nResult : Rejected");









return 0;

}

int get_input_from_rnd(int n)

{
    ofstream fout;
  fout.open("input.txt");
    int i;
    for( i = 0 ; i < n ; i++ ) {
      fout<<rand()%1000<<" ";
   }
return 1;

}

int get_input_from_lcm(int n)
{
    ofstream fout;
  fout.open("input.txt");
   int a,c,m,i,j;
   int x[5000];


    cout<<"Enter the value of seed (x0):";
    cin>>x[0];
    cout<<"\nEnter the value of (a):";
    cin>>a;
    cout<<"\nEnter the value of (c):";
    cin>>c;
    m=1000;



        for(i=0;i<=n;i++) {

        x[i+1]=(a*x[i]+c)%m;
          fout<<x[i+1]<<" ";

        }





    return 1;


}





