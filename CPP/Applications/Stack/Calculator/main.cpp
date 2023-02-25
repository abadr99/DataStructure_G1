#include <iostream>
#include<stack>
#include<string>
using namespace std ; 
float RevesePolishNotation(uint8_t _Exression[]);
bool IsOperator(uint8_t _operator);
bool IsNumber(uint8_t _Number);
float Evaluate(float Num1 ,float Num2  , uint8_t _operator);
int main() 
{
    //45+43+* --> (5+4)*(4+3) = 63
    //a b c − = * d + = --> (a * (b − c)) + d. 
    //421-=*6+= --> (4 * (2 - 1 ))+ 6 = 10
    uint8_t Expression[50] ;  
    cout<< "Enter Expression : ";
    cin>>Expression;
    
    cout<<"The result is "<< RevesePolishNotation(Expression) <<endl;
}
float RevesePolishNotation(uint8_t _Exression[])
{
    stack<float>s1 ; 
    uint32_t i = 0 ;
    while(_Exression[i]!='\0')
    {
        if(_Exression[i] == '=')
        {

            cout<< s1.top() <<endl ; 

        }
        else if( IsNumber(_Exression[i]) )
        {
   
           s1.push(_Exression[i] - '0') ; 

        }else if( IsOperator(_Exression[i]) )
        {
            float _Num1 ;
            float _Num2 ; 
            float _Result ;
            _Num2 = s1.top() ;
            s1.pop();
            _Num1 = s1.top() ;
            s1.pop();
            _Result = Evaluate(_Num1 , _Num2 ,_Exression[i] );
            s1.push((_Result));

        }else
        {
            cout<<"Wrong expression...\n";
        }
        i++;
    }
    return s1.top();
}
bool IsOperator(uint8_t _operator)
{
    bool LocReturn = false ; 
    if(_operator == '+' || _operator == '-' || _operator == '*' || _operator == '/') 
    {
        LocReturn = true;
    } 
    return LocReturn ; 
}

bool IsNumber(uint8_t _Number)
{
    bool LocReturn = false ; 
    if(_Number>='0' && _Number<='9') 
    {
        LocReturn = true;
    } 
    return LocReturn ; 
}
float Evaluate(float Num1 ,float Num2  , uint8_t _operator)
{
    float Ret_Result ;
    switch(_operator)
    {
        case '+': Ret_Result = Num1 + Num2 ; break;
        case '-': Ret_Result = Num1 - Num2 ; break;
        case '*': Ret_Result = Num1 * Num2 ; break;
        case '/': Ret_Result = Num1 / Num2 ; break;
    }
    return Ret_Result ; 
}