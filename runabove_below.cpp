
#include<stdio.h>
#include<iostream>
#include <fstream>
#include<stdlib.h>
#include<math.h>

using namespace std;
int r_number[5000];
int main()

{
    double calculate_avg(int n);
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

	double avg=calculate_avg(n);



	bool runup ;
	if(avg>r_number[0])
    {
        runup = true;
    }


	 char run[5000];

	 int numbers_of_run=0 ;
	 int n1=0,n2=0;

	 for(int i=0;i<n;i++)
     {
        if(runup)
        {
            if(r_number[i]>avg)
            {
                run[i]='+';
                n1 = n1+1;
            }
            else{
                run[i]='-';
                runup=false;
                numbers_of_run = numbers_of_run + 1;
                n2 = n2 + 1;
            }
        }
        else{
            if(r_number[i]<avg)
            {
                run[i]='-';
                n2 = n2 + 1;
            }
            else{
                    n1 = n1+1;
                run[i]='+';
                runup=true;
                numbers_of_run = numbers_of_run + 1;
            }
        }

     }
      freopen("output.txt","w",stdout);
     printf("\n The Run is : ");


     for(int i=0;i<n;i++)
     {
         printf("%c ",run[i]);
     }
     printf("\nThe above run = %d below run is = %d\n",n1,n2);



   printf("\n\nNumber of run : %d\n",numbers_of_run);
   int prod = 2*n1*n2;

   double mu=(float)((prod)/n)+0.5 ;

   double varience = sqrt( ((prod)*(prod-n))/(n*n*(n-1)));


   printf("Mu = %llf and varience = %llf\n",mu,varience);


   double z  = (numbers_of_run-mu)/varience;

   printf("The expected Z = %llf\n",z);
   printf("Result : ");

   if(z>=-1.96 && z<=1.96)
   {
       printf("ACCEPTED\n");

   }
   else
   {

       printf("NOT ACCEPTED\n");
   }



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

double calculate_avg(int n){

double avg,sum=0.0;
for(int i = 0;i<n;i++)
{
    sum=(double)(sum+r_number[i]);

}

avg = (float)(sum/n);

return avg;



}


