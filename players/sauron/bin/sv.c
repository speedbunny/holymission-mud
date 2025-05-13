#include <sys_bin.h>
#include <sys_defs.h>

int main() {
    object oOb;

    if(!present("spy", TP))
        oOb = clone_object("/players/herp/shadows/sv");
    if(oOb)
        move_object(oOb, TP);
    return 0;
}
