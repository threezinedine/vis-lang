#include <cstdio>

#ifdef DEBUG
#define DEBUG_PRINT(...) printf(__VA_ARGS__)
#else
#define DEBUG_PRINT(...)
#endif

int main(void)
{
    printf("Hello, World!\n");

    DEBUG_PRINT("Debugging...\n");

    return 0;
}