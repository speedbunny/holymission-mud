#include "/players/sargon/define.h"
inherit "/obj/std_shadow";

varargs int attack( object theWeapon, int nrOfHand ) {
   	write("++++++++++ ");
	TP->attack();
  if (TP->query_level() > 23) {
	write("########## ");
	TP->attack();
	TP->attack();
   	return 1;
	}
   if (TP->query_level() > 27) {
	write("!!!!!!!!!! ");
	TP->attack();
	return 1;
	}
  }
int berzerk_shad() {return 1; }
