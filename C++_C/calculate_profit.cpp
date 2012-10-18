#include <iostream>
using namespace std;

const float profitTab[] = {0.0, 10.0, 20.0, 40.0, 60.0, 100.0};
const float percentTab[] = {0.1, 0.075, 0.05, 0.03, 0.015, 0.01};


float get_salary(float profit)
{
    int i;
    float salary = 0.0;
    //float profit = 11;
    for (i = 0; i < 5 && profit > profitTab[i + 1]; i++)
    {
        salary += percentTab[i] * (profitTab[i + 1] - profitTab[i]);
    }

    salary += percentTab[i] * (profit - profitTab[i]);
    return salary;
}

int main(void)
{
    float profit;
    do
    {
        cout << "please input your profit in 10, 000 yuan:";
        cin >> profit;
        cout << get_salary(profit) << endl;
    }while (profit >= 0);
    return 0;
}
