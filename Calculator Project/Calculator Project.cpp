#include<iostream>
#include<cmath>
#include<math.h>
#include<string>
#include<strings.h>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<stdlib.h>
#include<windows.h>
using namespace std;
typedef long double LL;
const long long int MOD = 1e9+7;
const long double PI = 3.141592653589793;
const long double E = 2.718281828459045;
long long int dp[150];

bool myLetter(char c);
long long int getFactorial(long long int x);
LL transformLL(string s);
LL startAlgorithm(string s,int &check,int flag,LL last);
string fixString(string s,int &cnt);
bool isOperator(char c);
int Priority(char c);

struct stack{
    LL Number;
    char Character;
    stack* next;
    stack* top;

    stack(){
        next=NULL;
        top=NULL;
    }

    void pushChar(char c)
    {
        stack* newStack = new stack();
        newStack->Character=c;
        newStack->next=top;
        top=newStack;
        return;
    }

    void pushLL(LL x)
    {
        stack* newStack = new stack();
        newStack->Number=x;
        newStack->Character='&';
        newStack->next=top;
        top=newStack;
        return;
    }

    char popChar()
    {
        stack* p;
        p=top;
        top=top->next;
        char x=p->Character;
        delete p;
        return x;
    }

    LL popLL()
    {
        stack* p;
        p=top;
        top=top->next;
        LL x=p->Number;
        delete p;
        return x;
    }

    LL getTopLL()
    {
        return top->Number;
    }

    char getTopChar()
    {
        return top->Character;
    }

    bool isEmpty()
    {
        if(top!=NULL)
            return false;
        return true;
    }
};

int main()
{
    string s;

    int c=0;

    LL last=0;

    memset(dp,-1,sizeof(dp));

    while(1)
    {
        int check,cnt,flag;

        if(c)
            cout<<"Enter an expression in infix form or write 'END' to exit the program."<<endl<<endl;

        else
            cout<<"Enter 1 to use Degrees, 2 to use Radians\n\n";

        getline(cin,s);

        cout<<endl;

        size_t end=s.find("END");
        if(s=="1" and !c)
        {
            flag=1;
            system("cls");
            c++;
            continue;
        }
        else if(s=="2" and !c)
        {
            c++;
            flag=0;
            system("cls");
            continue;
        }

        if(end!=string::npos)
            return 0;

        if (s.empty())
        {
            c++;
            system("cls");
            continue;
        }

        s=fixString(s,cnt);

        LL answer=startAlgorithm(s,check,flag,last);

        (check!=0)?cout<<"Sorry but it seems that the expression is not correct."<<endl<<endl:
                        cout<<s<<" = "<<setprecision(15)<<answer<<endl<<endl;

        last=answer;
    }
}

