inherit "room/room";

#include "/players/redsexy/guild/guilddefs.h"

int state;
string msgs;

reset(arg) {
  if(arg) return;
  set_light(1);
  property = "no_teleport";
  short_desc = "Trial of Water";
  long_desc =
    "    This is a very cramped cubic room. The doorway through which\n" +
    "you entered is now blocked by a magical force.\n" +
    "    You can see a small hole leading out.\n";
  no_obvious_msg = "";
  
  items = ({
    "hole", "A small hole which you think you could squeeze through",
    "room", "The room is extremely small",
    "doorway", "It is blocked",
    "door", "It is blocked",
  });
  msgs = ({
    "A voice echoes: Bravery...\n",
    "Suddenly water starts gushing in from above you!\n",
    "The water begins to rise rather quickly.\n",
    "The water is up to your knees.\n",
    "Your legs are entirely underwater.\n",
    "The water level reaches your waist.\n",
    "You are up to your chest in water.\n",
    "The level continues to rise, you will surely drown soon!\n",
    "The water level reaches your neck!\n",
    "Water floods into your mouth and nose!\n",
    "You still have a few seconds to escape!\n",
    "The water reaches the ceiling.\n",
  });
}

init() {
  ::init();
  add_action("enter", "enter");
  add_action("my_look", "look");
  if(interactive(TP)) {
    state = 0;
    call_out("drown", 10);
  }
}

enter(arg) {
  if(arg == "hole") {
    write("You dart through the hole.\n");
    TP->MOVEP("through the hole#" + PATH + "room");
    return 1;
  }
  write("Enter what?\n");
  return 1;
}

my_look(arg) {
  if(!arg && state > 1 && state < 11) {
    long();
    write("    There is a great deal of water here.\n");
    return 1;
  }
  else if(arg == "at water" && state > 1) {
    write("There is quite a lot of it now.\n");
    return 1;
  }
}

drown() {
  if(ENV(TP) == TO) {
    write(msgs[state]);
    if(state < 11) {
      state++;
      if(ENV(TP) == TO) call_out("drown", 5);
      return 1;
    }
    success(); 
    return 1;
  }
  return 1;
}

success() {
  object waterob;
  write("All of the water suddenly vanishes, leaving you gasping for air.\n");
  waterob = clone_object(PATH + "objects/trial");
  MOVE(waterob, TP);
  waterob->set_type("water");
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
