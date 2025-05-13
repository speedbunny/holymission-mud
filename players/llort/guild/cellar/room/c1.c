inherit "/room/room";
#include "../cellar.h"

object ob;
int i;

reset(arg) {

    if (!arg) {
        set_light(0);
        short_desc= "In a cellar";
        long_desc=
                  "You have entered the dark cellar of the Mages Tower.\n"+
                  "It's cold and wet here, but the smell of fresh cheese\n"+
                  "really makes you hungry. The vault smells after bad wood.\n"+
                  "Corridors lead further to the north, west and south, and\n"+
                  "a stair leads up into the mage tower.\n";
   
        dest_dir = ({
                   ROOM+"c2","north",
                   ROOM+"c3","west",
                   ROOM+"c6","south",
                   "players/llort/guild/tower/hallway","up"
                   });
   
        items = ({
                  "vault","An old oak-wooden vault",
                  "wall","A grey stone wall",
                  "walls","Grey stone walls",
                  "bottom","A dark stone bottom",
                  "stair","Normal stone stairs"
                 });
    }
    if (!ob) {
        for (i=1;i<3;i++) {
            ob=clone_object(MONST+"rat");
            move_object(ob,this_object());
        }
    }
} 

init() {
  ::init();
  if(this_player()->id("rat"))
    add_action("up","up",1);
}

up() {
  if(this_player()->query_guild()!=5) {
    write("Sorry, you are not allowed to enter the mages tower.\n");
    return 1;
  } else return ::move();
}
