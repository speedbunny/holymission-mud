
#include "std.h"
#define	TP	this_player()
#define TO	this_object()
#define TPRN	TP->query_real_name()

string to_kill;

init() {
   add_action("set_kill","punish");
   if (to_kill && 
	(TPRN==to_kill && !TP->query_ghost() ||
       "monsters"==to_kill && TP->query_npc()) ) {
      write("You have been forbidden to enter Herp's workroom.\n"
	  + "Now you will be punished ...\n"
	  + "A blinding bolt of lightning flashes from the sky.\n");
      TP->attack_object(TO);
      TP->hit_player(10000);
      return 1;
   }
}

id(str) { return str=="punisher";  }
query_name() { return "Workroom of Herp"; }
query_npc() { return 1; }
query_pronoun() { return "it"; }
set_kill(str) {
  if (TPRN=="herp" && str) { to_kill=str; return 1; }
}
