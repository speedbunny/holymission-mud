inherit "obj/thing";

#include "/players/cashimor/include/skills.h"


reset(arg) {
  ::reset(arg);
  if(!arg) {
    set_name("test");
    set_short("A test object");
    set_long("Cashimor's test object");
    set_can_get(1);
    set_value(100);
    set_weight(1);
  }
}

init() {
  ::init();
  add_action("test_it","test");
}

test_it() {
  write("players/cashimor/objects/skills"->check_skill(this_player(),
       SS_PLAY_INSTRUMENT,SS_MEDIUM));
  return 1;
}
