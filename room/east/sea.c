inherit "/room/room";
// inherit "players/cashimor/inherit/water";
 
#include <room_defs.h>

void reset(int arg) {
  ::reset(arg);
  if(arg) return; 
 
  set_light(1);
  short_desc = "All at sea";

  long_desc =
    "You are on a small wooden pier which leads " + 
    "out into the sea. This place looks like a " +
    "good place to dive. There is a small wooden " + 
    "sign fixed to the stage.\n";
 
  items = ({ 
    "stage", "A small wooden boat stage",
    "sign", "This is a sign, maybe you should read it",
  });
 
  dest_dir = ({
    EAST + "jetty", "west",
  });
 
//   nodanger=1;
//   floats="room/sea_bottom";
} 
 
void init() { 
  ::init();
  if(!random(4))
    TP->set_smell("You smell of salty seawater.");
  add_action("_dive", "dive");
  add_action("_read", "read");  
} 
 
status _read(string str) {
  if(str=="sign"){
    writelw(
      "This is the landing of the cargo junk to ezo island. "+
      "The ride is free but the captain asks that you refrain "+
      "from smoking and observe all safety precautions. "+
      "Have a safe and enjoyable voyage and try not to get "+
      "yourself killed on the island.\n"
    );
    return 1;
  }
 
  notify_fail("Read what?\n");
  return 0;
}
 
status _dive() {
  TP->move_player("down#" + EAST + "sea_bottom");
  return 1;
} 
