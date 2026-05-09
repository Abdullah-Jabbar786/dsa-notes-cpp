#include <iostream>
#include <string>
using namespace std;

class Stack{
    char arr[100];
    int top;
    public:
    Stack() { top = -1; }
    
    void push(char c) { arr[++top] = c; }
    char pop() { return arr[top--]; }
    char peek() { return arr[top]; }
    bool isEmpty() { return top == -1; }
};

int precedence(char c){
    if(c=='^') return 3;
    if(c=='*' || c=='/') return 2;
    if(c=='+' || c=='-') return 1;
    return -1;
}

// Infix to Postfix
string infixToPostfix(string s){
    Stack st;
    string result = "";

    for(int i=0; i<s.length(); i++){
        char c = s[i];

        if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
            result += c;

        else if(c=='(')
            st.push(c);

        else if(c==')') {
            while(!st.isEmpty() && st.peek()!='(') {
                result += st.pop();
            }
            if(!st.isEmpty()) st.pop();
        }

        else {
            while(!st.isEmpty() && precedence(c) <= precedence(st.peek())) {
                result += st.pop();
            }
            st.push(c);
        }
    }

    while(!st.isEmpty()) {
        result += st.pop();
    }

    return result;
}

string reverseString(string s) {
    int n = s.length();
    for(int i=0; i<n/2; i++) {
        char temp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = temp;
    }
    return s;
}

// Infix to Prefix
string infixToPrefix(string s) {
    s = reverseString(s);

    for(int i=0; i<s.length(); i++) {
        if(s[i]=='(') s[i]=')';
        else if(s[i]==')') s[i]='(';
    }

    string postfix = infixToPostfix(s);
    postfix = reverseString(postfix);
    return postfix;
}

int main()
{
    string infix;
    cout<<"Enter infix expression: ";
    cin>>infix;
    cout<<"Prefix: "<<infixToPrefix(infix)<<endl;
    cout<<"Postfix: "<<infixToPostfix(infix)<<endl;

    return 0;
}