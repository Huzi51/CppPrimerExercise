struct absInt {
    int operator(int val) const {
        return val < 0 ? -val : val;
    }
};

int main()
{
    absInt absObj;
    int i = -42;
    int ui = absObj(i);
}