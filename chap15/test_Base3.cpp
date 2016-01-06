#include "Base.hpp"

int main()
{
    Pub_Derv d1;
    Priv_Derv d2;
    Prot_Derv d3;
    Derived_from_Public dd1;
    Derived_from_Private dd2;
    Derived_from_Protected dd3;

    Base *p = &d1;
    // p = &d2; // error
    p = &d3; // error
    p = &dd1;
    p = &dd2; // error
    p = &dd3; // error
}