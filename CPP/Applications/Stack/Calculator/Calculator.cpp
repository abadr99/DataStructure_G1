#include<iostream>
#include <stack> 
#include <algorithm>
#include <string>
#include"Calculator.h"

using namespace std ; 
bool Calculator::EvaluateInfix(string _Exression[] ,uint32_t Size , float &pResult )
{
    string _PostExression[Size];
    uint32_t NewSize; 
    bool Expression_Flag = true ; 
    if( GetPostFix(_Exression ,  _PostExression , Size , NewSize) )
    {
        pResult = RevesePolishNotation(_PostExression , NewSize);
    }
    else
    {
        //Wrong Expression ;
        Expression_Flag = false ;
    }
    return Expression_Flag ;
}
bool Calculator:: GetPostFix(string _Exression[]  , string _PostExression[]  , uint32_t Size , uint32_t &NewSize  ) 
{
    stack <string> Stack_t;
    uint32_t j=0; 
    uint32_t i=0; 
    uint16_t BracketCounter = 0 ;
    bool Expression_Flag = true ;  
    for(i=0 ; i<Size ; i++ ) 
    { 
        if(IsNumber(_Exression[i]))
        {
            _PostExression[j]=_Exression[i];
            j++; 
        }else if (_Exression[i] == "(")
        {
            Stack_t.push(_Exression[i]);
            BracketCounter ++ ; 
            
        }
        else if( IsOperator(_Exression[i]) && BracketCounter != 0  ) 
        { 
            while(Stack_t.top() !="(" && priority(_Exression[i]) <= priority(Stack_t.top()) ) 
            {
              _PostExression[j]=Stack_t.top();
              j++; 
              Stack_t.pop();
     
            } 
            Stack_t.push(_Exression[i]); 
        }
        else if( IsOperator(_Exression[i]) ) 
        {
            
            while(Stack_t.empty() == 0 && priority(_Exression[i]) <= priority(Stack_t.top())) 
            {
              _PostExression[j]=Stack_t.top();
              j++; 
              Stack_t.pop(); 
            } 
            Stack_t.push(_Exression[i]); 
        }else if(_Exression[i] == ")" && BracketCounter != 0   )
        {
            while( Stack_t.top() != "(") 
            {
                _PostExression[j]=Stack_t.top(); 
                j++; 
                Stack_t.pop(); 
            }
            BracketCounter-- ; 
            Stack_t.pop();
            
        }
        else 
        {
            Expression_Flag = false ; 
        } 
    }
    if(BracketCounter != 0 )
    {
        Expression_Flag = false ; 
    }
    while(Stack_t.empty()==0) 
    {
        _PostExression[j]=Stack_t.top(); 
        j++; 
        Stack_t.pop(); 
    }
    if(  (j == 1 && IsOperator(_PostExression[0]) )  || j % 2 == 0 )
    {
        Expression_Flag = false ; 
    }
    NewSize =  j ;
    return  Expression_Flag ; 

}
float Calculator:: RevesePolishNotation(string _Exression[],uint32_t Size) 
{ 

    stack<float>Stack_t ; 
    uint32_t j ;
    for( j=0 ; j<Size ; j++) 
    { 
        if(IsNumber(_Exression[j]))
        {
            Stack_t.push( stof(_Exression[j] ) ) ;
        }
        else if(IsOperator(_Exression[j]) ) 
        { 
            float _Num1 ; 
            float _Num2 ; 
            float _Result ; 
            _Num2 = Stack_t.top() ; 
            Stack_t.pop(); 
            _Num1 = Stack_t.top() ; 
            Stack_t.pop(); 
            _Result = Evaluate(_Num1 , _Num2 ,_Exression[j] ); 
            Stack_t.push((_Result)); 
          
        }
       

    } 
    return Stack_t.top(); 
} 
bool Calculator::IsNumber(string _Number)
{
    bool LocReturn = false ; 
    if(_Number[0] == '-')
    {
        _Number.erase(remove(_Number.begin(), _Number.end(), '-'), _Number.end());
    }
    if( _Number >= "0" &&  _Number<="99999999")
    {
        LocReturn = true;
    } 
    return LocReturn ; 
}
 
bool Calculator:: IsOperator(string _operator) 
{ 
    bool LocReturn = false ; 
    if(_operator == "+" || _operator == "-" ||  _operator == "*" || _operator == "/") 
    { 
        LocReturn = true; 
 
    } 
    return LocReturn ; 
} 
float Calculator:: Evaluate(float Num1 ,float Num2  , string _operator) 
{ 
    float Ret_Result ; 
    if(_operator == "+") 
    {
        Ret_Result = Num1 + Num2 ; 
    } 
    else if(_operator == "-") 
    { 
        Ret_Result = Num1 - Num2 ; 
    } 
    else if(_operator == "*") 
    { 
        Ret_Result = Num1 * Num2 ; 
    } 
    else if(_operator == "/") 
    { 
        Ret_Result = Num1 / Num2 ; 
    } 
 
    return Ret_Result ; 
} 

bool Calculator:: priority (string oprator)
{
    bool RetFlag; 
    if(oprator == "+" || oprator =="-") 
        RetFlag= 0; 
 
    if(oprator == "*" || oprator =="/") 
        RetFlag= 1; 

    return RetFlag; 
} 