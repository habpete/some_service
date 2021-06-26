#include "./handlers_iface.h"

class CreateHandler : virtual public IHandlers {
public:
    CreateHandler();
    ~CreateHandler();
public:
    void HandlerFunc();
};