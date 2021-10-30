#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mods = 1e9 + 7;

ll priority(char op)
{
  if (op == '+' || op == '-')
  {
    return 1;
  }
  else if (op == '*' || op == '/')
  {
    return 2;
  }
  return 0;
}

ll exec(ll a, ll b, char op)
{
  switch (op)
  {
  case '+':
    return (a + b) % mods;
  case '-':
    return (a - b + mods) % mods;
  case '*':
    return ((ll)a * b) % mods;
  case '/':
    return a / b;
  }
  return 0;
}

int eval(string s)
{
  int i = 0;
  stack<char> ops;
  stack<ll> vals;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == ' ')
    {
      continue;
    }
    if (s[i] == '(')
    {
      ops.push(s[i]);
    }
    else if (isdigit(s[i]))
    {
      ll val = 0;
      while (isdigit(s[i]) && i < s.length())
      {
        val = (10 * val) + (s[i] - '0');
        i++;
      }
      vals.push(val);
      --i;
    }
    else if (s[i] == ')')
    {
      while (!ops.empty() && ops.top() != '(')
      {
        ll val_b = vals.top();
        vals.pop();
        ll val_a = vals.top();
        vals.pop();
        char operation = ops.top();
        ops.pop();
        vals.push(exec(val_a, val_b, operation));
      }
      if (!ops.empty())
      {
        ops.pop();
      }
    }
    else
    {
      while (!ops.empty() && priority(ops.top()) >= priority(s[i]))
      {
        ll val_b = vals.top();
        vals.pop();
        ll val_a = vals.top();
        vals.pop();
        char operation = ops.top();
        ops.pop();
        vals.push(exec(val_a, val_b, operation));
      }
      ops.push(s[i]);
    }
  }
  while (!ops.empty())
  {
    ll val_b = vals.top();
    vals.pop();
    ll val_a = vals.top();
    vals.pop();
    char operation = ops.top();
    ops.pop();
    vals.push(exec(val_a, val_b, operation));
  }

  return vals.top();
}
int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    string str;
    cin >> str;
    char ops[3] = {'+', '-', '*'};
    bool valid = true;
    int str_size = str.size();
    int op_string[str_size];
    memset(op_string, 0, sizeof(op_string));
    for (int i = 0; i < str_size; i++)
    {
      for (int j = 0; j < 3; j++)
      {
        if (str[i] == ops[j])
        {
          op_string[i] = 1;
        }
      }
    }

    stack<char> parentheses;
    for (int i = 0; i < str_size - 1; i++)
    {
      if (str[i] == '(' || str[i] == ')')
      {
        if (str[i] == ')')
        {
          if (!parentheses.empty())
          {
            parentheses.pop();
          }
          else
          {
            valid = false;
            break;
          }
        }
        if (str[i] == '(')
        {
          parentheses.push(str[i]);
        }
      }
      if (op_string[i] && op_string[i + 1])
      {
        valid = false;
        break;
      }
      if (str[i] == '(' && str[i + 1] == ')')
      {
        valid = false;
        break;
      }
      if (op_string[i] && str[i + 1] == ')')
      {
        valid = false;
        break;
      }
      if (op_string[i + 1] && str[i] == '(')
      {
        valid = false;
        break;
      }
      if (isdigit(str[i + 1]) && str[i] == ')')
      {
        valid = false;
        break;
      }
      if (isdigit(str[i]) && str[i + 1] == '(')
      {
        valid = false;
        break;
      }
      if (str[i] == ')' && str[i + 1] == '(')
      {
        valid = false;
        break;
      }
    }

    if (str[0] == ')' || str[str_size - 1] == '(')
    {
      valid = false;
    }

    if (str[str_size - 1] == '(' || str[str_size - 1] == ')')
    {
      if (str[str_size - 1] == ')')
      {
        if (!parentheses.empty())
        {
          parentheses.pop();
        }
        else
        {
          valid = false;
        }
      }
      if (str[str_size - 1] == '(')
      {
        parentheses.push(str[str_size - 1]);
      }
    }

    if (!parentheses.empty())
    {
      valid = false;
    }

    if (op_string[0] || op_string[str_size - 1])
    {
      valid = false;
    }
    if (!valid)
    {
      cout << "invalid" << endl;
      continue;
    }
    cout << eval(str) << endl;
  }
}