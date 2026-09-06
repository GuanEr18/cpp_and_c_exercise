#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

/**
 * 未知数之前的隐式 1，-1 也要加入判断
 */

bool isNum(char c)
{
    return c >= '0' && c <= '9';
}

bool isCase(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool isPositiveSymbol(char c)
{
    if (c == '+')
        return true;
    if (c == '-')
        return false;
    return false;
}

double getResult(const vector<int> &com, const vector<int> &set)
{
    int comSum = 0;
    int setSum = 0;
    for (int i = 0; i < com.size(); i++)
    {
        comSum += com[i];
    }
    for (int i = 0; i < set.size(); i++)
    {
        setSum += set[i];
    }
    return (double)comSum / (double)setSum;
}

int main()
{
    string str;
    getline(cin, str);
    char unknow;
    vector<int> com;
    vector<int> set;
    bool afterEquals = false;
    bool afterPositiveSymbol = true; // 是否在符号之后 默认为正
    for (int i = 0; i < str.length(); i++)
    {
        if (isCase(str[i])) {
            unknow = str[i];
            if (i == 0 || !isNum(str[i - 1])) {
                // 如果前一个字符不是数字，则未知数的系数为1或-1
                if (!afterEquals)
                    set.push_back(afterPositiveSymbol ? 1 : -1);
                else
                    set.push_back(afterPositiveSymbol ? -1 : 1);
            }
            // 如果前一个字符是数字，则已经处理过这个未知数的系数
        }
        else if (str[i] == '+' || str[i] == '-')
            afterPositiveSymbol = isPositiveSymbol(str[i]);
        // 等号之后状态反转
        else if (str[i] == '=')
        {
            afterEquals = true;
            afterPositiveSymbol = true; // 等号之后默认为正
        }
        // 遇到等号前的处理情况
        if (!afterEquals)
        {
            if (isNum(str[i]))
            {
                int temp = 0;
                while (isNum(str[i]) && i < str.length())
                {
                    temp *= 10;
                    temp += str[i] - '0';
                    i++;
                }
                if (isCase(str[i]))
                {
                    unknow = str[i];
                    set.push_back(afterPositiveSymbol ? temp : -temp);
                }
                else
                    com.push_back(afterPositiveSymbol ? -temp : temp);
                i--; // 回退一位 因为for循环还会自增
            }
        }
        // 遇到等号后的处理情况
        else
        {
            if (isNum(str[i]))
            {
                int temp = 0;
                while (isNum(str[i]) && i < str.length())
                {
                    temp *= 10;
                    temp += str[i] - '0';
                    i++;
                }
                if (isCase(str[i]))
                {
                    unknow = str[i];
                    set.push_back(afterPositiveSymbol ? -temp : temp);
                }
                else
                    com.push_back(afterPositiveSymbol ? temp : -temp);
                i--;
            }
        }
    }
    cout << unknow << "=" << fixed << setprecision(3) <<  (abs(getResult(com, set))>=1e-5 ? getResult(com, set) : 0) << endl;
}