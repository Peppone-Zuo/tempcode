#include <iostream>
#include <vector>
using namespace std;


int calculate(vector<int> circle, int step);
int recursive_calc(int n, int k);

vector<int> josephus;


int main(void)
{
    int i;
    for (i = 0; i < 7; i++)
    {
        josephus.push_back(i + 1);
    }
    for (i = 0; i < josephus.size(); i++)
        cout << josephus[i] << " ";
    cout << endl;
    cout << "last position is: " << calculate(josephus, 3) << endl;
    cout << recursive_calc(7, 3);
    return 0;
}

int calculate(vector<int> circle, int step)
{
    int position, count;
    int size = circle.size();
    int i;
    count = 0;
    position = 0;

    while (1)
    {
        if (count >= size - 1)
            break;
        
        i = 0;
        while (1)
        {
            position = (position + 1) % size;
            if (circle[position] != 0)
                i++;
            if (i >= step)
                break;
        }
        count++;
    }

    return position + 1;
}

int recursive_calc(int n, int k)
{
    if (1 == n)
        return 1;
    return (recursive_calc(n - 1, k) + k - 1) % (n + 1);
}

