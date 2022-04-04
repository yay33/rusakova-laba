#include <iostream>
#include <cmath>
using namespace std;

long long factorial1(long long n) {
    long long f = 1;
    for (long long i = 2; i <= n; i++) {
        f *= i;
    }
    return f;
}

int main()
{
    long n = 2, m = -1;
    double ψ(0), pk(1), firstpart(0), PO, sum, secondpart, ρ(1.8),α(0.03),a(1);
    
    for (n; n < 5; n++) {
        m = -1, pk = 1, sum = 1, a = 1;
        ψ = ρ / n;
        
        for (int i = 1; i <= n; i++) {
            a = a * n / i * ψ;
            sum += a;
        }

        double pks = 2;
       
        secondpart = pow(n, n) / factorial1(n) * pow(ψ, n + 1) / (1 - ψ);
        firstpart = pow(n, n) / factorial1(n) * pow(ψ, n - 1);

        while (pk > α && (abs(pk - pks) > 0.0000001)) {
            pks = pk;
            m++;
            PO = 1 / (sum + secondpart * (1 - pow(ψ, m)));
            firstpart *= ψ;
            pk = firstpart * PO;
        }
        if (abs(pk - pks) > 0.0000001) {
            cout << "n = " << n << " m = " << m << endl;
        }
        else
            cout << "n = " << n << " m = inf " << endl;
    }
    
}


