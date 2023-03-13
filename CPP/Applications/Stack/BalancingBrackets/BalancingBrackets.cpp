#include <stack>
#include <bits/stdc++.h>
using namespace std;
bool bracketMatching(string given_string)
{bool flag=1;
    stack<char>Stack;
  for(int i=0;i<given_string.length();i++)
  {
      if(given_string[i]=='{'||given_string[i]=='('||given_string[i]=='[')
        {
           Stack.push(given_string[i]);
        }
       else
       {if (Stack.empty())
       {
           flag=0;
           break;
       }

        if(given_string[i]=='}'&&Stack.top()=='{'||given_string[i]==']'&&Stack.top()=='['||given_string[i]==')'&&Stack.top()=='(')
            {
                Stack.pop();
            }
            else
            {
                flag=0;
                break;
            }
       }

  }
  if(Stack.empty()==0)
  {
      flag=0;
  }
  return flag;
}
