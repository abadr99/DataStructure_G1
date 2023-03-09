#include<iostream>
#include "Calculator.h"
using namespace std; 
#define EXPRESSION_SIZE (50)

int main() 
{

    string Exression[EXPRESSION_SIZE]; 
    uint32_t Size; 
    uint32_t i; 
    float  result ; 
    cout<<"Enter Infix Expression (Enter = to evaluate it ) : ";
    for(i=0 ; i<EXPRESSION_SIZE ; i++) 
    { 
        cin>>Exression[i]; 
        if(Exression[i] == "=") 
        { 
            Size=i; 
            break; 
        } 
    }   

    
    if(EvaluateInfix(Exression , Size , result))
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


