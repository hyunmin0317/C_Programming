#include <stdio.h>
void myqsort(char* lineptr[], int left, int right);
void reversewritelines(char* v[], int argc);
void writelines(char* v[], int argc);
void swap(char* v[], int i, int j);

int main(int argc, char* argv[])
{
    if (--argc > 0 && (*++argv)[0] == '-')
    {
        if (*++argv[0] == 'r')
        {
            myqsort(argv, 2, argc);
            reversewritelines(argv, argc);
        }
    }
    else
    {
        myqsort(argv, 1, argc);
        writelines(argv, argc);
    }
    return 0;
}

void myqsort(char* v[], int left, int right)
{
    int i, last;
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    myqsort(v, left, last - 1);
    myqsort(v, last + 1, right);
}

void reversewritelines(char* v[], int argc)
{
    for (int i = argc-1; i > 0; i--)
        printf("%s\n", v[i]);

}

void writelines(char* v[], int argc)
{
    for (int i = 1; i <= argc; i++)
        printf("%s\n", v[i]);
}

void swap(char* v[], int i, int j)
{
    char* temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}