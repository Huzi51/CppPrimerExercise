#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
    void pub_mem();
    void memfcn(Base &b) { b = *this; }
protected:
    int prot_mem;
private:
    char priv_mem;
};


class Pub_Derv : public Base {
    void memfcn(Base &b) { b = *this; }
};
class Priv_Derv : private Base {
    void memfcn(Base &b) { b = *this; }
};
class Prot_Derv : protected Base {
    void memfcn(Base &b) { b = *this; }
};

class Derived_from_Public : public Pub_Derv {
    // legal
    void memfcn(Base &b) { b = *this; }
};
class Derived_from_Private : public Priv_Derv {
    // illegal
    // void memfcn(Base &b) { b = *this; }
};
class Derived_from_Protected : public Prot_Derv {
    // legal
    void memfcn(Base &b) { b = *this; }
};
#endif