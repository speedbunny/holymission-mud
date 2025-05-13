inherit "/room/room";
#include "/players/wilbie/def.h"

object monst;
reset(arg){
if(arg)return;

set_light(1);

short_desc="In a secret alcove";
long_desc=
"You are in what seems to be an empty grave.  The rotten stench of death "+ 
"fills your nose, and there is a sick feeling that enters your soul here. "+
"A large, flat stone sits at the bottom of the grave.\n";

items=({
"stone","It looks like you might be able to lift it", 
"grave","It looks empty",

});
::reset(arg);

}

void init(){
           ::init();
           add_action("lift","lift");
           add_action("climb","climb");
           add_action("climb","leave");
           }

int climb(string str) {
                      write("You leave the grave.\n");
    this_player()->move_player("leaves the grave",GPATH+"w_nave1.c");
    return 1;
                      }

int lift(string what) {
                      if(what=="stone") {
                      write("A rather LARGE Zombie appears!!\n");
 monst=CO("/players/wilbie/graveyard/monsters/big_zombie.c");
 MO(monst,"/players/wilbie/graveyard/window1");
                           

return 1;
                      }
notify_fail("Lift what?\n");
return 0;
}
