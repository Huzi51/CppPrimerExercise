#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>
class Window_mgr;

class Screen {
    friend void Window_mgr::clear(ScreenIndex);
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd): height(ht), width(wd),
                            contents(ht * wd, ' ') { }
    Screen(pos h, pos w, char c): height(h), width(w),
                                  contents(h * w, c) { }
    // get
    char get() const { return contents[cursor]; } // implicitly inline
    inline char get(pos ht, pos wd) const; // explicitly inline
    // move
    Screen &move(pos r, pos c); // can be made inline outside of class
    // set
    Screen &set(char);
    Screen &set(pos, pos, char);
    // display
    Screen &display(std::ostream &os) {
        do_display(os);
        return *this; // return reference to nonconst object
    }
    // display const version
    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this; // return reference to const object
    }
    // size
    pos size() const;
private:
    void do_display(std::ostream &os) const {
        os << contents;
    }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    // mutable data memeber, may change even in a const object
    mutable size_t access_ctr;
};
// we can specify inline on the definition
inline Screen &Screen::move(pos r, pos c) {
    pos row = r * width;
    cursor = row + c;
    return *this;
}
// declare as inline in the class
char Screen::get(pos ht, pos wd) const {
    pos row = ht * width;
    return contents[row + wd];
}
// set member function
inline Screen &Screen::set(char ch) {
    contents[cursor] = ch;
    return *this;
}
inline Screen &Screen::set(pos row, pos col, char ch) {
    contents[row * width + col] = ch;
    return *this;
}
// size member function
inline Screen::pos
Screen::size() {
    return height * width;
}
#endif