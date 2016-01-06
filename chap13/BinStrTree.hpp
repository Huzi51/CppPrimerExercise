#ifndef BINSTR_TREE_HPP
#define BINSTR_TREE_HPP

#include <string>

class TreeNode {
    TreeNode():
        count(1), left(new TreeNode), right(new TreeNode);
    TreeNode(const TreeNode &node):
        value(node.value), count(++node.count),
        left(node.left), right(node.right) { }
    TreeNode& operator=(const TreeNode &rhs);
    ~TreeNode();
private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};
// operator=
inline TreeNode&
TreeNode::operator=(const TreeNode &rhs) {
    ++rhs.count;
    if (--count == 0) {
        delete left;
        delete right;
    }
    value = rhs.value;
    count = rhs.count;
    left = rhs.left;
    right = rhs.right;
}
// destructor
inline
TreeNode::~TreeNode() {
    if (--count) {
        delete left;
        delete right;
    }
}

class BinStrTree {
    BinStrTree():
        root(new TreeNode) { }
    BinStrTree(const BinStrTree &rhs):
        root(new TreeNode(*rhs.root)) { }
    BinStrTree& operator=(const BinStrTree &rhs);
    ~BinStrTree();
private:
    TreeNode *root;
};
// copy-assignment constructor
inline BinstrTree&
BinStrTree::operator=(const BinStrTree &rhs) {
    auto newp = new TreeNode(*rhs.root);
    delete root;
    root = newp;
    return *this;
}
// destructor
BinStrTree::~BinStrTree() {
    delete root;
}
#endif