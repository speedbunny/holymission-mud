#include "/players/matt/guild/obdefs.h"
#include "/players/matt/guild/formulae.h"
#include "/players/matt/guild/functions.h"

object seeker, att;

id(arg) { return arg == "seeker_control"; }

init() {
  add_action("sgo",     "sgo");
  add_action("senter",  "senter");
  add_action("slook",   "slook");
  add_action("slookat", "slookat");
  add_action("slink",   "slink");
  add_action("sreturn", "sreturn");
  add_action("sname",   "sname");
  add_action("ssay",    "ssay");
  add_action("semote",  "semote");
  add_action("sfollow", "sfollow");
  add_action("ban",     "ban");
}

get() { return 1; }
drop() { return 1; }

sgo(arg) {
  int legal;
  string *dirs;
  object oldenv;
  if(arg) {
    switch(arg) {
      case "n": arg = "north"; legal = 1; break;
      case "north": legal = 1; break;
      case "ne": arg = "northeast"; legal = 1; break;
      case "northeast":	legal = 1; break;
      case "e":	arg = "east"; legal = 1; break;
      case "east": legal = 1; break;
      case "se": arg = "southeast"; legal = 1; break;
      case "southeast":	legal = 1; break;
      case "s":	arg = "south"; legal = 1; break;
      case "south": legal = 1; break;
      case "sw": arg = "southwest"; legal = 1; break;
      case "southwest":	legal = 1; break;
      case "w":	arg = "west"; legal = 1; break;
      case "west": legal = 1; break;
      case "nw": arg = "northwest"; legal = 1; break;
      case "northwest":	legal = 1; break;
      case "u":	arg = "up"; legal = 1; break;
      case "up": legal = 1; break;
      case "d":	arg = "down"; legal = 1; break;
      case "down": legal = 1; break;
    }
    if(!legal) dirs = ENV(seeker)->query_room("dest_dir");
    CHECK_ATTACK();
    CHECK_GHOST();
    CHECK_INTOX();
    CHECK_ARM();
    if(legal) {
      oldenv = ENV(seeker);
      if(command(arg, seeker)) {
	write("You command your Seeker to go " + arg + ".\n");
	if(ENV(seeker) != oldenv) {
	  CHECK_SP(SEEK_GO_SP);
	  dump_long(ENV(seeker));
	  return 1;
	}
	write("Your Seeker cannot seem to go that way.\n");
	return 1;
      }
      write("Your Seeker cannot find that exit.\n");
      return 1;
    }
    if(dirs) {
      if(member_array(arg, dirs) != -1) {
	oldenv = ENV(seeker);
	write("You command your Seeker to go " + arg + ".\n");
	command(arg, seeker);
	if(ENV(seeker) != oldenv) {
	  CHECK_SP(SEEK_GO_SP);
	  dump_long(ENV(seeker));
	  return 1;
	}
	write("Your Seeker cannot seem to go that way.\n");
	return 1;
      }
      write("Your Seeker cannot find that exit.\n");
      return 1;
    }
    write("Your Seeker can find no exits.\n");
    return 1;
  }
  write("Syntax: sgo <direction>\n");
  return 1;
}

senter(arg) {
  object oldenv;
  if(arg) {
    CHECK_ATTACK();
    CHECK_GHOST();
    CHECK_INTOX();
    CHECK_ARM();
    CHECK_SP(SEEK_ENT_SP);
    write("You command your Seeker to enter " + arg + ".\n");
    oldenv = ENV(seeker);
    command("enter " + arg, seeker);
    if(ENV(seeker) != oldenv) dump_long(ENV(seeker));
    else write("Your Seeker cannot seem to enter " + arg + ".\n");
    return 1;
  }
  write("Syntax: senter <object>\n");
  return 1;
}

slook(arg) {
  if(!arg) {
    CHECK_ATTACK();
    CHECK_GHOST();
    CHECK_INTOX();
    CHECK_ARM();
    CHECK_SP(SEEK_L_SP);
    write("You command your Seeker to look around.\n");
    command("look", seeker);
    TELLRS(ENV(seeker), seeker->SHORT + " looks around.\n", TP);
    dump_long(ENV(seeker));
    return 1;
  }
  write("Syntax: slook\n");
  return 1;
}

slookat(arg) {
  object target;
  if(arg) {
    CHECK_ATTACK();
    CHECK_GHOST();
    CHECK_INTOX();
    CHECK_ARM();
    CHECK_SP(SEEK_LA_SP);
    write("You command your Seeker to look at " + arg + ".\n");
    command("look at " + arg, seeker);
    target = present(arg, ENV(seeker));
    if(target) {
      TELL(target, seeker->SHORT + " looks at you.\n");
      TELLRS(ENV(seeker), seeker->SHORT + " looks at " + target->NAME +
	     ".\n", TP, target);
      dump_long(target);
    }
    return 1;
  }
  write("Syntax: slookat <object>\n");
  return 1;
}

