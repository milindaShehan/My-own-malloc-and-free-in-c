<h2>Custom Malloc and Free Implementation in C </h2>


<p>
This repository contains an implementation of malloc() and free() functions in C, which are used to dynamically allocate and free memory at runtime. These functions, MyMalloc() and MyFree(), have been implemented in the file mymalloc.h and mymalloc.c respectively.

<a href="https://www.cprogramming.com/" target="_blank" rel="noreferrer"> <img src="https://github.com/tandpfun/skill-icons/blob/main/icons/C.svg" alt="c" width="40" height="40"/> </a> 

</p>
<h3>How to Use</h3>
To use MyMalloc() and MyFree() functions in your own C program, simply include the mymalloc.h header file in your program and link the mymalloc.c file with your source code at compile time.

<h5>Example</h5>
Here is an example program that uses MyMalloc() and MyFree():
</br>

```c

#include <stdio.h>
#include <string.h>
#include "mymalloc.h"

int main(int argc, char *argv[]){
    int *p1 = (int*)MyMalloc(sizeof(int));
    if(p1 == NULL){
        printf("Can not allocate memory size %lu \n", sizeof(int));
    }
    else{
        *p1 = 10;
        printf("Allocated memory: %d\n", *p1);
    }

    char *p2 = (char*)MyMalloc(sizeof(char) * 100);
    if(p2 == NULL){
        printf("Can not allocate memory size %lu \n", sizeof(char) * 100);
    }
    else{
        strcpy(p2, "Allocated memory for 100 characters");
        printf("%s\n", p2);
    }

    MyFree(p1);
    MyFree(p2);

    return 0;
}
```
<h3>How It Works</h3>
The custom malloc() implementation works by maintaining a linked list of free memory blocks. When a request for memory allocation is made, the function scans through the linked list to find a suitable block of free memory. If a block with enough free space is found, it is returned to the calling function after marking it as used. If no suitable block is found, the function requests more memory from the operating system to add to the linked list.

When a memory block is freed, the free() implementation updates the linked list to reflect the freed memory block, and merges adjacent free blocks to reduce fragmentation.

The linked list of free memory blocks is maintained as a global variable, which is not thread-safe.

<h3>Limitations</h3>

This implementation of malloc() and free() is not designed to be used in production environments, and is intended only as an educational exercise. There are many more factors to consider in a production-quality memory allocation implementation, such as thread safety, performance, and optimization.
