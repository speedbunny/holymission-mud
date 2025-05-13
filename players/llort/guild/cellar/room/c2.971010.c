inherit "/room/room";
#include "../cellar.h"
#include "/obj/door.h"
object ob,obj_1,obj_2;
int i;

reset(arg) {
    if (!arg) {
        set_light(0);
        short_desc= "In a cellar";
        long_desc=
                  "You are in the dark cellar of the Mages Tower.\n"+
                  "It's cold and wet here, but the smell of fresh cheese\n"+
                  "really makes you hungry. The vault smells after bad wood.\n"+
                  "There is a wall to the east and north. The corridor\n"+ 
                  "leads further to the west and south.\n";
   
        dest_dir = ({
                   ROOM+"c4","west",
                   ROOM+"c1","south"
                   });
   
        items = ({
                  "vault","An old oak-wooden vault",
                  "wall","A grey stone wall",
                  "walls","Grey stone walls",
                  "bottom","A dark stone bottom"
                 });
        MAKE_DOORS(ROOM+"c2","west",ROOM+"c4","east","iron","cellardoor",
              "It looks like a normal wooden cellar door.\n", 1, 1, 1); 
    } 
    if(obj_1) {
        obj_1->set_closed(1);
        obj_1->set_locked(0);
        obj_1->set_both_status();
    }
    if (!ob) {
        for (i=1;i<3;i++) {
            ob=clone_object(MONST+"bat");
            move_object(ob,this_object());
        }
    }
}       
