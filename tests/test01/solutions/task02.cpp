#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int hotels[(int)1e5 + 5];

bool can_accommodate(int distance)
{
    int current_position = hotels[0], to_accommodate = k - 1;

    for (int i = 1; i < n; i++)
    {
        if (hotels[i] < current_position + distance)
            continue;

        current_position = hotels[i];

        to_accommodate--;

        if (to_accommodate == 0)
            return true;
    }

    return false;
}

void BS()
{
    int l = 0, r = hotels[n - 1], result = -1;

    while (l <= r)
    {
        int mid = l + ((r - l) / 2);

        if (can_accommodate(mid))
        {
            result = mid;

            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    cout << result << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> hotels[i];

    sort(hotels, hotels + n);

    BS();

    return 0;
}