string fixString(string s,int &cnt)
{
    // REMOVE SPACES
    for(int i=0;i<s.size();i++)
        if(isspace(s[i]))
            s.erase(s.begin()+i),i--;

    if(s[0]=='-')
        s.insert(s.begin(),'0');
    // REMOVE EQUAL SIGN
    if(s[s.size()-1]=='=')
        s.erase(s.end()-1);

    int minus,j;
//-++-123+123(123*2133 ) =
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='+' and isdigit(s[i+1]) and s[i-1]==')')
            continue;

        if(s[i]=='e' and s[i+1]!='^')
            s.insert(s.begin()+i+1,'^');

        if(s[i]=='-' or s[i]=='+')
        {
            minus=0;
            for(j=i;s[j]=='-' or s[j]=='+';j++)
                if(s[j]=='-')
                    minus++;
            s.erase(s.begin()+i,s.begin()+j-1);
            cout<<i<<" " <<s<<endl;
            if(minus%2)
            {
                if(s[i-1]=='*' or s[i-1]=='^' or s[i-1]=='/'){
                    s[i]='(';
                    i++;
                    s.insert(s.begin()+i,'-');
                    for(j=i+1;(isalpha(s[j]) or isdigit(s[j])) and j<s.size() or s[j]=='.';j++);
                    s.insert(s.begin()+j,')');
                }
                else if(isdigit(s[i-1]) or s[i-1]=='!' or s[i-1]=='%')
                    s[i]='-';
            }
            if(!(minus%2))
            {
                if((s[i]=='-' or s[i]=='+'))
                    s[i]='+';
                if(isOperator(s[i-1]) or i-1<0)
                    s.erase(s.begin()+i);
            }
        }

        if(isdigit(s[i]) and myLetter(s[i+1]))
            s.insert(s.begin()+i+1,'*');
    }

    for(int i=0;i<s.size();i++)
        if(s[i]=='(' and s[i+1]=='-')
            s.insert(s.begin()+i+1,'0');

    for(int i=0;i<s.size();i++)
        if((isdigit(s[i]) and s[i+1]=='(') or (s[i]==')' and s[i+1]=='(') or (s[i]==')' and isdigit(s[i+1])))
            s.insert(s.begin()+i+1,'*');
        else if((s[i]=='!' or s[i]=='%') and s[i+1]=='(')
            s.insert(s.begin()+i+1,'*');
        else if(s[i]=='!' and isdigit(s[i+1]))
            s.insert(s.begin()+i+1,'*');

    if(s[0]=='-')
        s.insert(s.begin(),'0');

    return s;
}

bool myLetter(char c)
{
    if(c=='s' or c=='c' or c=='t' or c=='e' or c=='P')
        return true;
    return false;
}

bool isOperator(char c)
{
    if(c=='/' or c=='*' or c=='+' or c=='-' or c=='^' or c=='(' or c==')' or c=='!' or c=='%' or c=='=')
        return true;
    return false;
}

int Priority(char c)
{
    if(c=='-' or c=='+')
        return 0;
    if(c=='/' or c=='*')
        return 1;
    if(c=='^')
        return 2;
}

LL transformLL(string s)
{
    LL ans=0;
    int n=s.size();
    for(int i=0;i<n;i++)
        ans=(ans*10+(s[i]-'0'));
    return ans;
}

long long int getFactorial(long long int x)
{
    if(x<=1)
        return 1;
    long long int &ret=dp[x];
    if(~ret)
        return ret;
    return ret=x*getFactorial(x-1);
}

