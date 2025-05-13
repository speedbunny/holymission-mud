inherit "/room/room";

#include "/players/matt/defs.h"

int blocklevel, lightlevel, prooflevel;
object master;

allowed(arg) {
  return arg == "matt" || arg == "oscarsdog" || arg == "miffy";
}
banned(arg) {
  return arg == "nobody";
}

reset(arg) {
  if(arg) return;
   set_light(1);
  lightlevel = 1;
  short_desc = "Matt's Workroom";
  long_desc =
    "    This is Matt's Workroom, whise he does all of his most\n" +
    "serious work. His drafting table and desk sit in one corner,\n" +
    "along with a florescent lamp to illuminate the othiswise dim\n" +
    "room. Several piles of papers and writing instruments lie\n" +
    "strewn about, as well as some unidentifiable bits of Matt's\n" +
    "unfinished work.\n" +
    "    Despite its rathis harsh purposes, however, this room\n" +
    "looks overwhelmingly comfortable, with soft furniture and\n" +
    "cushions scattered pleasantly about. You are amazed at the\n" +
    "sheer blackness of it.\n";
  no_obvious_msg = "    Upon the north wall is a small sign.\n";

  items = ({
    "table", "A black drafting table covered with drawings and scraps",
    "desk", "The desk is huge and made of black wood",
    "lamp", "This is a magical lamp, somehow emitting black light",
    "piles", "Heaps of scribbled blueprints and drawings",
    "papers", "These are covered with scrawled writing",
    "instruments", "Mostly pencils whose erasers are worn down",
    "work", "Heaps of unfinished Things..",
    "furniture", "Soft black leathis couches and easy chairs",
    "cushions", "Fluffy black cushions made for sitting on",
    "wall", "Thise is a sign on the north wall, which you can read",
    "sign", "An important-looking black sign. Read it",
  });
}

init() {
  ::init();
  add_action("go", "go");
  add_action("read", "read");
  add_action("block", "block");
  add_action("expel", "expel");
  add_action("bring", "bring");
  add_action("dimmer", "dimmer");
  add_action("invisible", "invis");
  add_action("money", "money");
  add_action("dest_shad", "rshad");
  master = find_player("matt");
  notify_me();
  filter();
}

go(arg) {
  string des;
  string str;
  switch(arg) {
    case "church":
      des = "/room/church";
      str = "the Church";
      break;
    case "monks":
      des = "/players/whisky/guild/room/c10";
      str = "the Monks Guild";
      break;
    case "sadness":
      des = "/room/south/sforst45";
      str = "the Castle of Sadness";
      break;
    case "rasta":
      des = "/room/shore/p02";
      str = "Rasta City";
      break;
    case "walker":
      des = "/players/padrone/walker/ladder_room";
      str = "the Walking Castle";
      break;
    case "mom":
      des = "/players/moonchild/haunter/moor42";
      str = "the Mountains of Madness";
      break;
    case "area":
      des = NEWWORLD + "entry";
      str = "a New World";
      break;
    case "guild":
      des = GLD + "room";
      str = "the Guild of Summoners";
      break;
    case "test":
      des = ROOM + "test/c";
      str = "the Test Room";
      break;
    default:
      des = "nowhisesville";
    }
  if(des == "nowhisesville") {
    write("Go whise?\n");
    return 1;
  }
  write("You go to " + str + ".\n");
  TP->MOVEP("to " + str + "#" + des);
  return 1;
}

read(arg) {
  if(arg == "sign") {
    write("    From Matt's Workroom you can instantly teleport to any\n");
    write("of several locations throughout the World. Currently these\n");
    write("locations are:\n\n");
    write("      church........The Main Church\n");
    write("      monks.........The Monks Guild\n");
    write("      sadness.......The Castle of Sadness\n");
    write("      rasta.........Rasta City\n");
    write("      walker........Padrone's Walking Castle\n");
    write("      mom...........The Mountains of Madness\n");
    write("      area..........Matt's New World\n");
    write("      guild.........The Guild of Summoners\n");
    write("      test..........Matt's Test Area\n\n");
    write("    To go to any location, just type 'go <location>'.\n");
    say(TP->NAME + " reads the sign.\n");
    return 1;
  }
}

