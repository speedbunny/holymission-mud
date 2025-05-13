inherit "/room/room";

#include "lw.h"
#include "/players/matt/defs.h"

#define RENT_COST (300 * TP->LEVEL)
#define STORE NWCITY + "rooms/lockstorage"

string renters;
object stuff;

reset(arg) {
  if(arg) return;
  renters = allocate(0);
  stuff = allocate(0);
  set_light(1);
  short_desc = "Locker Room";
  long_desc =
    "    The first thing you notice upon looking around this room\n" +
    "is the huge wall of lockers. There is a sign on the opposite\n" +
    "wall which looks important, but other than that everything\n" +
    "here looks rather ordinary.\n";

  dest_dir = ({
    NWCITY + "rooms/square", "north",
  });

  items = ({
    "wall", "An enormous wall full of lockers",
    "lockers", "Hundreds of black lockers set into a huge wall",
    "sign", "An important-looking sign that you could read",
    "opposite wall", "There is a sign on this wall",
  });
  property = ({"no_clean_up" , "no_teleport"});
}

init() {
  ::init();
  add_action("gostore", "gostore");
  add_action("read", "read");
  add_action("rent", "rent");
  add_action("store_obj", "store");
  add_action("claim_obj", "claim");
  add_action("list_objs", "list");
  add_action("rents", "rents");
  add_action("show", "show");
}
        
gostore(arg) {
  if(!arg) {
    if(!TP->query_immortal()) return;
    write("You go to the storage room.\n");
    TP->MOVEP("out of the locker room#" + STORE);
    return 1;
  }
}

read(arg) {
  if(arg == "sign") {
    write("    Welcome to Dyolf's Storage Facility. This is a place\n");
    write("where you can leave your things if you don't want others to\n");
    write("steal them. Commands:\n");
    write("  - rent locker: Reserves locker til next reboot (costs " +
	  RENT_COST + ").\n");
    write("  - store <obj> in locker\n");
    write("  - claim <obj> from locker\n");
    write("  - list locker: Shows you what you have stored\n");
    if(TP->RNAME == "matt") {
      write("  - rents:       Lists who has rented lockers here\n");
      write("  - show <name>: Shows you <name>'s stored stuff\n");
      write("  - gostore:     Takes you to the storage room\n");
    }
    write("\n    The management here would like you to know that we are\n");
    write("NOT responsible for loss or damage of your items.\n");
    write("Enjoy!  - Matt\n");
    return 1;
  }
  write("Read what?\n");
  return 1;
}

rent(arg) {
  int id_num;
  if(arg == "locker" || arg == "a locker") {
    if(!renters || member_array(TP->RNAME, renters) == -1) {
      if(TP->query_money() >= RENT_COST) {
	renters += ({ TP->RNAME });
	id_num = member_array(TP->RNAME, renters);
	stuff += ({ 0 });
	stuff[id_num] = allocate(0);
	TP->add_money(-1 * (RENT_COST));
	write("You rent out a locker until the next reboot.\n");
	return 1;
      }
      write("You do not have enough money.\n");
      return 1;
    }
    write("You have already rented a locker here.\n");
    return 1;
  }
  write("Rent what?\n");
  return 1;
}

store_obj(arg) {
  int id_num;
  object what;
  id_num = member_array(TP->RNAME, renters);
  if(id_num != -1) {
    if(arg) {
      what = present(arg, TP);
      if(what) {
	switch(transfer(what, STORE)) {
          case 0:
	    write("You store " + what->NAME + " in your locker.\n");
	    say(TP->NAME + " stores " + what->NAME + " in " + TP->POS +
		" locker.\n");
	    stuff[id_num] += ({ what });
	    break;
	  case 2:
	    write("You can't seem to store that in your locker.\n");
	    break;
	}
	return 1;
      }
      write("You are not carrying that.\n");
      return 1;
    }
    write("Store what?\n");
    return 1;
  }
  write("You have not rented a locker from here!\n");
  return 1;
}

claim_obj(arg) {
  int i, id_num, success;
  id_num = member_array(TP->RNAME, renters);
  if(id_num != -1) {
    if(arg == "all") {
      if(sizeof(stuff[id_num])) {
	while(sizeof(stuff[id_num]))
	  claim_obj(stuff[id_num][0]->NAME);
	return 1;
      }
      write("There is nothing stored in your locker.\n");
      return 1;
    }
    for(i = 0; i < sizeof(stuff[id_num]); i++)
      if(stuff[id_num][i] && stuff[id_num][i]->id(arg)) {
	switch(transfer(stuff[id_num][i], TP)) {
          case 0:
	    write("You claim " + stuff[id_num][i]->NAME + " from " +
		  "your locker.\n");
	    say(TP->NAME + " claims " + stuff[id_num][i]->NAME +
		"from " + TP->POS + " locker.\n");
	    stuff[id_num] = del_array(stuff[id_num], i);
	    success = 1;
	    break;
	  case 1:
	    write("You are carrying too much.\n");
	    success = 1;
	    break;
	}
	return 1;
      }
    if(!success) write("That is not stored in your locker.\n");
    return 1;
  }
  write("You have not rented a locker here!\n");
  return 1;
}

list_objs(arg) {
  int i, id_num;
  if(arg == "locker") {
    id_num = member_array(TP->RNAME, renters);
    if(id_num != -1) {
      write("Currently your locker contains:\n");
      if(!sizeof(stuff[id_num])) {
	write("  Nothing.\n");
	return 1;
      }
      for(i = 0; i < sizeof(stuff[id_num]); i++)
	write("  " + stuff[id_num][i]->SHORT + "\n");
      return 1;
    }
    write("You have not rented a locker here!\n");
    return 1;
  }
}

rents(arg) {
  int i;
  string names;
  if(arg || TP->RNAME != "matt") return;
  if(sizeof(renters)) {
    write("Lockers have been rented by:\n");
    names = "    ";
    for(i = 0; i < sizeof(renters); i++)
      names += (CAP(renters[i]) + ", ");
    write(lw(names + "\n"));
    return 1;
  }
  write("No one has rented a locker here.\n");
  return 1;
}

show(arg) {
  int i, id_num;
  if(TP->RNAME != "matt") return;
  id_num = member_array(arg, renters);
  if(id_num != -1) {
    if(sizeof(stuff[id_num])) {
      write("Items rented by " + CAP(renters[id_num]) + ":\n");
      for(i = 0; i < sizeof(stuff[id_num]); i++)
	write("  " + stuff[id_num][i]->NAME + "\n");
      return 1;
    }
    write(CAP(renters[id_num]) + " has nothing stored.\n");
    return 1;
  }
  write("That player has not rented a locker here.\n");
  return 1;
}
