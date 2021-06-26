#include "./tree.h"

handlerPair::handlerPair(std::string& handlerName, IHandlers* handlerFunc) {
    this->handlerName = handlerName;
    this->handlerFunc = handlerFunc;
}

Node::Node(size_t hash, handlerPair* handler) {
    this->hash = hash;
    this->handler = handler;
}

Node::~Node() {
    if (this->lessNode != nullptr) {
        delete this->lessNode;
    }
    if (this->moreNode != nullptr) {
        delete this->moreNode;
    }
}

void Tree::Add (std::string& handlerName, IHandlers* handlerFunc) {
    size_t hashKey = std::hash<std::string>()(handlerName); // вычисление хеш ключа

    handlerPair* tmpHandlerPair = new handlerPair(handlerName, handlerFunc);

    if (this->node == nullptr) {
        this->node = new Node(hashKey, tmpHandlerPair);
        return;
    }

    Node* cellNode = searchForAdd(this->node, hashKey);
    cellNode = new Node(hashKey, tmpHandlerPair);

}

Node*& Tree::searchForAdd (Node* nodeTree, size_t hashKey) {
    if (nodeTree->hash < hashKey) {
        if (nodeTree->lessNode == nullptr) {
            return nodeTree->lessNode;
        }
        return searchForAdd(nodeTree->lessNode, hashKey);
    }
    if (nodeTree == nullptr) {
        return nodeTree->moreNode;
    }
    return searchForAdd(nodeTree->moreNode, hashKey);
}

handlerPair* Tree::Get(std::string& handlerName) {
    size_t hashKey = std::hash<std::string>()(handlerName); // вычисление хеш ключа

    Node* cellNode = search(this->node, hashKey);

    return cellNode->handler;
}

Node* Tree::search(Node* nodeTree, size_t hashKey) {
    if (nodeTree == nullptr) {
        return nullptr;
    }

    if (nodeTree->hash == hashKey) {
        return nodeTree;
    }

    if (nodeTree->hash < hashKey) {
        return search(nodeTree->lessNode, hashKey);
    }
    return search(nodeTree->moreNode, hashKey);
}
