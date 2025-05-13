inherit "room/room";

#include "/players/kryll/other/defs.h"

void reset(int arg){
  if(arg) return;

  set_light(1);
  short_desc = "At a spring";
  long_desc =
    "You are standing in front of a tiny spring. "+
    "This must be the spring of the river you followed up "+
    "to here. The water is fresh and clean and invites you "+ 
    "to drink some. There are some stones lying around.\n";

  items = ({
    "stones","Some heavy grey stones",
    "ground","You see some heavy stones lying in the grass",
    "grass","The grass is dew-drenched",
    "sky","You see the blue sky",
    "spring","You see a fresh water coming out of the ground",
    "water","You see yourself !!!!"
  });

  dest_dir = ({
    HOBBE + "path4","southeast"
  });

  ::reset(arg);
}

void init(){
  ::init();
  add_action("_search","search");
  add_action("_push","push");
  add_action("_push","move");
  add_action("_drink","drink");
}

status _push(string str){
  if(TO->id(str) {
    write("You can't move that !\n");
    return 1;
  }
  notify_fail("Push what?\n");
  return 0;
}

status search(string str){
  switch(str) {
    case "room" :
    case "area" :
      write();
      return 1;
    default :
      notify_fail("Search what?\n");
      return 0;
  }
}

status drink(string str){
  switch(str) {
    case "water" :
    case "from spring" :
    case "some water" :
      write("You drink some fresh water.\n");
      say(TP->NAME+" drinks some water from the spring.\n");
      TP->drink_soft(1);
      return 1;
    default :
      notify_fail("Drink what?\n");
      return 0;
  }
}    
