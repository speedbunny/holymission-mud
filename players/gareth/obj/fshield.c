#include "/players/gareth/define.h"

static object owner;
static string own_name;

set_owner(ob) {
  owner = ob;
  own_name = capitalize(owner->query_name());
  shadow(owner, 1);
}

can_put_and_get() { return 0; }

long() {
  tell_object(owner, TPN+" looked at you.\n");
  owner->long();
  if(TP->query_level() < 30) {
    write("You are terrified of "+owner->query_name()+"'s power and run away!!!!!\n\n");
    TP->run_away();
  }
  return 1;
}
