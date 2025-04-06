// Student ID: 20587063
#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;
bool play_game(int n)
{
    int count = 1;
    string input;
    int x;
    cout << "Welcome to my number guessing game\n\n";
    do
    {
        cout << "Enter your guess: ";
        getline(cin, input);
        istringstream(input) >> x;
        cout << "\nYou entered: " << x << "\n";
        count++;

    } while (x != n && count < 7);

    if (count > 6)
    {
        cout << "I'm sorry. You didn't find my number.\nIt was " << n;
        return false;
    }
    else
    {
        cout << "You found it in " << count - 1 << " guess(es).\n";
        return true;
    }
}
double etox(double x, size_t n)
{
    double res = 1.0;
    double term = 1.0;
    if (n == 0)
    {
        return 0.0;
    }
    if (n == 1)
    {
        return 1.0;
    }

    for (size_t i = 1; i < n; i++)
    {
        term *= (x / i);
        res += term;
    }

    return res;
}
size_t count_chars(string s, char c)
{
    size_t count = 0;

    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == c)
        {
            count++;
        }
    }

    return count;
}
size_t gcd(size_t a, size_t b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
string get_ap_terms(int a, int d, size_t n)
{
    string res = "";
    int seq = a;
    string append;
    for (size_t i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            append = to_string(seq) + ",";
        }
        else
        {
            append = to_string(seq);
        }
        res.append(append);
        seq += d;
    }
    return res;
}
string get_gp_terms(double a, double r, size_t n)
{
    stringstream res;
    double seq = a;
    if (n == 0)
    {
        return res.str();
    }
    if (n == 1)
    {
        res << a;
    }
    else
    {
        res << a << ",";
    }
    for (size_t i = 1; i < n; i++)
    {
        seq *= r;
        if (i == n - 1)
        {
            res << seq;
        }
        else
        {
            res << seq << ",";
        }
    }
    return res.str();
}

double get_nth_fibonacci_number(size_t n)
{
    vector<double> fibo(n+1);
    fibo[0] = 0;
    fibo[1] = 1;
    for (size_t i = 2; i <= n; i++)
    {
        fibo[i] = fibo[i - 1] + fibo[i - 2]; 
    }
    return fibo[n];
}