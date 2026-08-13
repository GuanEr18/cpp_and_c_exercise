#include <iostream>
#include <vector>
using namespace std;
bool m[4][4];
int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i,j,t;
    string s;
	cin>>s;
	for(i=0;i<s.length();i++)
	{
		t=s[i]-'0'-1;
		m[t/3+1][t%3+1]=i%2==0?0:1;
	}
    for (int i = 1; i <= 3; i++)
    {
        if(m[i][1]==m[i][2]&&m[i][2]==m[i][3])
		{
			if(m[i][1])cout<<"uim wins.\n";
			else cout<<"xiaoa wins.\n";
			return 0;
		}
		if(m[1][i]==m[2][i]&&m[2][i]==m[3][i])
		{
			if(m[1][i])cout<<"uim wins.\n";
			else cout<<"xiaoa wins.\n";
			return 0;
		}
    }
    if(m[1][1]==m[2][2]&&m[2][2]==m[3][3])
	{
		if(m[1][1])cout<<"uim wins.\n";
		else cout<<"xiaoa wins.\n";
		return 0;
	}
	if(m[1][3]==m[2][2]&&m[2][2]==m[3][1])
	{
		if(m[1][3])cout<<"uim wins.\n";
		else cout<<"xiaoa wins.\n";
		return 0;
	}
	cout<<"drew.\n";
	return 0;
}