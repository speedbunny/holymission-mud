/*  This is the East side of the Courtyard */

#include "/players/tamina/defs.h"

inherit "room/room";
status has_cloned;
object *skels;  /* this is a list of 4 skeleton objects */

reset(arg) {
  has_cloned = 0;
  if (arg) return;
  skels = allocate(4);  /* this makes 4 spaces in the array of skeletons */
  set_light(1);
  short_desc = "Courtyard ";
  long_desc = 
    "You are at the East side of the courtyard, standing alongside the wall\n"+
    "sheltered from the blustery wind.  The ground is quite furrowed here,\n"+
    "with not as many weeds as other areas of the courtyard.\n";

  dest_dir = ({
    CROOMS + "ecourt3","north",
    CROOMS + "ecourt1","south",
    CROOMS + "court2","west",
  });

  items = ({
    "wall",
    "This is the stone wall, presumably of the East Wing of Camelot",
    "ground",
    "It looks as though many people have walked around over this particular "+ 
    "part of the ground",
     });

}

init() {
  ::init();
  call_out("skeletons",5,TP);  /* give this player as argument to func */
}

skeletons(obj) {

  int i;  
  int num_skels;  /* number of skeletons previously in the array */

  if (has_cloned == 1) return;

  /* if the player is no longer in the room now, return */
  if (!present(obj, TO)) return;

  if (num_skels == 4) return;  /* if there were already 4, return */

  /* we loop over the skeletons list to see what's there; if a slot
     is empty, we fill it with a skeleton */

  for(i = 0; i < 4; i++) {
    if(!skels[i]) {  /* if there is no skeleton */
      skels[i] = CLO(CMONS + "skel");  /* clone one to that slot */
      transfer(skels[i], TO);  /* move it here */

       has_cloned = 1;
    }
    else num_skels++;  /* otherwise increment the # of skeletons */
  }

  tell_room(TO,
	    "Suddenly, the furrowed earth starts to boil uncontrollably...\n"+
	    "Bleached bones begin to sprout up from the ground!!\n"+
	    "You suddenly notice skeletons standing in front of you,\n"+
	    "preparing to fight!!\n");
  return 1;
}
