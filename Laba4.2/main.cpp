#include <iostream>
#include <vector>
using namespace std;

struct stats
{
    size_t comparison_count = 0;
    size_t copy_count = 0;
};


size_t lcg(){
    static size_t x = 0;
    x = (1021*x + 24631) % 116640;
    return x;
}

void clear_monitor()
{
    for (int i = 0; i < 31; i++)
    {
        cout << endl;
    }
}


int check()
{
    int number;
    while (!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Incorrect value" << endl;
    }
    return number;
}


void inserts_sort(vector<int>& arr, stats& count)
{
    for (auto i = arr.begin(); i != arr.end() - 1; i++)
    {
        count.comparison_count += 1;
        for (auto j = i + 1; j != arr.begin() && *(j - 1) > *j; j--)
        {
            count.comparison_count += 2;
            int tmp = *j;
            *j = *(j - 1);
            *(j - 1) = tmp;
            count.copy_count += 3;
        }
    }
}


void shaker_sort(vector<int>& arr, stats& count)
{
    auto left = arr.begin()+1;
    auto right = arr.end()-1;
    int swap_flag = 1;
    while (left != right)
    {
        count.comparison_count += 1;
        for (auto i = left; i <= right; i++)
        {
            count.comparison_count += 1;
            if (*i < *(i - 1))
            {
                count.comparison_count += 1;
                int tmp = *i;
                *i = *(i - 1);
                *(i - 1) = tmp;
                count.copy_count += 3;
            }
        }
        right--;
        for (auto i = right; i >= left; i--)
        {
            count.comparison_count += 1;
            if (*i < *(i - 1))
            {
                count.comparison_count += 1;
                int tmp = *i;
                *i = *(i - 1);
                *(i - 1) = tmp;
                swap_flag = 1;
                count.copy_count += 3;
            }
        }
        left++;
    }
}


int muny_1()
{
    cout << "Count number of comparisons and number of object copies for arrays. To press.." << endl;
    cout << "1 - mean time"<< endl;
    cout << "2 - for sort arrey"<< endl;
    cout << "3 - for no sort arrey"<< endl;
    cout << "4 - go out" << endl;
    cout << "Operation №";
    int n = check();
    while (n > 4 || n <= 0)
    {
        cout << "Incorrect value" << endl << "Operation №";
        n = check();
    }
    clear_monitor();
    return n;
}

void add_arr(vector<int>& arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr.push_back(int(lcg()));
    }
}


void print_v(vector<int>& arr)
{
    for (auto iter = arr.begin(); iter != arr.end(); iter++)
    {
        cout << *iter << endl;
    }
}


void muny_2()
{
    cout << "What about sort?" << endl;
    cout << "1 - inserts_sort"<< endl;
    cout << "2 - shaker sort"<< endl;
    cout << "3 - go out" << endl;
    cout << "Operation №";
    int n = check();
    while (n > 3 || n <= 0)
    {
        cout << "Incorrect value" << endl << "Operation №";
        n = check();
    }
    cout << "What about size?" << endl;
    cout << "size: ";
    int size = check();
    while (size <= 0)
    {
        cout << "Incorrect value" << endl << "Operation №";
        size = check();
    }
    vector<int> arr;
    add_arr(arr, size);
    clear_monitor();
}


int main()
{
    vector<int> j = {4,6,5,9,1,7,8,3,2,10};
    stats g;
    shaker_sort(j, g);
    print_v(j);
    cout << g.comparison_count << "\t" << g.copy_count;
}
