#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

int main()
{
    char ca[] = "nihaoajjfjf";
    char ca2[] = "hello,huzi";
    int result;
    if ( (result = strcmp(ca, ca2)) == 0) {
        cout << "Equal" << endl;
    } else
    if(result > 0) {
        cout << "ca is bigger!" << endl;
    } else {
        cout << "ca2 is bigger!" << endl;
    }
    return 0;
}