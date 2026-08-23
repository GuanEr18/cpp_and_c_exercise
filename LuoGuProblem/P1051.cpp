#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct student
{
    string name;
    int score = 0;
    int classScore = 0;
    bool set;
    bool western;
    int paper = 0.;
};
int n;
char c1, c2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<student> students(n);
    for (int i = 0; i < students.size(); i++)
    {
        cin >> students[i].name >> students[i].score >> students[i].classScore >> c1 >> c2 >> students[i].paper;
        if (c1 == 'Y')
            students[i].set = true;
        else
            students[i].set = false;
        if (c2 == 'Y')
            students[i].western = true;
        else
            students[i].western = false;
    }
    int temp = -1, number;
    long long sum = 0;
    for (size_t i = 0; i < students.size(); i++)
    {
        int bounce = 0;
        if (students[i].score > 80 && students[i].paper >= 1)
        {
            bounce += 8000;
        }
        if (students[i].score > 85 && students[i].classScore > 80)
        {
            bounce += 4000;
        }
        if (students[i].score > 90)
        {
            bounce += 2000;
        }
        if (students[i].western && students[i].score > 85)
        {
            bounce += 1000;
        }
        if (students[i].set && students[i].classScore > 80)
        {
            bounce += 850;
        }
        sum += bounce;
        // 这里不用等于号式因为题目要求奖学金相同时输出排名靠前的人
        if (temp < bounce)
        {
            number = i;
            temp = bounce;
        }
    }
    cout << students[number].name << endl
         << temp << endl
         << sum << endl;
    return 0;
}