#include "helpers/tree.h"
#include "handlers/handlers_iface.h"
#include "handlers/create_handler.h"

int main () {
    std::string handlerName = "create";
    IHandlers* handler = new CreateHandler();

    Tree handlersTree;
    handlersTree.Add(handlerName, handler);

    return 0;
}