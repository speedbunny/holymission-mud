inherit "room/room";

#include "/players/redsexy/guild/guilddefs.h"

int times, which, correct;
string direc;

reset(arg) {
  if(arg) return;
  set_light(1);
  property = "no_teleport";
  short_desc = "Trial of Wind";
  long_desc =
    "    You find yourself standing on a tiny platform suspended by\n" +
    "sheer magic above a gaping cavern below. The doorway through\n" +
    "which you entered is nowhere to be seen.\n";
  no_obvious_msg = "";
  
  items = ({
    "platform", "A small wooden platform floating over a huge cavern",
    "cavern", "A yawning cavern; you cannot see the bottom",
  });

  direc = ({
    ({ "north", "n" }),
    ({ "northeast", "ne" }),
    ({ "east", "e" }),
    ({ "southeast", "se" }),
    ({ "south", "s", }),
    ({ "southwest", "sw" }),
    ({ "west", "w" }),
    ({ "northwest", "nw" }),
  });
}

init() {
  ::init();
  add_action("brace", "brace");
  add_action("jump", "jump");
  if(interactive(TP)) {
    which = 0;
    times = 0;
    correct = 0;
    call_out("begin", 10);
  }
}

brace(arg) {
  int i;
  if(arg) {
    for(i = 0; i < sizeof(direc); i++)
      if((direc[i][0] == arg) || (direc[i][1] == arg)) {
	write("You brace yourself " + direc[i][0] + ".\n");
	if(which && (i == (which - 1))) correct = 1;
      }
    return 1;
  }
  write("Brace which direction?\n");
  return 1;
}

jump() {
  write("You jump off the platform into the chasm below.\n");
  TP->MOVEP("down into the chasm#" + PATH + "room");
  return 1;
}

begin() {
  if(ENV(TP) == TO) {
    write("A voice echoes: Agility...\n");
    write("BRACE YOURSELF!\n");
    call_out("game", 5);
  }
  return 1;
}

game() {
  if(ENV(TP) == TO) {
    which = (random(8) + 1);
    write("A strong gust of wind begins to gather from the " +
	  direc[which - 1][0] + ".\n");
    call_out("test", 3);
  }
  return 1;
}

test() {
  object windob;
  if(ENV(TP) == TO) {
    if(!correct) {
      write("The wind knocks you off of the platform into the " +
	    "abyss below!\n");
      write("You fall...and land with a THUD.\n");
      say(TP->NAME + "is blown off the platform!\n");
      TP->MOVEP("down into the chasm#" + PATH + "room");
      return 1;
    }
    write("The mighty wind blows all around you, but you stand firm.\n");
    times++;
    correct = 0;
    which = 0;
    if(times < 6) {
      call_out("game", 3);
      return 1;
    }
    write("A voice echoes: Well done...\n");
    windob = clone_object(PATH + "objects/trial");
    MOVE(windob, TP);
    windob->set_type("wind");
    return 1;
  }
}

query_busy() {
  int i, flag;
  object inv;
  inv = all_inventory(TO);
  for(i = 0; i < sizeof(inv); i++)
    if(inv[i] && interactive(inv[i])) flag = 1;
  return flag;
}

