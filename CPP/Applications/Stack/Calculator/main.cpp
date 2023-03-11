#include<iostream>
#include "Calculator.h"
using namespace std; 
#define EXPRESSION_SIZE (50)

int main() 
{

    Calculator obj;
    string Exression[EXPRESSION_SIZE]; 
    uint32_t Size; 
    uint32_t i; 
    float  result ; 
    for(i=0 ; i<EXPRESSION_SIZE ; i++) 
    { 
        cin>>Exression[i]; 
        if(Exression[i] == "=") 
        { 
            Size=i; 
            break; 
        } 
    }   
    if(obj.EvaluateInfix(Exression , Size , result))
    {   
        //cout << fixed ; /* remove the comment on this line if the output will be more than 6 digit(integer part) */
        cout<< result <<endl ; 
    }else
    {
        /*Do any thing */
        cout<<"wrong Expression "<<endl ;
    }
    
    return 0; 
}


