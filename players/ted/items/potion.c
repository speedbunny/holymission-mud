#include "std.h"

string short_desc, name, mess, alias, long_desc, info;
int value, heal, weight;

reset(arg) {
 if(arg) return 1;
  set_info();
}

id(str) {
 return str == name || str == alias || str == "potion";
}

short() {
  return short_desc;
}

long() {
  write(long_desc);
  return 1;
}

init() {
 add_action("drink"); add_verb("drink");
}

set_name(n) { name = n; }
set_alias(a) { alias = a; }
set_short(s) { short_desc = s; long_desc = s+".\n"; }
set_long(l) { long_desc = l; }
set_mess(m) { mess = m; }
set_weight(w) { weight = w; }
set_value(v) { value = v; }
set_heal(h) { heal = h; }
set_info(i) {
 if(i)
  info = i;
 else
  info = "This is a potion. Type 'drink <potion>' to consume.\n";
}

query_info() { return info; }
query_name() { return name; }
query_weight() { return weight; }
query_value() { return value; }

drink(str) {
 if(id(str)) {
  write("You drink "+str+".\n");
  if(mess)
   write(mess);
  call_other(this_player(),"heal_self", heal);
  call_other(this_player(),"add_weight", -weight);
  say(call_other(this_player(),"query_name")+" drinks "+alias+".\n");
  destruct(this_object());
  return 1;
 }
}

drop() { return 0; }

get() { return 1; }
