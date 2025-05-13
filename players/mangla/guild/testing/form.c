#include "/players/mangla/defs.h"

/* Blowing bubbles.  No, not really, but I though I would mess with your ming
   a little.  Er, that was supposed to be mind, not ming.  Anyway, this
   spell creates a force bubble of protection for the player, allowing them
   to float above the room.  It can be left at will, or will time out and
   self-destruct.  For best results, eat these instructions before they
   self-destruct.
  I changed the name from blowing bubbles to forming spheres. 
  Placed in the game 1.15.98.
*/


int query_delay() {
  return 3;
}


int main(string str) {
  object bub;
  if(!str) {
  notify_fail("Syntax: form sphere\n");
    return 0;
  }

  if(!this_player()->query_legend_level()) {
    write("You lack the necessary experience for this ability.\n");
    return 1;
  }

  if(TP->SP <= 255 || TP->WIS < 30) {
    write("You lack the preparation for this ability.\n");
    return 1;
  }

  if(ENV(TP)->id("sphere")) {
   write("You are already in a sphere of protection!\n");
    return 1;
  }

  TP->ADDSP(-200);
  bub=clone_object("/players/mangla/guild/obj/sphere");
  MOVE(bub,ENV(TP));
  MOVE(TP,bub);
  TELLR(ENV(bub), TP->NAME+" creates a sphere from the Force and "+
    "places "+TP->OBJ+"self inside.\n");
  write("You concentrate the Force and create a sphere of protection.\n");
  return 1;
}
