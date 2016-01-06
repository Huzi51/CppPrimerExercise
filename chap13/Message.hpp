#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <string>
#include <set>
#include <utility>

class Folder;
class Message {
    friend void swap(Message&, Message&);
public:
    explicit Message(const std::string &s = " "):
        contents(s) { }
    Message(const Message&); // copy-constructor
    Message(Message&&); // move-constructor

    Message& operator=(const Message&); // copy-assignment
    Message& operator=(const Message&&) // move-assignment
    ~Message();
    void save(Folder&);
    void remove(Folder&);
private:
    std::string contents;
    std::set<Folder*> folders;
    void add_to_Folders(const Message&);
    void remove_from_Folders();
    void move_Folders(Message *m);
};

class Folder {
public:
    Folder() = default;

    Folder(const Folder&);
    Folder(Folder&&);

    Folder& operator=(const Folder&);
    Folder& operator=(Folder&&);

    ~Folder();
    void addMsg(Message *mp) {
        msgs.insert(mp);
    }
    void remMsg(Message *mp) {
        msgs.erase(mp);
    }
private:
    std::set<Message*> msgs;
    void remove_from_Messages();
    void add_to_Messages(const Folder&);
};
// Folder::remove_from_Message
inline void
Folder::remove_from_Messages() {
    for (auto m : msgs) {
        m->remove(*this);
    }
}

// Folder::add_to_Messages
inline void
Folder::add_to_Messages(const Folder &f) {
    for (auto m : f.msgs) {
        m->save(*this);
    }
}

// Folder copy-constructor
inline
Folder::Folder(const Folder &rhs):
    msgs(rhs.msgs) {
    add_to_Messages(rhs);
}
// Folder::move_Messages
inline void
Folder::move_Messages(Folder *f) {
    msgs = std::move(f->msgs);
    for (auto m : msgs) {
        m->save(*this);
        m->remove(*f);
    }
    f->msgs.clear();
}
// Folder move-constructor
inline
Folder::Folder(Folder &&rhs) {
    move_Messages(&rhs);
}

// copy-assignment
inline Folder&
Folder::operator=(const Folder &rhs) {
    remove_from_Messages();
    msgs = rhs.msgs;
    add_to_Messages(rhs);
    return *this;
}
// move-assignment
inline Folder&
Folser::operator=(Folder &&rhs) {
    if (this != &rhs){
        remove_from_msgs();
        move_Messages(&rhs);
    }
    return *this;
}
// destructors
inline
Folder::~Folder() {
    remove_from_Messages();
}
// save
inline void
Message::save(Folder &f) {
    f.addMsg(this);
    folders.insert(&f);
}
// remove
inline void
Message::remove(Folder &f) {
    f.remMsg(this);
    folders.erase(&f);
}
// add_to_Folders
inline
void Message::add_to_Folders(const Message &msg) {
    for (auto f : msg.folders) {
        f->addMsg(this);
    }
}
// remove_from_Folders
inline
void Message::remove_from_Folders() {
    for (auto f : folders) {
        f->remMsg(this);
    }
}
// move_Folders
inline void
Message::move_Folders(Message *m) {
    folders = std::move(m->folders);
    for (auto f : folders) {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}
// copy-constructors
Message::Message(const Message &rhs):
    contents(rhs.contents), folders(rhs.folders) {
    add_to_Folders(rhs);
}
// move-constructors
Message::Message(Message &&rhs):
    contents(std::move(rhs.contents)) {

    move_Folders(&rhs);
}
// copy-assignment
Message&
Message::operator=(const Message &rhs) {
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(rhs);
    return *this;
}
// move-assignment
Message&
Message::operator=(Message &&rhs) {
    if (this != &rhs) {
        remove_from_Folders();
        contents = std::move(rhs.contents);
        move_Folders(&rhs);
    }
    return *this;
}
// destructors
Message::~Message() {
    remove_from_Folders();
}
// Message::swap
inline void
swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for(auto f : lhs.folders) {
        f->remMsg(&lhs);
    }
    for (auto f : rhs.folders) {
        f->remMsg(&rhs);
    }

    swap(lhs.contents, rhs.contents);
    swap(lhs.folders, rhs.folders);

    for (auto f : lhs.folders) {
        f->addMsg(&lhs);
    }

    for (auto f : rhs.folders) {
        f->addMsg(&rhs);
    }
}
#endif