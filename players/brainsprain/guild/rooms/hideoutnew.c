#include "/include/defs.h"
#include "/players/brainsprain/guild/headers.h"
inherit "room/room";

object  board;
string  picklock, poison;

int query_property(string arg){
  switch(arg) {
  case "no_fight": return 1;
  case "has_fire": return 1;
  }
}

void reset(int arg) {

  int     i;
//  string  dir;
  string  p_color, p_strength;
  object  p;

//  dir      = GM->query_dir(1);
  poison   = DIR + "poison/poison";
  picklock = DIR + "obj/picklock";

  ::reset(arg);

  if(!present("board", TO))
    transfer(clone_object("/boards/guilds/thief_guild"), TO);
  if(!(present("picklock"))) {
    for (i = 0; i < random(3) + 1; i++) {
      move_object(clone_object(picklock), this_object());
    }
  }


  if(!(present("basilisk's eye"))) {
    for (i = 0; i < random(2) + 1; i++) {
      move_object(p = clone_object(poison), this_object());
      p->set_name("basilisk's eye");
      p->set_alias("poison");
      p->set_alt_name("vial");
      p->set_short("Basilisk's eye");
      p->set_long("A vial of poison, left here by some experienced thief.\n"
        + "You'll have to learn the art of poison-brewing yourself.\n");
      p->set_strength(5);
    }
  }

  if (arg)
    return;

  set_light(1);
  short_desc = "Thieves board room";
  long_desc  =
     "This is the thieves board room, where notes pertaining to thieves " +
     "are left. Other items are also left to help the other " +
     "thieves in the guild out.  A sputtering torch illuminates a scroll " +
     "that has recently been hung on the wall.\n";

  items = ({
    "room", "This is the guild board room",
    "scroll","The thieves code, perhaps you should READ it",
    "torch","The torch gives off a sickly greenish glow",
  });
}


void init() {
  ::init();
  add_action("read",  "read");
  add_action("guild", "guild");
  if((TP->query_immortal())
    || present("thiefsoul", TP)) {
    return;
  }
  else {
    write("You are not allowed in this place!\n");
    TP->MOVEP("is moved to the#room/church");
  }
}
   


int read(string arg){
  if(!arg) return 1;
  if(arg != "scroll" && arg != "code") {
    write ("Read what?\n");
    return 1;
  }
  else {
    cat("/players/brainsprain/guild/code");
    return 1;
  }
}

int guild(){

	if(TP->RNAME != "brainsprain"
        && TP->RNAME != "brainsprain") {
    return 1;
  }
  else
    TP->MOVEP("to the guild#" + ROOMDIR + "joinroom");
  return 1;
}
