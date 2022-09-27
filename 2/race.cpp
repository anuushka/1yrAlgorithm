#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct runner {
    int place;
    string name;
    string country;
};

vector<runner> a;
vector<runner> tmp;

void inline runner_a_tmp(int i)
{
    a[i].name = tmp[i].name;
    a[i].place = tmp[i].place;
    a[i].country = tmp[i].country;
}

void inline runner_tmp_a(int i, int j)
{
    tmp[i].name = a[j].name;
    tmp[i].place = a[j].place;
    tmp[i].country = a[j].country;
}

void sum_sub_arrays(int L, int R)
{
    for (int i = L; i < R; ++i)
    {
        a[i] = tmp[i];
    }
}

bool compare_country(int i, int j)
{
    return a[i].country <= a[j].country;
}

void merge(int L, int M, int R)
{
    int i = L;
    int j = M;

    for (int k = L; k < R; ++k) {
        if (j == R || (i < M && compare_country(i, j)))
        {
            tmp[k] = a[i];
            i++;
        } else {
            tmp[k] = a[j];
            j++;
        }
    }

    sum_sub_arrays(L, R);
}

void merge_sort(int L, int R)
{
    if (R <= L + 1)
    {
        return;
    }

    int M = (L + R) / 2;
    merge_sort(L, M);
    merge_sort(M, R);
    merge(L, M, R);
}

int main()
{
    ifstream input("race.in");
    ofstream output("race.out");

    int n = 0;
    input >> n;

    a.resize(n);
    tmp.resize(n);

    string input_country;
    string input_runner;

    for (int i = 0; i < n; ++i)
    {
        input >> input_country >> input_runner;
        a[i].name = input_runner;
        a[i].place = i+1;
        a[i].country = input_country;
    }

    merge_sort(0, n);

    string current_country = "";

    for (int i = 0; i < n; i++)
    {
        if (current_country != a[i].country)
        {
            current_country = a[i].country;
            output << "=== " << a[i].country << " ===" << endl;
        }
        output << a[i].name << endl;
    }

    return 0;
}
