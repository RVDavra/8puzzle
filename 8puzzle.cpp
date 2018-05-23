#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
typedef struct dataset
{
    string s;
    int heuristic;
}dataset;
ofstream fout("output.txt");
int isThisMatch(string a,string b)
{
    char a1='9',b1='9';
    for(int i=0;i<9;i++)
    {
        if(a[i]!=b[i])
        {
            if(a[i]=='_')
                b1=b[i];
            else if(b[i]=='_')
                a1=a[i];
            else
                return 0;
        }
    }
    if(a1!=9 && b1!=9 && a1==b1)
        return 1;
    else
        return 0;
}
int countHeauristic(string a)
{
    string main = "12345678_";
    int count = 0;
    for(int i=0;i<main.length();i++)
        if(a[i]!=main[i])
            count++;
    return count;
}
string moveUp(string s)
{
    int index;
    for(int i=0;i<9;i++)
        if(s[i]=='_')
            index = i;
    if(index/3 == 0)
        return s;
    else{
        int bi=index-3;
        string temp=s;
        char c=temp[bi];
        temp[bi]=temp[index];
        temp[index]=c;
        return temp;
    }
}
string moveDown(string s)
{
    int index;
    for(int i=0;i<9;i++)
        if(s[i]=='_')
            index = i;
    if(index/3 == 2)
        return s;
    else{
        int bi=index+3;
        string temp=s;
        char c=temp[bi];
        temp[bi]=temp[index];
        temp[index]=c;
        return temp;
    }
}
string moveLeft(string s)
{
    int index;
    for(int i=0;i<9;i++)
        if(s[i]=='_')
            index = i;
    if(index%3 == 0)
        return s;
    else{
        int bi=index-1;
        string temp=s;
        char c=temp[bi];
        temp[bi]=temp[index];
        temp[index]=c;
        return temp;
    }
}
string moveRight(string s)
{
    int index;
    for(int i=0;i<9;i++)
        if(s[i]=='_')
            index = i;
    if(index%3 == 2)
        return s;
    else{
        int bi=index+1;
        string temp=s;
        char c=temp[bi];
        temp[bi]=temp[index];
        temp[index]=c;
        return temp;
    }
}
void printState(string s)
{
    fout<<s[0]<<s[1]<<s[2]<<endl;
    fout<<s[3]<<s[4]<<s[5]<<endl;
    fout<<s[6]<<s[7]<<s[8]<<endl<<endl;
}

int main()
{
    vector<string> visited;
    int h;
    //input string
    string ps="_12345678";
    h = countHeauristic(ps);
    visited.push_back(ps);
    printState(ps);
    while(h!=0){
        vector<dataset> moves;
        string mu = moveUp(ps);
        string md = moveDown(ps);
        string ml = moveLeft(ps);
        string mr = moveRight(ps);
        if(find(visited.begin(),visited.end(),mu)==visited.end())  moves.push_back({mu,countHeauristic(mu)});
        if(find(visited.begin(),visited.end(),md)==visited.end())  moves.push_back({md,countHeauristic(md)});
        if(find(visited.begin(),visited.end(),ml)==visited.end())  moves.push_back({ml,countHeauristic(ml)});
        if(find(visited.begin(),visited.end(),mr)==visited.end())  moves.push_back({mr,countHeauristic(mr)});
        int min=0;
        for(int i=0;i<moves.size();i++)
        {
            if(moves[min].heuristic>moves[i].heuristic)
                min=i;
        }
        ps = moves[min].s;
        h = countHeauristic(ps);
        printState(ps);
        visited.push_back(ps);
    }
}
