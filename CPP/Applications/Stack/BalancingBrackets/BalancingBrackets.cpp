#include <stack>
#include <bits/stdc++.h>
using namespace std;
bool bracketMatching(string ss)
{bool f=1;
    stack<char>s;
  for(int i=0;i<ss.length();i++)
  {
      if(ss[i]=='{'||ss[i]=='('||ss[i]=='[')
        {
           s.push(ss[i]);
        }
       else
       {if (s.empty())
       {
           f=0;
           break;
       }

        if(ss[i]=='}'&&s.top()=='{'||ss[i]==']'&&s.top()=='['||ss[i]==')'&&s.top()=='(')
            {
                s.pop();
            }
            else
            {
                f=0;
                break;
            }
       }

  }
  if(s.empty()==0)
  {
      f=0;
  }
  return f;
}
