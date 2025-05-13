inherit "/room/room";
#include "/players/wilbie/def.h"
  reset(arg){
  if(!arg){

  set_light(1);
   short_desc="A large room";
  long_desc=
  "You have come to a large room.  Huge pillars of fire bellow out of "+
  "bronze cauldrons, and the screams of tortured souls pour from the flames. "+
  "The smell of death fills your nostrils, and your feeling of nausia is "+
  "overcome only by your fear of the huge Pit Fiend who makes a home of the "+
  "room!\n";

  items=({
  "cauldrons","They are rather large and hollow.\n"+    
  "Maybe you could fit in there",
  "cauldron","It is rather large and hollow.\n"+
  "Maybe you could fit in there",
  "Maybe you could fit in there",
  "pillars","They are large pillars of flame",
  "bronze","They are glowing from the heat",
  "souls","You cannot see the souls in the flames",
  "flames","They are the fires of hell you suspect",
  "fires","They burn very hot",
  "home","Only a Pit Fiend could call this home",
  "room","It is a room filled with flaming bronze cauldrons",
  "nostrils","You try to see your own nostrils and fail",
  "screams","You can't see sound",
  "flame","It is the fires of hell you suspect",
  "fire","It is the fire of eternal damnation!!",
  });

  smell="You almost choke on the smell of burning, rotted flesh!\n";
  dest_dir=({
  GPATH+"hell4","down",
  });

   clone_list=({
   1,1,"pit fiend","/players/wilbie/graveyard/monsters/pit_fiend",0
   });
  }
::reset(arg);
  }


void init() {
   ::init();
add_action("enter","enter");
add_action("enter","search");
}

int enter(string str) {
if(str=="cauldron") {
write("You are pulled into the cauldron!\n");
this_player()->move_player("down the cauldron",GPATH+"doom1");
return 1;
}
  else
if(str=="cauldrons") {
write("You are pulled into the cauldron!\n");
this_player()->move_player("down the cauldron",GPATH+"doom1");
return 1;
}
notify_fail("What do you mean?\n");
return 0;
}
