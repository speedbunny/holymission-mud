inherit "/room/room";
#include "../cellar.h"
#include "/obj/door.h"
object ob,key;
int i,ok;

reset(arg) {
    ok=1;
    if (!arg) {
        set_light(0);
        short_desc= "In a cellar";
        long_desc=
                  "You are in the dark cellar of the Mages Tower.\n"+
                  "It's cold and wet here, but the smell of fresh cheese\n"+
                  "gets stronger and stronger. You notice a barrel in the\n"+
                  "corner. The corridor leads further to the east.\n";
   
        dest_dir = ({
                   ROOM+"c2","east"
                   });
   
        items = ({
                  "vault","An old oak-wooden vault",
                  "wall","A grey stone wall",
                  "walls","Grey stone walls",
                  "bottom","A dark stone bottom",
                  "barrel","An old wooden barrel"
                 });
    } 
    if (!ob) {
           for (i=1;i<3;i++) {
            ob=clone_object(MONST+"spider");
            move_object(ob,this_object());
        }
    }
}

init() {
    add_action("search","search");
    ::init();
}

search(arg) {
    if(arg!="barrel") return;
    if(!ok) {
        write("You find nothing.\n");
    } else {
        write("You find a rusty iron key.\n");
        MAKE_KEY(key,"iron","cellardoor");
        if(transfer(key,this_player())) {
            write("You are carrying too much.\n");
            destruct(key);
            return 1;
        }
        ok=0;
    }
    return 1;
}
