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


stats inserts_sort(vector<int>& arr)
{
    stats count;
    for (auto i = arr.begin(); i != arr.end() - 1; i++)
    {
//        count.comparison_count += 1;
        for (auto j = i + 1; j != arr.begin() && *(j - 1) > *j; j--)
        {
            count.comparison_count += 1;
            int tmp = *j;
            *j = *(j - 1);
            *(j - 1) = tmp;
            count.copy_count += 3;
        }
        count.comparison_count += 1;
    }
    return count;
}


stats shaker_sort(vector<int>& arr)
{
    stats count;
//    cout <<"shaker_sort";
    auto left = arr.begin() + 1;
    auto right = arr.end() - 1;
    int swap_flag = 1;
    while (left != right)
    {
//        count.comparison_count += 1;
        for (auto i = left; i <= right; i++)
        {
//            count.comparison_count += 1;
            if (*i < *(i - 1))
            {
                count.comparison_count += 1;
                int tmp = *i;
                *i = *(i - 1);
                *(i - 1) = tmp;
                count.copy_count += 3;
            }
            count.comparison_count += 1;
        }
        right--;
        for (auto i = right; i >= left; i--)
        {
//            count.comparison_count += 1;
            if (*i < *(i - 1))
            {
                count.comparison_count += 1;
                int tmp = *i;
                *i = *(i - 1);
                *(i - 1) = tmp;
                swap_flag = 1;
                count.copy_count += 3;
            }
            count.comparison_count += 1;
        }
        left++;
    }
    return count;
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


void mean_time(int m)
{
    stats (*func[2])(vector<int>& arr) = {inserts_sort, shaker_sort};
    int size = 1000;

    while(size < 100001)
    {
        long int mean_copy = 0;
        long int mean_comp = 0;
        for (int i = 0; i < 100; i++)
        {
           vector<int> arr;
           add_arr(arr, size);
           stats res = func[m-1](arr);
           mean_comp += res.comparison_count;
           mean_copy += res.copy_count;
        }
        cout << "Size : " << size << "\t";
        cout << "Comparisons : " << mean_comp/100 << "\t";
        cout << "Copy : " << mean_copy/100 << endl;
        if (size < 10000)
            size += 1000;
        else
        {
            if (size == 10000)
                size = 25000;
            else
                size += 25000;
        }
    }
    getchar();
    getchar();
    clear_monitor();
}


void sort_arrey(int m)
{
    stats (*func[2])(vector<int>& arr) = {inserts_sort, shaker_sort};
    int size = 1000;

    while(size < 100001)
    {
        long int mean_copy = 0;
        long int mean_comp = 0;
        vector<int> arr;
       add_arr(arr, size);
        shaker_sort(arr);
       stats res = func[m-1](arr);
       mean_comp += res.comparison_count;
       mean_copy += res.copy_count;
        cout << "Size : " << size << "\t";
        cout << "Comparisons : " << mean_comp << "\t";
        cout << "Copy : " << mean_copy << endl;
        if (size < 10000)
            size += 1000;
        else
        {
            if (size == 10000)
                size = 25000;
            else
                size += 25000;
        }
    }
    getchar();
    getchar();
    clear_monitor();
}

void back_arr(vector<int>& arr)
{
    for (auto i = arr.begin(); i != arr.end() - 1; i++)
    {
        for (auto j = i + 1; j != arr.begin() && *(j - 1) < *j; j--)
        {
            int tmp = *j;
            *j = *(j - 1);
            *(j - 1) = tmp;
        }
    }
}


void backsort_arrey(int m)
{
    stats (*func[2])(vector<int>& arr) = {inserts_sort, shaker_sort};
    int size = 1000;

    while(size < 100001)
    {
        long int mean_copy = 0;
        long int mean_comp = 0;
       vector<int> arr;
       add_arr(arr, size);
        back_arr(arr);
       stats res = func[m-1](arr);
       mean_comp += res.comparison_count;
       mean_copy += res.copy_count;
        cout << "Size : " << size << "\t";
        cout << "Comparisons : " << mean_comp << "\t";
        cout << "Copy : " << mean_copy << endl;
        if (size < 10000)
            size += 1000;
        else
        {
            if (size == 10000)
                size = 25000;
            else
                size += 25000;
        }
    }
    getchar();
    getchar();
    clear_monitor();
}


int muny_2()
{
    cout << "What about sort?" << endl;
    cout << "1 - inserts_sort"<< endl;
    cout << "2 - shaker sort"<< endl;
    cout << "3 - go out" << endl;
    cout << "Operation №";
    int m = check();
    while (m > 3 || m <= 0)
    {
        cout << "Incorrect value" << endl << "Operation №";
        m = check();
    }
    return m;
}


int main()
{
    void (*operatoin[3])(int m) = {mean_time, sort_arrey, backsort_arrey};
    int n = muny_1();
    getchar();
    while (n < 4)
    {
        int m = muny_2();
        operatoin[n - 1](m);
        getchar();
        clear_monitor();
        cout << "What's next?" << endl;
        n = muny_1();
    }
//    cout << g.comparison_count << "\t" << g.copy_count;
//    mean_time(2);
}
/*
 1)
 inserts_sort
Size : 1000    Comparisons : 249847    Copy : 749541
Size : 2000    Comparisons : 996912    Copy : 2990736
Size : 3000    Comparisons : 2245186    Copy : 6735560
Size : 4000    Comparisons : 3991326    Copy : 11973979
Size : 5000    Comparisons : 6236955    Copy : 18710866
Size : 6000    Comparisons : 8983846    Copy : 26951540
Size : 7000    Comparisons : 12222712    Copy : 36668138
Size : 8000    Comparisons : 15969105    Copy : 47907316
Size : 9000    Comparisons : 20212746    Copy : 60638240
Size : 10000   Comparisons : 24965942    Copy : 74897827
Size : 25000   Comparisons : 154697466    Copy : 464092398
Size : 50000   Comparisons : 624416026    Copy : 1873248078
Size : 75000   Comparisons : 1415104108    Copy : 4245312324
Size : 100000  Comparisons : 2477102201    Copy : 7431306603
 
 shaker sort
 Size : 1000    Comparisons : 249847    Copy : 749541
 Size : 2000    Comparisons : 996912    Copy : 2990736
 Size : 3000    Comparisons : 2245186    Copy : 6735560
 Size : 4000    Comparisons : 3991326    Copy : 11973979
 Size : 5000    Comparisons : 6236955    Copy : 18710866
 Size : 6000    Comparisons : 8983846    Copy : 26951540
 Size : 7000    Comparisons : 12222712    Copy : 36668138
 Size : 8000    Comparisons : 15969105    Copy : 47907316
 Size : 9000    Comparisons : 20212746    Copy : 60638240
 Size : 10000   Comparisons : 24965942    Copy : 74897827
 Size : 25000   Comparisons : 154697466    Copy : 464092398
 Size : 50000   Comparisons : 624416026    Copy : 1873248078
 Size : 75000   Comparisons : 1415104108    Copy : 4245312324
 Size : 100000  Comparisons : 2477102201    Copy : 7431306603
 
 2)
 inserts_sort
Size : 1000    Comparisons : 999    Copy : 0
Size : 2000    Comparisons : 1999    Copy : 0
Size : 3000    Comparisons : 2999    Copy : 0
Size : 4000    Comparisons : 3999    Copy : 0
Size : 5000    Comparisons : 4999    Copy : 0
Size : 6000    Comparisons : 5999    Copy : 0
Size : 7000    Comparisons : 6999    Copy : 0
Size : 8000    Comparisons : 7999    Copy : 0
Size : 9000    Comparisons : 8999    Copy : 0
Size : 10000   Comparisons : 9999    Copy : 0
Size : 25000   Comparisons : 24999    Copy : 0
Size : 50000   Comparisons : 49999    Copy : 0
Size : 75000   Comparisons : 74999    Copy : 0
Size : 100000  Comparisons : 99999    Copy : 0
 
 shaker sort
 Size : 1000    Comparisons : 499499    Copy : 0
 Size : 2000    Comparisons : 1998999    Copy : 0
 Size : 3000    Comparisons : 4498499    Copy : 0
 Size : 4000    Comparisons : 7997999    Copy : 0
 Size : 5000    Comparisons : 12497499    Copy : 0
 Size : 6000    Comparisons : 17996999    Copy : 0
 Size : 7000    Comparisons : 24496499    Copy : 0
 Size : 8000    Comparisons : 31995999    Copy : 0
 Size : 9000    Comparisons : 40495499    Copy : 0
 Size : 10000    Comparisons : 49994999    Copy : 0
 Size : 25000    Comparisons : 312487499    Copy : 0
 Size : 50000    Comparisons : 1249974999    Copy : 0
 Size : 75000    Comparisons : 2812462499    Copy : 0
 Size : 100000    Comparisons : 4999949999    Copy : 0
 
 3)
 inserts_sort
 Size : 1000    Comparisons : 500499    Copy : 1498500
 Size : 2000    Comparisons : 2000999    Copy : 5997000
 Size : 3000    Comparisons : 4501499    Copy : 13495500
 Size : 4000    Comparisons : 8001999    Copy : 23994000
 Size : 5000    Comparisons : 12502499    Copy : 37492500
 Size : 6000    Comparisons : 18002999    Copy : 53991000
 Size : 7000    Comparisons : 24503499    Copy : 73489500
 Size : 8000    Comparisons : 32003999    Copy : 95988000
 Size : 9000    Comparisons : 40504499    Copy : 121486500
 Size : 10000    Comparisons : 50004999    Copy : 149985000
 Size : 25000    Comparisons : 312512499    Copy : 937462500
 Size : 50000    Comparisons : 1250024999    Copy : 3749925000
 Size : 75000    Comparisons : 2812537499    Copy : 8437387500
 Size : 100000    Comparisons : 5000049999    Copy : 14999850000
 
 shaker sort
 Size : 1000    Comparisons : 998998    Copy : 1498497
 Size : 2000    Comparisons : 3997998    Copy : 5996997
 Size : 3000    Comparisons : 8996998    Copy : 13495497
 Size : 4000    Comparisons : 15995998    Copy : 23993997
 Size : 5000    Comparisons : 24994998    Copy : 37492497
 Size : 6000    Comparisons : 35993998    Copy : 53990997
 Size : 7000    Comparisons : 48992998    Copy : 73489497
 Size : 8000    Comparisons : 63991998    Copy : 95987997
 Size : 9000    Comparisons : 80990998    Copy : 121486497
 Size : 10000    Comparisons : 99989998    Copy : 149984997
 Size : 25000    Comparisons : 624974998    Copy : 937462497
 Size : 50000    Comparisons : 2499949998    Copy : 3749924997
 Size : 75000    Comparisons : 5624924998    Copy : 8437387497
 Size : 100000    Comparisons : 9999899998    Copy : 14999849997
*/
