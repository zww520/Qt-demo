#include "signleapplication.h"

int main(int argc, char *argv[])
{
    SignleApplication a(argc, argv);
    if(a.isRunning())
    {
        exit(0);
    }
    return a.exec();
}
