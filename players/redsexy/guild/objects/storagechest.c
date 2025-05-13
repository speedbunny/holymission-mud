#include "/players/redsexy/guild/guilddefs.h"

int weight;

id(arg) {
  return arg == "chest" || arg == "large chest" ||
    arg == "storage chest";
}

short() { return "A large chest"; }

long() {
  int i;
  object inv;
  write("    This chest serves as a large storage bin. If you have extra\n");
  write("items to leave here for other Summoners that need them, please\n");
  write("put them in here. If you need an item from the chest, feel free\n");
  write("to take it.\n");
  inv = all_inventory(TO);
  if(!sizeof(inv))
    write("        Chest contains:\nNothing.\n");
}

init() {
  add_action("put", "put");
}

put(arg) {
  int i;
  object inv;
  if(arg == "all in chest") {
    inv = all_inventory(TP);
    for(i = 0; i < sizeof(inv); i++)
      if(inv[i]->short() && inv[i]->NAME)
	command("put " + inv[i]->NAME + " in chest", TP);
    return 1;
  }
}

can_put_and_get() { return 1; }
add_weight(arg) {
  weight += arg;
  return 1;
}
query_weight() { return weight; }
