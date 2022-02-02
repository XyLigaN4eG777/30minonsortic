#include <vector>
#include <iostream>

using namespace std;

long itc_len(string str) {
    int i = 0;
    while (str[i] != '\0'){
        i += 1;
    }
    return i;
}

long long itc_abs(long long num){
    if (num >= 0) return num;
    return -num;
}

double itc_pow(long long num, long long n){
    if (n == 0) return 1;
    long long res = num;
    for (int i=1; i < itc_abs(n); i++){
        res *= num;
    }
    if (n >= 0) return res;
    return 1.0 / res;
}

void ra(vector <int> &mass) {
    if (mass.size() != 0){
        vector <int> mass2(mass.size());
        mass2[mass2.size() - 1] = mass[0];
        for (int i = 0; i < mass.size() - 1; i++)
            mass2[i] = mass[i + 1];
        mass = mass2;
    }
}

void pa(vector <int> &a, vector <int> &b) {
    int num = b[0];
    vector <int> newB;
    for (int i = 1; i < b.size(); i++) newB.push_back(b[i]); // 3
    b = newB;
    a.push_back(num);
    ra(a);
}


void pb(vector <int> &a, vector <int> &b) {
    int num = a[0];
    vector <int> newa;
    for (int i = 1; i < a.size(); i++) newa.push_back(a[i]);
    a = newa;
    b.push_back(num);
    ra(b);
}
int trans(string s) {
    int num = 0;
    for (int i = 0; i < itc_len(s); i++) {
        num += (int(s[i]) - 48) * itc_pow(10, itc_len(s) - i - 1);
    }
    return num;
}
void print(vector <int> &a, vector <int> &b, string f)
{
    for (int i = 0; i < 100; i++) cout << "~";
    cout << endl << f << endl;
    cout << "a:" << endl;
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << endl;
    cout << "b:" << endl;
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << endl;
}
int main()
{
    string p;
    getline(cin, p);
    p = p + " ";
    int l = itc_len(p);
    int i = 0;
    string pus = "";
    string g;
    g = p[i];
    vector <string> a_string;
    while(i != l){
        g = p[i];
        if((g == "1") || (g == "2") || (g == "3") || (g == "4") || (g == "5") || (g == "6") || (g == "7") || (g == "8") || (g == "9") || (g == "0"))
        {
            pus += g;
            i++;
        }
        else{
            a_string.push_back(pus);
            pus = "";
            i++;

        }
    }
    vector <int> a;
    for (int i = 0; i < a_string.size(); i++)
    {
        string j = a_string[i];
        int k = trans(j);
        a.push_back(k);
    }
    vector <int> b;
    string f = "start";
    print(a, b, f);
    int c;
    int z;
    int n = 0;
    while(a.size() != 1){
        while(c != a.size())
        {
            ra(a);
            f = "ra";
            print(a, b, f);
            z = a[n];
            c = 0;
            for (int k = 0; k < a.size(); k++)
            {
                if(z >= a[k])
                    c += 1;
            }

        }
        pb(a, b);
        int pop = b.size() - 1;
        while(pop > 0)
        {
            ra(a);
            pop -= 1;
        }
        f = "pb";
        print(a, b, f);}
    while(b.size() != 0)
    {
        while(c != b.size())
        {
            ra(b);
            f = "rb";
            print(a, b, f);
            z = b[n];
            c = 0;
            for (int k = 0; k < b.size(); k++)
            {
                if(z <= b[k])
                    c += 1;
            }

        }
        pa(a, b);
        int pop = a.size() - 1;
        while(pop > 0)
        {
            ra(a);
            pop -= 1;
        }
        f = "pa";
        print(a, b, f);}

    return 0;
    }
