/* TRASHCAN.C - Programmed? by Whisky */
/* 230993: Ethereal Cashimor: Should be /obj/thing and ungettable */

#include "/obj/lw.h"
inherit "obj/thing";
   
reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("trashcan");
    set_alias("trash");
    set_short("A little trashcan");
    set_long(lw("A little trashcan, where you can put in the items which have "
              + "no value and help us to clean the shop. Just type <trash> "
              + "<itemname> to get rid of your worthless item.\n"));
    set_can_get(0);
  }
}

init() {
  add_action("trash","trash");
  ::init();
}

trash(arg) {
     object ob;
     int i;
     if(!arg) {
        write("Trash what ??\n");
     return 1;
     }
     if(!(ob=present(arg,this_player()))) {
        write("You don't have that object.\n");
      return 1;
     }
     if(transfer(ob, environment())) {
	write("You can't trash that!\n");
	return 1;
     }
     destruct(ob);
     write("Suddenly, a coin flips out from the trashcan "+
           "into your pocket.\n");
     this_player()->add_money(1); 
     return 1;
}
     

