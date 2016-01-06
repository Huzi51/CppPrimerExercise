
string (&array_str(int))[10];

typedef string arr[10];
arr &array_str(int);

string arr[10];
decltype(arr) &array_str(int);

auto array_str(int) -> string(&)[10];