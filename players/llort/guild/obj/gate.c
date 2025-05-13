inherit "obj/thing";

#include "../tune.h"

object source,place;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("gate");
  set_alias("crack");
  set_short("A crack in the fabric of space");
}

init() {
  ::init();
  add_action("enter","enter");
}

enter(arg) {
  if(!source) dest();
  if(id(arg)) {
    write("As you enter the gate, the world vanishes.\n"+
          "Some moments later you arrive beside of "+
          source->query_name()+".\n");
    this_player()->move_player("into the gate",place);
    return dest();
  }
}

get() { return 0; }

long() {
  write("The crack seems to be a gate to "+source->query_name()+".\n");
}

set_gate(src) {
  if(!src || !src->query_player()) destruct(this_object());
  tell_room(environment(),"A crack apears in the fabric of space.\n");
  source=src;
  place=environment(src);
  call_out("chk_place",1);
  call_out("dest",60);
}

chk_place() {
  if(!source || place!=environment(source)) dest();
  call_out("chk_place",1);
}

dest() {
  tell_room(environment(this_object()),short()+" vanishes.\n");
  destruct(this_object());
  return 1;
}
