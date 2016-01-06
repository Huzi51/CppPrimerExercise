void swap(int *ptr, int *ptr2)
{
    if (*ptr == *ptr2) {
        return;
    }
    int temp = *ptr;
    *ptr =  *ptr2;
    *ptr2 = temp;
}