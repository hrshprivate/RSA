#include<iostream>
#include<math.h>

using namespace std;

long int p, q, n, t, flag, e, d, temp[100], j, m[100], en[100], i;
char msg[100];

int primeNumber(long int pr)
{
    int i;
    j = sqrt(pr);
    for (i = 2; i <= j; i++)
    {
        if (pr % i == 0)
            return 0;
    }
    return 1;
}
long int calculateD(long int x)
{
    long int k = 1;
    while (1)
    {
        k = k + t;
        if (k % x == 0)
            return (k / x);
    }
}
void  calculateE()
{
    for (i = 2; i < t; i++)
    {
        if (t % i == 0)
            continue;
        flag = primeNumber(i);
        if (flag == 1 && i != p && i != q)
        {
            e = i;
            flag = calculateD(e);
            if (flag > 0)
            {
                d = flag;
            }
        }
    }
}

void encrypt()
{
    long int pt, ct, key = e, k, len;
    i = 0;
    len = strlen(msg);
    while (i != len)
    {
        pt = m[i];
        pt = pt - 96;
        k = 1;
        for (j = 0; j < key; j++)
        {
            k = k * pt;
            k = k % n;
        }
        temp[i] = k;
        ct = k + 96;
        en[i] = ct;
        i++;
    }
    en[i] = -1;
    cout << "Зашифрованое сообщение: " << endl;
    for (i = 0; en[i] != -1; i++)
        cout << (char)en[i];
}
void decrypt()
{
    long int pt, ct, key = d, k;
    i = 0;
    while (en[i] != -1)
    {
        ct = temp[i];
        k = 1;
        for (j = 0; j < key; j++)
        {
            k = k * ct;
            k = k % n;
        }
        pt = k + 96;
        m[i] = pt;
        i++;
    }
    m[i] = -1;
    cout << "Расшифрованое сообщение: " << endl;
    for (i = 0; m[i] != -1; i++)
        cout << (char)m[i];
}
int main()
{
    setlocale(0, "");
    cout << "Введите первое число: " << endl;
    cin >> p;
    flag = primeNumber(p);
    if (flag == 0)
    {
        cout << "Неверный ввод! " << endl;
        exit(1);
    }
    cout << "Введите второе число: " << endl;
    cin >> q;
    flag = primeNumber(q);
    if (flag == 0 || p == q)
    {
        cout << "Неверный ввод! " << endl;
        exit(1);
    }
    cout << "Введите сообщение! " << endl;
    cin.ignore();
    cin >> msg;
    for (i = 0; msg[i] != '\0'; i++)
        m[i] = msg[i];
    n = p * q;
    t = (p - 1) * (q - 1);
    calculateE();
    cout << "Возможные значения e , d: " << endl;
        cout << e << "\t" << d <<'\t';
        cout << endl;
    encrypt();
    cout << endl;
    decrypt();
    cout << endl;
    system("pause");
    return 0;
}
