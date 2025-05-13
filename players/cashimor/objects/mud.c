inherit "obj/thing";
#include "/players/cashimor/monsters/fly.h"

object fly;

reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("pool");
set_alias("mud");
set_short("A pool of mud");
set_long("This is a smelly pool of mud.\n");
   set_can_get(0);
    move_object(this_object(),FLY_LOCATION);
  }
  if(!present("fly",environment(this_object()))) {
    fly=clone_object("players/cashimor/monsters/fly");
    move_object(fly,environment(this_object()));
  }
}

init() {
  ::init();
  add_action("smell_it","smell");
  if(!random(10)) {
    call_out("step_in",1);
  }
}

step_in() {
    write("You step in the pool of mud that's lying here.\n");
    say(this_player()->query_name()+" steps in the pool of mud "
      + "that's lying here.\n");
    this_player()->set_smell(FLY_SMELL);
}

smell_it(str) {
  if((!str)||((str!="pool")&&(str!="mud"))) {
    notify_fail("Smell what?\n");
    return 0;
  }
  say(this_player()->query_name()+" smells a pool of mud.\n");
  write(FLY_SMELL+"\n");
  return 1;
}
