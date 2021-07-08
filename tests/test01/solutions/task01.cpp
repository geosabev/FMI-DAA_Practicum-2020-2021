#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Student
{
    string name;
    int fac_number, points;

    Student(string n = "", int fn = 0, int p = 0)
    {
        this->name = n;
        this->fac_number = fn;
        this->points = p;
    }

    bool operator<(const Student& other) const
    {
        if (this->points == other.points)
            return (this->fac_number < other.fac_number);

        return (this->points < other.points);
    }
};

int n, q;
Student arr[(int)1e5 + 5];

void BS(int target)
{
    int l = 0, r = n - 1, result = -1;

    while (l <= r)
    {
        int mid = l + ((r - l) / 2);

        if (arr[mid].points >= target)
        {
            result = mid;

            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    cout << arr[result].name << ' ' << arr[result].fac_number << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int to_check;

    cin >> n >> q;

    for (int i = 0; i < n; i++)
        cin >> arr[i].name >> arr[i].fac_number >> arr[i].points;

    sort(arr, arr + n);

    for (int i = 0; i < q; i++)
    {
        cin >> to_check;

        BS(to_check);
    }

    return 0;
}