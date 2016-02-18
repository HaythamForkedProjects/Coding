#include <ulib/util_macro.h>

bool foo()
{
    printf("passed\n");
    return false;
}

int main()
{
    ULIB_ASSERT(1);
    ULIB_ASSERT(foo());
    return 0;
}
