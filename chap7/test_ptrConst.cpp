int &fun(const int *ip)
{
    return *ip;
}
int main()
{
    int i = 2;
    int *p = &i;
    fun(p) = 3;
}