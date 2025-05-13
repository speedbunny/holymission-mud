inherit "/players/kryll/inherit/std_gem";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("diamond");
  set_short("diamond");
  set_long("A beautiful clear diamond. It sparkles in the light "+
    "and looks like it could be worth some money.\n");
  set_alias_list(({ "Diamond", "gem" }));
  set_value(3000 + random(501));
}
