#include <stdio.h>

// Declare the external function
extern void hello();

int main() {
    // Call the assembly function
    hello();
    return 0;
}