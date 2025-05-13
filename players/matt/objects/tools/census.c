#include "/players/matt/defs.h"

id(arg) {
  return arg == "census taker" || arg == "taker";
}

short() {
  return "Census taker";
}

long() {
  write("A magical Census Taker. Type 'pop <wizname>' to see who is in\n");
  write("that wiz's area.\n");
}

get() { return 1; }

init() {
  add_action("pop", "pop");
}

pop(arg) {
  int i;
  object *players;
  if(arg) {
    players = users();
    for(i = 0; i < sizeof(players); i ++) {
      if(creator(ENV(players[i])) == arg) {
	printf("%-4d%-15s%40s\n", players[i]->LEVEL,
	       players[i]->SNAME,
	       file_name(ENV(players[i])));
      }
    }
    return 1;
  }
  write("Syntax: pop <wizname>\n");
  return 1;
}
