#include "/players/mangla/defs.h"

/******** PERINV Can be used to check your inventory without
                 others being able to tell. Can also check
                 inventroy when it is too dark to see otherwise.
*********/

int query_delay() {
  return 0;
}


int main() {

    object obj;

    write("You can feel the items you carry.\nYou carry:\n");
    obj=first_inventory(TP);
    while(obj) {
        if(obj->short())
            write(obj->short()+".\n");
        obj=next_inventory(obj);
    }
    return 1;
}

