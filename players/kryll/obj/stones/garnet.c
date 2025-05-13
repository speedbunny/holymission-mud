inherit "/players/kryll/inherit/std_gem";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("garnet");
  set_short("garnet");
  set_long("A deep-red garnet. It looks like it could have some "+
    "value.\n");
  set_alias_list(({ "gem", "Garnet" }));
  set_value(100 + random(151));
}
