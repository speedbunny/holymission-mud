#include "/sys/levels.h"
#include "/players/saffrin/guild/defs.h"

int main(string target) {

  object *ob;
  int i, j;
  int total_invis;

  if (!target) {
    write("Usage : detect invisible\n");
    return 1;
  }

  if (target != "invisible") {
    write("You may only detect invisible objects.\n");
    return 1;
  }

  if(TP->SP < 25) {
    write("You are too weak to detect invisible persons.\n");
    return 1;
  }

  ob = all_inventory(ENV(TP));
  j = sizeof(ob);
  total_invis = 0;
  for (i=0; i<j; i++) {
    if (living(ob[i])) {
      if (ob[i]->query_invis() > TP->LEVEL) {
	if (ob[i]->query_invis() < L_APPR) {
	  write("You detect " + CAP(ob[i]->RNAME) + ".\n");
	  TP->ADDSP(-20);
	  total_invis++;
	}
      }
    }
    if(TP->SP < 20) {
      write("You have run out of power.\n");
      return 1;
    }
  }
  if(!total_invis)
    write("No invisible players detected.\n");

  return 1;
}
