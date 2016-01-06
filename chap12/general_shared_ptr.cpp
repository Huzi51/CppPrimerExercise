#include <memory>
#include <new>

// chapter 12.1.4
struct destination;
struct connection;
void connect(destination*);
void disconnet(connection);

void f(destination &d /* other parameters */)
{
    connection c = connect(&d);
    std::shared_ptr<connection> p(&c, [](connection *p)
                                  { disconnet(*p); });
    /* .... */
}