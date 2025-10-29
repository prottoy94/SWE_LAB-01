#include <iostream>
#include <string>
using namespace std;

enum State1 { q0_1, q1_1, q2_1, q_dead_1 };
enum State2 { q0_2, q1_2, q2_2, q_dead_2 };
enum State3 { q0_3, q1_3, q_dead_3 };

// FA 1: accepts a(a+b)* + b
bool isAccepted_FA1(const string &input)
{
    if(input.empty())
    {
        return false;
    }
    State1 state = q0_1;
    for(char ch:input)
    {
        switch(state)
        {
            case q0_1:
                if(ch=='a')
                {
                    state=q1_1;
                }
                else if(ch=='b')
                {
                    state=q2_1;
                }
                else
                {
                    state=q_dead_1;
                }
                break;
            case q1_1:
                if(ch=='a'||ch == 'b')
                {
                    state=q1_1;
                }
                else
                {
                    state=q_dead_1;
                }
                break;
            case q2_1:
                if(ch=='a'||ch=='b')
                {
                    state=q_dead_1;
                }
                break;
            case q_dead_1:
                break;
        }
    }
    return (state==q1_1||state==q2_1);
}

// FA 2: accepts a(a+b)* + b*
bool isAccepted_FA2(const string &input)
{
    State2 state = q0_2;
    for(char ch : input)
    {
        switch(state)
        {
            case q0_2:
                if(ch=='a')
                {
                    state=q1_2;
                }
                else if(ch=='b')
                {
                    state=q2_2;
                }
                else
                {
                    state=q_dead_2;
                }
                break;
            case q1_2:
                if(ch=='a'||ch=='b')
                {
                    state=q1_2;
                }
                else
                {
                    state=q_dead_2;
                }
                break;
            case q2_2:
                if(ch == 'b')
                {
                    state = q2_2;
                }
                else
                {
                    state = q_dead_2;
                }
                break;
            case q_dead_2:
                break;
        }
    }
    return (state == q0_2 || state == q1_2 || state == q2_2);
}

// FA 3: accepts a(a+b)*
bool isAccepted_FA3(const string &input)
{
    State3 state = q0_3;
    for(char ch : input)
    {
        switch(state)
        {
            case q0_3:
                if(ch == 'a')
                {
                    state = q1_3;
                }
                else
                {
                    state = q_dead_3;
                }
                break;
            case q1_3:
                if(ch == 'a' || ch == 'b')
                {
                    state = q1_3;
                }
                else
                {
                    state = q_dead_3;
                }
                break;
            case q_dead_3:
                break;
        }
    }
    return (state == q1_3);
}

int main()
{
    string input;
    cout << "Enter a string over {a, b}: ";
    getline(cin, input);

    bool accepted1 = isAccepted_FA1(input);
    bool accepted2 = isAccepted_FA2(input);
    bool accepted3 = isAccepted_FA3(input);

    cout<<"\nResult:\n";
    if(accepted1)
    {
        cout<<" Accepted by FA1: a(a+b)* + b\n";
    }
    else
    {
        cout<<" Rejected by FA1: a(a+b)* + b\n";
    }

    if(accepted2)
    {
        cout<<" Accepted by FA2: a(a+b)* + b*\n";
    }
    else
    {
        cout<<" Rejected by FA2: a(a+b)* + b*\n";
    }

    if(accepted3)
    {
        cout << " Accepted by FA3: a(a+b)*\n";
    }
    else
    {
        cout << " Rejected by FA3: a(a+b)*\n";
    }

    return 0;
}
