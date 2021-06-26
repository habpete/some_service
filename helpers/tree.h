#include <string>
#include "../handlers/handlers_iface.h"

struct handlerPair {
    handlerPair(std::string& handlerName, IHandlers* handlerFunc);
    ~handlerPair();
    std::string handlerName;
    IHandlers* handlerFunc;
};

struct Node {
    Node(size_t hash, handlerPair* handler);
    ~Node();
    size_t hash;
    handlerPair* handler;
    Node* moreNode;
    Node* lessNode;
};

class Tree {
public:
    Tree();
    ~Tree();
private:
    Node* node;
    int counter;
public:
    void Add (std::string& handlerName, IHandlers* handlerFunc);
    handlerPair* Get(std::string& handlerName);
private:
    Node*& searchForAdd (Node* nodeTree, size_t hashKey);
    Node* search(Node* nodeTree, size_t hashKey);
};