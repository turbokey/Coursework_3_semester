#include <iostream>

using namespace std;

const int N = 5;

void outputArr(int *arr, int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
            cout << "... ";
        else if (arr[i] == -1)
            if (i != 0)
                cout << "[" << arr[i-1]+1 << "] ";
            else
                cout << "[" << arr[i+1]-1 << "] ";
        else
            cout << arr[i] << " ";
    }
    cout << endl;
}

int input(char *message, int cntr_arg)
{
    int tmp;
    cout << message;
    while (!(cin >> tmp) || tmp <= 0 || (tmp > cntr_arg))
    {
        if (cntr_arg == 0 && tmp > 0)
            break;
        cin.clear();
        while (cin.get() != '\n');
        cout << "Input error!" << endl;
        cout << message;
    }
    return tmp;
}

int calcArrSize(int L, int C)
{
    int size;
    if(L > N+2)
    {
        if(((C-N/2)>2) && ((C+N/2)<(L-N%2)))
            size = N+4;
        else if ((C-N/2 == 2) || (C+N/2 == (L-N%2)))
            size = N+3;
        else
            size = N+2;
    }
    else
    {
        size = L;
    }
    return size;
}

void calcListProp(int L, int C, bool &dots_in_beg, bool &dots_in_end)
{
    if(L > N+2)
    {
        if(((C-N/2)>2) && ((C+N/2)<(L-N%2)))
        {
            dots_in_beg = true;
            dots_in_end = true;
        }
        else if (C-N/2 == 2)
        {
            dots_in_beg = false;
            dots_in_end = true;
        }
        else if (C+N/2 == (L-N%2))
        {
            dots_in_beg = true;
            dots_in_end = false;
        }
        else
        {
            if (C-N/2 == 1)
            {
                dots_in_beg = false;
                dots_in_end = true;
            }
            else if (C-N/2 == (L-N%2)+1)
            {
                dots_in_beg = true;
                dots_in_end = false;
            }
            else if (C-N/2 < 1)
            {
                dots_in_beg = false;
                dots_in_end = true;
            }
            else if (C+N/2 > (L-N%2)+1)
            {
                dots_in_beg = true;
                dots_in_end = false;
            }
            else
            {
                dots_in_beg = true;
                dots_in_end = false;
            }
        }
    }
    else
    {
        dots_in_beg = false;
        dots_in_end = false;
    }
}

int* constructArr(int L, int C, int *out_arr)
{
    bool dots_in_beg, dots_in_end;
    int arr_size = calcArrSize(L,C);
    int beg_index = 0, end_index = arr_size;

    calcListProp(L, C, dots_in_beg, dots_in_end);

    if (dots_in_beg)
    {
        out_arr[0] = 1;
        out_arr[1] = 0;
        beg_index = 2;
    }
    if (dots_in_end)
    {
        out_arr[arr_size-1] = L;
        out_arr[arr_size-2] = 0;
        end_index = arr_size-3;
    }
    int elem;
    if (C < N)
        elem = 1;
    else if (C + N/2 <= L)
        elem = C - N/2;
    else
        elem = L - N + 1;
    for (int i = beg_index; i <= end_index; i++)
    {
        if (elem == C)
            out_arr[i] = -1;
        else
            out_arr[i] = elem;
        elem++;
    }
    return out_arr;
}

int main()
{
    int L,C, arr_size;
    char a = 'y';
    while(a == 'y')
    {
        L = input("Enter the number of pages: ", 0);
        C = input("Enter the selected page: ", L);

        arr_size = calcArrSize(L,C);
        int *out_arr = new int[arr_size];
        out_arr = constructArr(L,C,out_arr);
        outputArr(out_arr, arr_size);
        delete [] out_arr;

        cout << "Try again? [y/n]: ";
        cin >> a;
        cout << endl;
    }
    return 0;
}
