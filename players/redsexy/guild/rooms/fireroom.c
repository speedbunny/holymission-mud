inherit "room/room";

#include "/players/redsexy/guild/guilddefs.h"

int killed;
object priest, demon, sword;

reset(arg) {
  if(arg) return;
  set_light(1);
  property = "no_teleport";
  short_desc = "Trial of Fire";
  long_desc =
    "    You wipe your brow as flames lick at you. This place is very\n" +
    "hot and smoky; though there are no proper walls, you find yourself\n" +
    "surrounded by virtual walls of flame. You can see a small doorway\n" +
    "shielded from the fires nearby.\n";
  no_obvious_msg = "";
  
  items = ({
    "flames", "Extremely hot, unnatural fires",
    "fires", "Bright, unnatural flames surround you",
    "walls", "Walls of fire",
    "flame", "Extremely hot, unnatural fire",
    "doorway", "There is a doorway protected from the fire",
  });
}

exit(obj) {
  if(!interactive(obj)) return;
  if(sword) {
    write("The fiery sword disappears in a burst of flame.\n");
    destruct(sword);
  }
  if(demon) destruct(demon);
  if(priest) destruct(priest);
}

init() {
  ::init();
  killed = 0;
  add_action("enter", "enter");
  if(interactive(TP)) call_out("begin", 10);
}

enter(arg) {
  if(arg == "doorway") {
    write("You enter the doorway.\n");
    TP->MOVEP("through the doorway#" + PATH + "room");
    return 1;
  }
  write("Enter what?\n");
  return 1;
}

begin() {
  if(ENV(TP) == TO) {
    write("A voice echoes: Integrity...\n");
    call_out("bring", 5, 0);
  }
  return 1;
}

bring(arg) {
  if(ENV(TP) == TO) {
    if(!arg) {
      TELLR(TO, "A red-robed priest materializes before you.\n");
      priest = clone_object(PATH + "creatures/firepriest");
      MOVE(priest, TO);
      sword = present("flamesword", priest);
      call_out("bring", 10, 1);
    }
    else {
      TELLR(TO, "Flames spring up as a Firedemon phases in.\n");
      demon = clone_object(PATH + "creatures/firedemon");
      MOVE(demon, TO);
    }
  }
  return 1;
}

success() {
  object fireob;
  fireob = clone_object(PATH + "objects/trial");
  MOVE(fireob, TP);
  fireob->set_type("fire");
  write("A voice echoes: Well done...\n");
  return 1;
}

query_busy() {
  int i, flag;
  object inv;
  inv = all_inventory(TO);
  for(i = 0; i < sizeof(inv); i++)
    if(inv[i] && interactive(inv[i])) flag = 1;
  return flag;
}

set_killed(arg) { killed = arg; }
     
query_killed() { return killed; }
