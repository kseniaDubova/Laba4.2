#include <iostream>
using namespace std;

struct stats
{
    size_t comparison_count = 0;
    size_t copy_count = 0;
};


size_t lcg(){
    static size_t x = 0;
    x = (1021*x+24631) % 116640;
    return x;
}

void clear_monitor()
{
    for (int i=0; i<31; i++)
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


void inserts_sort(int* arr, int size)
{
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j > 0 && arr[j - 1] > arr[j]; j--) {
            int tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
        }
    }
}


void shaker_sort(int* arr, int size) {
    int left = 0, right = size, swap_flag = 1;
    while ((left < right) && (swap_flag > 0)) {
        swap_flag = 0;
        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swap_flag = 1;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                int tmp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = tmp;
                swap_flag = 1;
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
    clear_monitor();
}


int main()
{
    
}
