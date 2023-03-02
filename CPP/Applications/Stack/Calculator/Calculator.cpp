#include <stack> 
#include <algorithm>
#include <string>
#include "Calculator.h"

bool EvaluateInfix(string _Exression[] ,uint32_t Size , float *pResult )
{
    string _PostExression[Size];
    uint32_t NewSize; 
    bool Expression_Flag = true ; 
    if( GetPostFix(_Exression ,  _PostExression , Size , &NewSize) )
    {
        (*pResult) = RevesePolishNotation(_PostExression , NewSize);
    }
    else
    {
        //Wrong Expression ;
        Expression_Flag = false ;
    }
    return Expression_Flag ;
}
bool GetPostFix(string _Exression[]  , string _PostExression[]  , uint32_t Size , uint32_t *NewSize  ) 
{
    stack <string> S1;
    uint32_t j=0; 
    uint32_t i=0; 
    bool BracketFlag = false ;
    bool Expression_Flag = true ;  
    for(i=0 ; i<Size ; i++ ) 
    { 
        if(IsNumber(_Exression[i]))
        {
            _PostExression[j]=_Exression[i];
            j++; 
        }else if (_Exression[i] == "(")
        {
            S1.push(_Exression[i]);
            BracketFlag = true ; 
            
        }
        else if( IsOperator(_Exression[i]) && BracketFlag == true  ) 
        { 
            while(S1.top() !="(" && priority(_Exression[i]) <= priority(S1.top()) ) 
            {
              _PostExression[j]=S1.top();
              j++; 
              S1.pop();
     
            } 
            S1.push(_Exression[i]); 
        }
        else if( IsOperator(_Exression[i]) ) 
        {
            
            while(S1.empty() == 0 && priority(_Exression[i]) <= priority(S1.top())) 
            {
              _PostExression[j]=S1.top();
              j++; 
              S1.pop(); 
            } 
            S1.push(_Exression[i]); 
        }else if(_Exression[i] == ")" && BracketFlag == true   )
        {
            while( S1.top() != "(") 
            {
                _PostExression[j]=S1.top(); 
                j++; 
                S1.pop(); 
            }
            BracketFlag = false ; 
            S1.pop();
            
        }
        else 
        {
            Expression_Flag = false ; 
        } 
    }
    if(BracketFlag == true )
    {
        Expression_Flag = false ; 
    }
    while(S1.empty()==0) 
    {
        _PostExression[j]=S1.top(); 
        j++; 
        S1.pop(); 
    }
    if(  (j == 1 && IsOperator(_PostExression[0]) )  || j%2 == 0 )
    {
        Expression_Flag = false ; 
    }
    *NewSize =  j ;
    return  Expression_Flag ; 

}
float RevesePolishNotation(string _Exression[],uint32_t Size) 
{ 

    stack<float>s1 ; 
    uint32_t j ;
    for( j=0 ; j<Size ; j++) 
    { 
        if(IsNumber(_Exression[j]))
        {
            s1.push( stof(_Exression[j] ) ) ;
        }
        else if(IsOperator(_Exression[j]) ) 
        { 
            float _Num1 ; 
            float _Num2 ; 
            float _Result ; 
            _Num2 = s1.top() ; 
            s1.pop(); 
            _Num1 = s1.top() ; 
            s1.pop(); 
            _Result = Evaluate(_Num1 , _Num2 ,_Exression[j] ); 
            s1.push((_Result)); 
          
        }
       

    } 
    return s1.top(); 
} 
bool IsNumber(string _Number)
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
 
bool IsOperator(string _operator) 
{ 
    bool LocReturn = false ; 
    if(_operator == "+" || _operator == "-" ||  _operator == "*" || _operator == "/") 
    { 
        LocReturn = true; 
 
    } 
    return LocReturn ; 
} 
float Evaluate(float Num1 ,float Num2  , string _operator) 
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

bool priority (string oprator)
{
    bool RetFlag; 
    if(oprator == "+" || oprator =="-") 
        RetFlag= 0; 
 
    if(oprator == "*" || oprator =="/") 
        RetFlag= 1; 

    return RetFlag; 
} 