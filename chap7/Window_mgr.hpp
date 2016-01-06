#ifndef WINDOW_MGR_H
#define WINDOW_MGR_H

#include <vector>
#include "Screen.hpp"

class Window_mgr {
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    // reset the screen at the given position to all blanks
    void clear(ScreenIndex);
    ScreenIndex addScreen(const Screen &);
private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

// clear
void Window_mgr::clear(ScreenIndex i) {
    Screen &s = screens[i];
    contents = string(s.height * s.width, ' ');
}
// addScreen
Window_mgr::ScreenIndex
Windwo_mgr::addScreen(const Screen &s) {
    screens.push_back(s);
    return screens.size() - 1;
}
#endif