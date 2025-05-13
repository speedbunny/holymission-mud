string short_desc, name, mess, alias, long_desc, info;
int value, heal, weight;

id(str) {
 return str == name || str == alias;
}

short() {
  return short_desc;
}

long() {
  write(long_desc);
}

init() {
 add_action("eat"); add_verb("eat");
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
  info = "This is edible. Type 'eat "+alias+"' to consume.\n";
}

query_info() { return info; }
query_name() { return name; }
query_weight() { return weight; }
query_value() { return value; }

eat(str) {
 if(id(str)) {
  write("You eat "+str+".\n");
  if(mess)
   write(mess);
  call_other(this_player(),"heal_self", heal);
  call_other(this_player(),"add_weight", -weight);
  destruct(this_object());
  return 1;
 }
}

drop() { return 0; }
get() { return 1; }
