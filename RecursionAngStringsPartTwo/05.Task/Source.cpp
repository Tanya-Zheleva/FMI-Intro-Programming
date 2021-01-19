#include <iostream>
#include <string.h>

using namespace std;

bool shouldReplace(const char* what, const char* where)
{
    int i = 0;

    while (i < strlen(what) && i < strlen(where))
    {
        if (what[i] != where[i])
        {
            return false;
        }

        i++;
    }

    return true;
}

char* getReplaced(const char* what, char* where)
{
    char* idx = nullptr;
    int i = 0;

    while (i < strlen(where))
    {
        if (where[i] == what[0] && shouldReplace(what, where + i))
        {
            idx = where + i;
            int j = 0;

            while (j < strlen(what))
            {
                where[i] = '*';
                i++;
                j++;
            }

            i--;
        }

        i++;
    }

    return idx;
}


int main()
{
    char what[250], where[250];

    cin.getline(what, 250);
    cin.getline(where, 250);

    char* replaced = getReplaced(what, where);

    cout << where << endl;
    cout << replaced << endl;

	return 0;
}