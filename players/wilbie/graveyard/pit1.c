inherit "/room/room";
#include "/players/wilbie/def.h"
  reset(arg){
  if(!arg){

  set_light(1);
  short_desc="A deep pit";
  long_desc=
  "You find yourself in a large pit.  The stench of death is a bit stronger "+
  "than you expected, and you feel a little faint... "+
  "The only visible exits are up and down.  The stench of decay seems to rise "+
  "from the hole.  There is a message on the wall, written in what looks a "+
  "lot like blood...\n";

  items=({
  "hole","A dark hole leading to who knows where..",
  "message","You need to read the message",
  "demons of great power.  They have traveled from the depths of hades "+
  "to take command of this once sacred place.  I, Arturus Delmarco, "+
  "Knight of Thorin, shall now go down to my doom, taking as many of the "+
  "fiends as I can with me to the afterlife",
  "ladder","Luckily, you think you can get out",
  "wall","It has blood on it",
  "pit","It is a rather deep pit",
  "blood","It is very old blood, dry for years now",
  "walls","They are smooth rock",
  });

  smell="The smell of death makes you feel sick.";
  dest_dir=({
  "/players/wilbie/barriers/pit2","down",
  GPATH+"w_hole","up",
  });

  }
::reset(arg);
  }

void init() {
   ::init();
   add_action("read","read");
}

int read(string str) {
   if(str == "message") {
   write(
   "The message reads...\n"+
   "I Thorin, Paladin of Illumitar, have met my doom in this place \n"+
   "of evil.  I shall venture down into the dark pit and attempt to \n"+
   "take as many of the evil creatures as I can, with me to the \n"+
   "afterlife!!\n"
   );
   return 1;
}

notify_fail("Read what?");
return 0;
}