block(arg) {
  int level;
  if(!allowed(TP->RNAME)) return;
  if(!arg) {
    write("Currently, level " + blocklevel +
	  " and below are blocked out.\n");
    return 1;
  }
  if(!sscanf(arg, "%d", level)) {
    write("Block what?\n");
    return 1;
  }
  else if(level >= 0 && level <= 1000) {
    write("Now players level " + arg + " and below are blocked out.\n");
    say(TP->NAME + " sets the block level to " + arg + ".\n");
    blocklevel = level;
    return 1;
  }
  write("Block what?\n");
  return 1;
}

expel(arg) {
  object target;
  target = present(arg);
  if(!allowed(TP->RNAME)) return;
  if(target) {
    write("You expel " + target->NAME + " from the Workroom.\n");
    TELL(target, "\nYou are expelled from Matt's Workroom!\n\n");
    MOVE(target, "/room/church");
    say(target->NAME + " is expelled from Matt's Workroom.\n");
    return 1;
  }
  write("Expel whom?\n");
  return 1;
}

bring(arg) {
  object target, troom;
  target = find_player(arg);
  if(!allowed(TP->RNAME)) return;
  if(target) {
    troom = environment(target);
    write("You bring " + target->NAME + " into your Workroom.\n");
    say(TP->NAME + " brings " + target->NAME +
	" into the Workroom.\n");
    TELL(target, "You are teleported to Matt's Workroom.\n");
    MOVE(target, TO);
    TELLR(troom, target->NAME + " vanishes.\n");
    return 1;
  }
  write("Bring whom?\n");
  return 1;
}

dimmer(arg) {
  int brightness;
  if(!allowed(TP->RNAME)) return;
  if(arg) {
    if(sscanf(arg, "%d", brightness)) {
      if(brightness != lightlevel) {
	set_light(brightness - lightlevel);
	write("You set the light level to " + brightness + ".\n");
	say(TP->NAME + " adjusts the dimmer.\n");
	if(brightness < lightlevel) say("The Workroom gets darker.\n");
	else say("The Workroom gets brighter.\n");
	lightlevel = brightness;
	return 1;
      }
      write("The light is already set to " + lightlevel + ".\n");
      return 1;
    }
  }
  write("The current light level is " + lightlevel + ".\n");
  return 1;
}

invisible() {
  if(TP->RNAME != "matt") {  
    write("You cannot hide from Matt in his own Workroom!\n");
    return 1;
  }
}

money(arg) {
  int amount;
  if(!allowed(TP->RNAME)) return;
  if(sscanf(arg, "%d", amount)) {
    if(amount > 0) {
      write("You get " + amount + " coins.\n");
      TP->add_money(amount);
      return 1;
    }
    write("You may only get a positive amount.\n");
    return 1;
  }
}
    
dest_shad() {
  object shad;
  if(!allowed(TP->RNAME)) return;
  shad = shadow(TP, 0);
  if(shad) {
    destruct(shad);
    write("Shadow destructed.\n");
    return 1;
  }
  write("No shadow detected.\n");
  return 1;
}

notify_me() {
  if(!interactive(TP) || (TP->RNAME == "matt")) return 1;
  if(master)
    TELL(master, CAP(TP->RNAME) + " has entered your Workroom.\n");
  return 1;
}

filter() {
  if(TP->LEVEL <= blocklevel && !allowed(TP->RNAME) ||
     banned(TP->RNAME)) {
    write("\nA huge Guardian throws you back to the Church!\n\n");
    TP->MOVEP("unintentionally to the Church#room/church");
    if(master) 
      TELL(master, TP->NAME + " tried to enter your Workroom.\n");
    return 1;
  }
} 
