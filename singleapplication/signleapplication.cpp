#include "signleapplication.h"

SignleApplication::SignleApplication(int argc, char **argv) :
    QCoreApplication(argc, argv)
{

}

bool SignleApplication::isRunning()
{
    mem.setKey("key");
    if(mem.attach())
    {
        mem.detach();
        if(mem.attach())
        {
            mem.detach();
            return false;
        }
    }
    mem.create(4);
    return true;
}
