/* LAMP.C - Programmed by Ethereal Cashimor */
/* 121094: Started programming */

inherit "obj/torch";
#include "/obj/lw.h"
#include "/players/cashimor/eternal/eternal.h"

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("lamp");
    set_short("A rusty lamp");
    set_long("This is a rusty lamp. It doesn't have much oil left in it.\n");
    set_weight(2);
    set_smell("The lamp smells pretty dusty. It may need to be cleaned.\n");
    set_fuel(10);
  }
}

init() {
  ::init();
  add_action("clean_it","clean");
}

clean_it(str) {
  if((!str)||(str!="lamp")) {
    notify_fail("Clean what?\n");
    return 0;
  }
  if(query_is_lit()) {
    write("You burn your fingers on the lamp.\n");
    say(lw(this_player()->query_name()+" tries to clean a lamp, but burns "
         + this_player()->query_possessive()+" hands.\n"));
    this_player()->hit_player(2);
    return 1;
  }
  if(!TEST_ETERNAL) {
    write("You don't seem to be able to remove the rust from the lamp.\n");
    say(lw(this_player()->query_name()+" tries to clean a lamp, but isn't "
         + "able to remove the rust.\n"));
    return 1;    
  }
  write("Ok.\n");
  return 1;
}

  
