inherit "players/cashimor/inherit/hostile";
#include "/players/cashimor/include/float.h"
#include "/players/cashimor/include/extinguish.h" // changed moonchild no ;'s

reset(arg) {
  if(!arg) {
    timer=3;
    damage=5;
    survivor="allows_breathing";
    envname="water";
    saymsg="seems to be unable to breathe.";
    wrtmsg="You can't breathe!";
  }
  float_down();
  ::reset(); /* Galadriel 121293: needed for clone_list */
}

init() {
  ::init();
  if(!nodanger) extinguish();
  add_action("take_breath","take");
}

take_breath(str) {
object air;
  if(!str) {
    notify_fail("Take what?\n");
    return 0;
  }
  if((str!="breath")&&(str!="breath of air")) {
    notify_fail("Take what?\n");
    return 0;
  }
  if(present("breath_of_air",this_player())) {
    write("You already have your lungs full!\n");
    return 1;
  }
  if(!nodanger) {
    write("That would be very stupid!\n");
    return 1;
  }
  air=clone_object("players/cashimor/objects/breath");
  transfer(air,this_player());
  write("You take a big breath of air.\n");
  say(this_player()->query_name()+" takes a big breath of air.\n");
  return 1;
}
