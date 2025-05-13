inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_weight(1);
  set_value(5);
  set_id("scalp");
}

name_it(str) {
  alias_name="scalp of " + str;
  short_desc="Scalp of " + capitalize(str);
  long_desc="This is a grisly trophy of war, the scalp of " + capitalize(str) + ".\n";
}
