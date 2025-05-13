#include "/players/matt/defs.h"

id(arg) { return arg == "eradicator"; }

init() {
  add_action("nuke", "eradicate");
  add_action("dump", "dumplist");
}

get() { return 1; }

reset(arg) {
  if(arg) return;
  set_heart_beat(1);
}

nuke(arg) {
  int which;
  object inv, obj;
  if(arg && sscanf(arg, "room %d", which)) obj = ENV(TP);
  else if(arg && sscanf(arg, "me %d", which)) obj = TP;
  else {
    write("Eradicate room <num> or me <num>\n");
    return 1;
  }
  inv = all_inventory(obj);
  if((sizeof(inv) >= which) && (which >= 1)) {
    write("You eradicate the object.\n");
    say(TP->SNAME + " eradicates an object.\n");
    destruct(inv[which - 1]);
    return 1;
  }
  write("Not found.\n");
  return 1;
}

dump(arg) {
  int i;
  string item, path;
  object inv, obj;
  if(arg == "room") obj = ENV(TP);
  else if(arg == "me") obj = TP;
  else {
    write("Dumplist on either \"room\" or \"me\".\n");
    return 1;
  }
  inv = all_inventory(obj);
  write("Inventory:\n");
  for(i = 0; i < sizeof(inv); i++) {
    if(inv[i]->SHORT) item = inv[i]->SHORT;
    else item = "Invisible object";
    path = file_name(inv[i]);
    printf("  %-2d - %s (%s)\n", (i + 1), path, item);
  }
  return 1;
}

heart_beat() {
  MOVE(TO, ENV(TO));
  return 1;
}

query_auto_load() { return OBJS + "tools/eradicator:"; }
