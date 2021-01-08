#include <stdio.h>
#include <stdlib.h>

#include "proj.h"

extern int i;

static void func(void){
    printf("[%s]:i = %d\n",__FUNCTION__,i);
    exit(0);
}

void call_func(){
    func();
}