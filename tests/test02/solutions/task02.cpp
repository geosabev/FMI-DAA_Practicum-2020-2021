#include<iostream>
#include<algorithm>
using namespace std;

struct Application
{
    int boss, employee, price;

    Application(int b = 0, int e = 0, int p = 0)
    {
        this->boss = b;
        this->employee = e;
        this->price = p;
    }

    bool operator<(const Application& other) const
    {
        return (this->price < other.price);
    }
};

int n, m, result = 0, found_job = 0;
int q[(int)1e5 + 5];
Application applications[4 * (int)1e5];
bool visited[(int)1e5 + 5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int b, e;

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> q[i];

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> b >> e >> applications[i].price;

        applications[i].boss = b - 1;
        applications[i].employee = e - 1;
    }

    sort(applications, applications + m);

    for (int i = 0; i < m; i++)
    {
        int boss = applications[i].boss, employee = applications[i].employee, price = applications[i].price;

        if (visited[employee] == false && q[boss] > q[employee])
        {
            visited[employee] = true;

            result += price;

            found_job++;
        }

        if (found_job == n - 1)
            break;
    }

    if (found_job == n - 1)
        cout << result << '\n';
    else
        cout << -1 << '\n';

    return 0;
}