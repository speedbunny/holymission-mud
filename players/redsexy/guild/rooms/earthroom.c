inherit "room/room";

#include "/players/redsexy/guild/guilddefs.h"

int dropped;
object caught_by;

reset(arg) {
  if(arg) return;
  set_light(1);
  property = "no_teleport";
  short_desc = "Trial of Earth";
  long_desc =
    "    A huge cavern stretches out and above you in all directions,\n" +
    "its rocky walls soaring up beyond your sight. Monstrous pillars\n" +
    "of stone rise up from the ground and extend upwards, joining the\n" +
    "ceiling impossibly high above. There is a small doorway carved\n" +
    "into the rock of the nearest cavern wall.\n";
  no_obvious_msg = "";
  
  items = ({
    "cavern", "This is an enormous stone cavern",
    "walls", "Made of solid rock, the walls are huge",
    "doorway", "A small doorway carved into the rock",
    "pillars", "Columns of stone stretching from ground to ceiling",
    "ground", "The rocky ground of the cavern",
    "ceiling", "The rocky ceiling of the cavern, far above you",
    "rock", "Reddish-brown rock making up the entire cavern",
    "wall", "There is a doorway in the nearest wall",
  });
}

exit(obj) {
  if(caught_by == obj) {
    write("You drop the boulder, which disintegrates.\n");
    say(obj->NAME + " drops the boulder, which disintegrates.\n");
  }
  caught_by = 0;
  dropped = 0;
}
  

init() {
  ::init();
  add_action("enter", "enter");
  add_action("catch_it", "catch");
  add_action("my_look", "look");
  if(interactive(TP)) {
    dropped = 0;
    caught_by = 0;
    call_out("begin", 10);
  }
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

my_look(arg) {
  if(!arg) {
    long();
    if(caught_by == TP) write("    You are holding up a massive boulder.\n");
    else if(caught_by)
      write("    " + caught_by->NAME + " is holding up a massive boulder.\n");
    return 1;
  }
  else if(arg == "at boulder" && dropped) {
    write("A huge boulder that has dropped from the ceiling.\n");
    return 1;
  }
}

catch_it(arg) {
  if(arg == "boulder") {
    if(dropped) {
      if(!caught_by) {
	write("You close your eyes and hold out your arms as the boulder\n");
	write("comes crashing down, and suddenly feel enormous weight\n");
	write("from the impact.\n");
	say(TP->NAME + " catches the boulder!\n");
	caught_by = TP;
	return 1;
      }
      write("The boulder has already been caught.\n");
      return 1;
    }
  }
  write("Catch what?\n");
  return 1;
}

begin() {
  if(ENV(TP) == TO) {
    write("A voice echoes: Strength...\n");
    call_out("hold", 5);
  }
  return 1;
}

hold() {
  if(ENV(TP) == TO) {
    if(!dropped) {
      write("You look up and see an enormous boulder loosen and drop\n");
      write("from the ceiling!\n");
      dropped = 1;
      call_out("hold", 5);
      return 1;
    }
    else if(caught_by == TP) {
      if(TP->HP > 4) {
	write("The weight of the boulder crushes you!\n");
	TP->ADDHP(TP->HP / -2);
	TP->show_hp();
	call_out("hold", 5);
	return 1;
      }
      success();
      return 1;
    }
    write("The boulder lands, crushing you through the ground!\n");
    TP->ADDHP(TP->HP / -2);
    TP->MOVEP("through the ground with a crunch#" + PATH + "room");
    dropped = 0;
    return 1;
  }
}

success() {
  object earthob;
  write("Suddenly the boulder is gone!\n");
  earthob = clone_object(PATH + "objects/trial");
  MOVE(earthob, TP);
  earthob->set_type("earth");
  TP->ADDHP(TP->MAXHP / 2);
  caught_by = 0;
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

