inherit "/players/kryll/inherit/std_gem";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("amethyst");
  set_short("amethyst");
  set_long("A beautiful purple amethyst. It is a remarkable specimen "+
    "of a gem and looks to be quite valuable.\n");
  set_alias_list(({ "gem", "Amethyst" }));
  set_value(300 + random(151));
}
