#include "Executive.h"

int main(int argc, char* argv[])
{
    Executive exec(argv[1]);
    exec.run();
    return 0;
}