slink() {
  CHECK_ATTACK();
  CHECK_GHOST();
  CHECK_INTOX();
  CHECK_ARM();
  CHECK_SP(SEEK_LINK_SP);
  if(seeker->query_link()) {
    write("You disconnect the Seeker's mind from your own.\n");
    seeker->set_link(0);
    return 1;
  }
  write("You link the Seeker's mind to your own.\n");
  seeker->set_link(1);
  return 1;
}

sreturn() {
  if(ENV(seeker) != ENV(TP)) {
    CHECK_ATTACK();
    CHECK_GHOST();
    CHECK_INTOX();
    CHECK_ARM();
    CHECK_SP(SEEK_RET_SP);
    write("You command your Seeker to return to you.\n");
    TELLR(ENV(seeker), seeker->SHORT + " vanishes.\n");
    seeker->set_follow();
    MOVE(seeker, ENV(TP));
    say(seeker->SHORT + " materializes before you.\n");
    return 1;
  }
  write("Your Seeker is already here.\n");
  return 1;
}

sname(arg) {
  if(ENV(seeker) == ENV(TP)) {
    CHECK_ATTACK();
    CHECK_GHOST();
    CHECK_INTOX();
    CHECK_ARM();
    CHECK_SP(SEEK_NAME_SP);
    if(arg) {
      write("You name your Seeker '" + arg + "'.\n");
      seeker->set_short(arg + " [" + TP->SNAME + "'s Seeker]");
    }
    else {
      if(seeker->SHORT != TP->SNAME + "'s Seeker") {
	write("You unname your Seeker.\n");
	seeker->set_short(TP->SNAME + "'s Seeker");
      }
      else {
	write("You have not named your Seeker.\n");
	return 1;
      }
    }
    seeker->set_long("A lean, low-built, four-legged beast whose " +
		     "keen eyes\n" +
		     "scan the area vigilantly.\n");
    return 1;
  }
  write("Your Seeker is not here.\n");
  return 1;
}

ssay(arg) {
  if(arg) {
    CHECK_ATTACK();
    CHECK_GHOST();
    CHECK_INTOX();
    CHECK_ARM();
    CHECK_SP(SEEK_SAY_SP);
    TELLR(ENV(seeker), seeker->SHORT + " says: " + arg + "\n");
    return 1;
  }
  write("Syntax: ssay <message>\n");
  return 1;
}

semote(arg) {
  if(arg) {
    CHECK_ATTACK();
    CHECK_GHOST();
    CHECK_INTOX();
    CHECK_ARM();
    CHECK_SP(SEEK_EMOT_SP);
    TELLR(ENV(seeker), seeker->SHORT + " " + arg + "\n");
    return 1;
  }
  write("Syntax: semote <emote>\n");
  return 1;
}

sfollow(arg) {
  object target, leader;
  if(!arg) {
    leader = seeker->query_follow();
    if(leader) {
      CHECK_ATTACK();
      CHECK_GHOST();
      CHECK_INTOX();
      CHECK_ARM();
      CHECK_SP(SEEK_FOL_SP);
      write("You command your Seeker to stop following " +
	    leader->NAME + ".\n");
      seeker->set_follow();
      return 1;
    }
    write("Your Seeker is not following anyone.\n");
    return 1;
  }
  if(!seeker->query_follow()) {
    target = present(arg, ENV(seeker));
    if(target) {
      if(living(target)) {
	CHECK_ATTACK();
	CHECK_GHOST();
	CHECK_INTOX();
	CHECK_ARM();
	CHECK_SP(SEEK_FOL_SP);
	seeker->set_follow(target);
	write("You command your Seeker to follow " + target->NAME + ".\n");
	return 1;
      }
      write("That is not a living thing.\n");
      return 1;
    }
    write("Your seeker cannot find " + CAP(arg) + ".\n");
    return 1;
  }
  leader = seeker->query_follow();
  write("Your Seeker is already following " + leader->NAME + ".\n");
  return 1;
}

ban(arg) {
  if(arg == "seeker") {
    if(ENV(seeker) == ENV(TP)) {
      CHECK_ATTACK();
      CHECK_GHOST();
      CHECK_INTOX();
      CHECK_ARM();
      CHECK_SP(SEEK_BAN_SP);
      write("You banish your Seeker.\n");
      say(TP->SNAME + " gestures towards " + TP->POS +
	  " Seeker, banishing it to its own Plane.\n");
      seeker->destroy_me(1);
      return 1;
    }
    write("Your Seeker is not here.\n");
    return 1;
  }
}

dump_long(obj) {
  int i;
  object inv;
  inv = all_inventory(obj);
  TELL(TP, "\n-- Seeker --\n");
  if(obj->query_room("long_desc")) TELL(TP, obj->query_room("long_desc"));
  else {
    obj->long();
    for(i = 0; i < sizeof(inv); i++)
      if(inv[i]->extra_look()) write(inv[i]->extra_look() + ".\n");
  }
  for(i = 0; i < sizeof(inv); i++)
    if(inv[i]->SHORT && (inv[i] != seeker))
      TELL(TP, inv[i]->SHORT + ".\n");
  return 1;
}

orient(obj) {
  seeker = obj;
  return 1;
}
