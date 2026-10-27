#include <iostream>
#include <vector>
using namespace std;

int n;

vector<bool> is_prime(int n)
{
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    return prime;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<int> primes;
    vector<bool> isPrime = is_prime(100005);
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (isPrime[temp])
        {
            primes.push_back(temp);
        }
    }
    for (int i = 0; i < primes.size(); i++)
    {
        cout << primes[i] << " ";
    }
}