LL startAlgorithm(string s,int &check,int flag,LL last)
{
    stack postfix;
    stack operators;

    if(flag!=0 and flag!=1)
        flag=1;

    size_t found = s.find('.');

    check=0;

    string go;
    LL x;


    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='=')
            break;

        else if(s[i]=='a' and s[i+1]=='n' and s[i+2]=='s')
            postfix.pushLL(last);

        else if(s[i]=='e')
            postfix.pushLL(E);

        else if(s[i]=='%')
        {
            x = postfix.popLL()/100;
            postfix.pushLL(x);
        }

        else if(s[i]=='!')
        {
            long long int h = getFactorial((long long int)postfix.popLL());
            postfix.pushLL((LL)h);
        }

        else if(s[i]=='P' and s[i+1]=='I')
            postfix.pushLL(PI);

        else if(s[i]=='t' and s[i+1]=='a')
        {
            go.clear();
            i+=3;
            while(!isOperator(s[i]) and i<s.size())
            {
                go+=s[i];
                i++;
            }
            i--;
            if(found!=string::npos)
                x = atof(go.c_str());
            else
                x = transformLL(go);
            (flag)?postfix.pushLL(tanl(x*PI/180)):postfix.pushLL(tanl(x));
        }

        else if(s[i]=='c' and s[i+1]=='o')
        {
            go.clear();
            i+=3;
            while(!isOperator(s[i]) and i<s.size())
            {
                go+=s[i];
                i++;
            }
            i--;
            if(found!=string::npos)
                x = atof(go.c_str());
            else
                x = transformLL(go);
            (flag)?postfix.pushLL(cosl(x*PI/180)):postfix.pushLL(cosl(x));
        }

        else if(s[i]=='s' and s[i+1]=='i' and s[i+2]=='n')
        {
            go.clear();
            i+=3;
            while(!isOperator(s[i]) and i<s.size())
            {
                go+=s[i];
                i++;
            }
            i--;
            if(found!=string::npos)
                x = atof(go.c_str());
            else
                x = transformLL(go);
            (flag)?postfix.pushLL(sinl(x*PI/180)):postfix.pushLL(sinl(x));
        }

        else if(s[i]=='s' and s[i+1]=='q')
        {
            go.clear();
            i+=4;
            while(!isOperator(s[i]) and i<s.size())
            {
                go+=s[i];
                i++;
            }
            i--;
            if(found!=string::npos)
                postfix.pushLL(sqrtl(atof(go.c_str())));
            else
            {
                x = transformLL(go);
                postfix.pushLL(sqrtl(x));
            }
        }

        else if(isdigit(s[i]))
        {
            go.clear();
            while(!isOperator(s[i]) and i<s.size())
            {
                go+=s[i];
                i++;
            }
            i--;
            if(found!=string::npos)
                postfix.pushLL(atof(go.c_str()));
            else
                postfix.pushLL(transformLL(go));
        }

        else if(isOperator(s[i]))
        {
            if(!operators.isEmpty())
            {
                if(s[i]=='(')
                    operators.pushChar(s[i]),check++;
                else if(s[i]==')')
                {
                    check--;
                    while(operators.getTopChar()!='(')
                        postfix.pushChar(operators.popChar());
                    operators.popChar();
                }
                else
                {
                    while(!operators.isEmpty() and operators.getTopChar()!='(' and Priority(s[i])<=Priority(operators.getTopChar()))
                        postfix.pushChar(operators.popChar());
                    operators.pushChar(s[i]);
                }
            }
            else
            {
                operators.pushChar(s[i]);
                if(s[i]=='(')   check++;
                else if(s[i]==')')  check--;
            }
        }
        if(check<0)
            break;
    }

    if(check)
        return 0;

    while(!operators.isEmpty())
        postfix.pushChar(operators.popChar());

    stack POSTFIX;
    stack NUMBERS;
    stack DISPLAY;

    while(!postfix.isEmpty())
    {
        if(postfix.getTopChar()!='&')
        {
            POSTFIX.pushChar(postfix.getTopChar());
            DISPLAY.pushChar(postfix.getTopChar());
            postfix.popChar();
        }
        else
        {
            POSTFIX.pushLL(postfix.getTopLL());
            DISPLAY.pushLL(postfix.getTopLL());
            postfix.popLL();
        }
    }

    cout<<"The Postfix Expression for the input is: ";
    while(!DISPLAY.isEmpty())
        (DISPLAY.getTopChar()!='&')?cout<<DISPLAY.popChar()<<" ":cout<<DISPLAY.popLL()<<" ";
    cout<<" ,"<<endl<<endl;

    LL a,y;

    while(!POSTFIX.isEmpty())
    {
        if(POSTFIX.getTopChar()=='&')
            NUMBERS.pushLL(POSTFIX.popLL());
        else
        {
            a=NUMBERS.popLL();
            y=NUMBERS.popLL();
            if(POSTFIX.getTopChar()=='+')
                NUMBERS.pushLL(y+a);
            if(POSTFIX.getTopChar()=='-')
                NUMBERS.pushLL(y-a);
            if(POSTFIX.getTopChar()=='^')
                NUMBERS.pushLL(powl(y,a));
            if(POSTFIX.getTopChar()=='/')
                NUMBERS.pushLL(y/a);
            if(POSTFIX.getTopChar()=='*')
                NUMBERS.pushLL(a*y);
            POSTFIX.popChar();
        }
    }

    return NUMBERS.popLL();
}
