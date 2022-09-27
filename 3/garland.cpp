#include <bits/stdc++.h>


using namespace std;

double B(int n, double A)
{
    double hi = A;
    double low = 0;
    double B = 0;
    double EPS = 0.00000001;

    while (hi - low > EPS)
    {
        double mid = (hi + low) / 2;

        double prev_lamp = A;
        double curr_lamp = mid;
        double pos_B = 0;
        int ground = 0;

        for (int i = 2; i < n; i++)
        {
            double next_lamp = 2 * curr_lamp + 2 - prev_lamp;
            if (next_lamp == 0)
            {
                ground++;
            }
            if (next_lamp < 0)
            {
              	ground = 2000;
                break;
            }
            prev_lamp = curr_lamp;
            curr_lamp = next_lamp;
            pos_B = next_lamp;
        }

        if (ground <= 1)
        {
            hi = mid;
            B = pos_B;
        }
        else
        {
            low = mid;
        }
    }

    return B;
}


int main()
{
    ifstream input("garland.in");
    ofstream output("garland.out");

    int n = 0;
    double A = 0;

    input >> n >> A;

    output << setprecision(2) << fixed << B(n, A);

    return 0;
}
