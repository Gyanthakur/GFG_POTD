#include <bits/stdc++.h>
using namespace std;

/*

EASY AND EFFICIENT SOLUTION O(1):

OBSERVATION :

FOR N =2 WE NEED MAKE ALL ELEMENTS EQUAL TO 2

FOR N=3 WE NEED TO MAKE ALL ELEMENTS EQUAL TO 3

.

.

.

FOR N=6 WE NEED TO MAKE ALL ELEMENTS EQUAL TO 6

SO THE AFTER APPLYING ALL THE OPERATIONS WE GET ALL  ELEMENTS IN ARRAY WILL BE EQUAL TO N ITSELF.

THAT IS FOR N=6 ARRAY ={6,6,6,6,6,6};

FOR N=7 ARRAY={7,7,7,7,7,7};

NOW CONSIDER FOR N=6

ORIGINAL ARRAY = {1,3,5,7,9,11};

SO FROM THE ABOVE OBSERVATION WE NEED TO MAKE ALL ELEMENTS EQUAL TO " 6 ".

SO FOR CHANGING 1 TO 6 , IT TAKES | 1-6 | OPERATIONS .

FOR CHANGING 3 TO 6 , IT TAKES |3-6| OPERATIONS .

AND SOON .

-->

DERIVATION OF FORMULA :

SO FOR N=6 , TO MAKE ALL ARRAY ELEMENTS EQUAL TO 6 , WE SHOULD CALCULATE THE VALUE OF

" ( | 1-6 | + | 3- 6 | + | 5 - 6 | + | 7-6 | + | 9 -  6| + | 11 - 6| ) "

WHICH IS EQUAL TO

 SUM OF N ODD NUMBERS - SQUARE OF N "

BUT AS MENTIONED IN THE QUESTION

WE CAN INCREMENT AND DECREMENT IN ONE SINGLE STEP

THE FORMULA BECOMES

  (  SUM OF N ODD NUMBERS - ( (SQUARE OF N)/2) )/2

WHICH IS EQUAL TO  (N^2 - ((N^2)/2))/2

WHICH CAN BE FURTHER SIMPLIFIED TO

( 2*(N^2)-(N^2))/4 ==== (N^2)/4

SO THE FINAL FORMULA IS :

     ( N^2) /4

C++ CODE :

*/

class Solution
{
public:
  long long int minOperations(int N)
  {
    // Code here
    return ((long long)N * N) / 4;

    /*
    other method

        if(N == 1)
       {
       return 0;
       }
       else if(N == 2)
       {
           return 1;
       }

        long ibm = -1;
        long res = 0;

        ibm = ((N + 1) / 2) - 1;
        res = (ibm * (ibm + 1));

        if(N % 2 == 0)
        {
            res += (ibm + 1);
        }

        return res;
        */
  }
};