#include <iostream>
#include <string>
using namespace std;

enum State {q0,q1,q_dead};

bool isAccepted(const string &input)
{
    State state=q0;
    for(char ch:input)
    {
        if(state==q0)
        {
            if(ch=='a')
            {
                state=q1;
            }
            else
            {
                state=q_dead;
            }
        }
        else if(state==q1)
        {
            if(ch=='a'||ch=='b')
            {
                state=q1;
            }
            else
            {
                state=q_dead;
            }
        }
        else if(state==q_dead)
        {
            state=q_dead;
        }
    }
    if(state==q1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string input;
    cout<<"Enter a string over {a,b}: ";
    getline(cin,input);
    if(isAccepted(input))
    {
        cout<<"String ACCEPTED by the FA (matches a(a+b)*)."<<endl;
    }
    else
    {
        cout<<"String REJECTED by the FA."<<endl;
    }
    return 0;
}
