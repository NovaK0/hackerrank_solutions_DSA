/* This is the problem of hackerrank under the name Balanced Brackets.*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string s) {
	//stack to store and check brackets
    stack<char> ans;
    //string to store answer
    string res;
    //loop to iterate through string
    for(int i=0;i<s.length();i++)
    {
    	//to store opening brackets into the stack
        if(s[i]=='{' || s[i]=='[' || s[i]=='(')
        {
            ans.push(s[i]);
        }
        /* to check for closing bracket and top of the stack if there is match for current closing bracket and 
         top of the stack to be opening bracket then pop. Also check if stack is empty of not*/
        else if(s[i]=='}')
        {
            if(ans.empty())
            {
                ans.push(s[i]);
            }
            else if(ans.top()=='{'){
                ans.pop();
            }
            else{
                 ans.push(s[i]);
            }
        }
        else if(s[i]==']')
        {
            if(ans.empty())
            {
                ans.push(s[i]);
            }
            else if(ans.top()=='['){
                ans.pop();
            }
            else{
                 ans.push(s[i]);
            }
        }
        else if(s[i]==')')
        {
            if(ans.empty())
            {
                ans.push(s[i]);
            }
            else if(ans.top()=='('){
                ans.pop();
            }
            else{
                 ans.push(s[i]);
            }
        }
        
    }
    //if stack is not empty means brackets are not balanced
    if(!ans.empty())
    {
        res="NO";
    }
    else
    {
        res="YES";
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
        cout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

