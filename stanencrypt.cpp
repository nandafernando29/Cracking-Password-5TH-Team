//EncryptionProgram

#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include <ctime>
# define size 100
using namespace std;



int x, y, n, t, i, flag;
long int e[size], d[size], temp[size], j;
char en[size], m[size], msg[size];
int prime(long int); 
void key();
long int cd(long int);
void encrypt();

int main()
{
   flag=0;
   srand(time(NULL));
   while(flag == 0)
   {
      x = rand() % 100 + 1; 
      flag = prime(x); // if not prime return 0
   }
   
   flag=0;
   while(flag == 0)
   {
      y = rand() % 100 + 1; 
      flag = prime(y); 
   }


   cout << "\nENTER STRING TO ENCRYPT\n";
   cin >> msg;
   for(i = 0; msg[i] != NULL; i++)
      m[i] = msg[i];
   n = x * y;
   t = (x - 1) * (y - 1);

   key();
   encrypt();
   
   cout<<"\n";
   cout<<"Your First Generated Prime number";
   cout<<"\n";
   cout<<x;
   cout<<"\n";
   cout<<"Your Second Generated Prime number";
   cout<<"\n";
   cout<<y;
   return 0;
}

int prime(long int pr)
{
   j = sqrt(pr);
   for(i = 2; i <= j; i++)
   {
      if(pr % i == 0) return 0;
   }
   return 1;
 }


void key()
{
   int k;
   k = 0;
   for(i = 2; i < t; i++)
   {
      if(t % i == 0)  continue;
      flag = prime(i);
      if(flag == 1 && i != x && i != y)
      {
         e[k] = i;
         flag = cd(e[k]);
         if(flag > 0)
         {
            d[k] = flag;
            k++;
         }
         if(k == 99)  break;
      }
   }
}

long int cd(long int a)
{
   long int k = 1;
   while(1)
   {
      k = k + t;
      if(k % a == 0)  return(k/a);
   }
}


void encrypt()
{
   long int pt, ct, key = e[0], k, len;
   i = 0;
   len = strlen(msg);

   while(i != len)
   {
      pt = m[i];
      pt = pt - 96;
      k = 1;
      for(j = 0; j < key; j++)
      {
         k = k * pt;
         k = k % n;
      }
      temp[i] = k;
      ct= k + 96;
      en[i] = ct;
      i++;
   }
   en[i] = -1;
   cout << "\n\nTHE ENCRYPTED MESSAGE IS\n";
   for(i=0; en[i] != -1; i++)
      cout << en[i];
}
