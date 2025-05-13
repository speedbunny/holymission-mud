#define PR "players/bobo/krooms/mountains/specialpath2e"

#include "/players/mangla/defs.h"
reset(arg) {
  if (!arg) {
    set_light(1);
  }
} /* reset */

init() {
  add_action("nw","northwest");
  add_action("sw","southwest");
  if(living(this_player())) {
    tell_room(PR,
     this_player()->query_name()+" arrives on the other side of the gap.\n");
  }
} /* init */

short() {
    return "A path";
}

long(str) {
   if(!str) {
     write("You are standing on a large plateau with a gap in the middle.\n" +
           "Here at this point the gap isn't very large, though you would\n" +
           "not be able to jump over it.\n"+
           "   There are two obvious exits: northwest and southwest.\n");
     return;
   }
   if(str=="gap") {
     write("It is too wide to jump over it.\n");
     return;
   } 
   if(str=="other side") {
     PR->long();
   }
} /* long */

id(str) { return !str || str=="gap" || str=="other side"; }

sw() {
   TP->MOVEP("southwest#players/bobo/krooms/mountains/specialpath1w");
  return 1;
}

nw() {
   TP->MOVEP("northwest#players/bobo/krooms/mountains/specialpath3w");
  return 1;
}

