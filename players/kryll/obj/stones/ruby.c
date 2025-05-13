inherit "/players/kryll/inherit/std_gem";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("ruby");
  set_short("ruby");
  set_long("A gorgeous red ruby. It could be worth a lot.\n");
  set_alias_list(({ "gem", "Ruby" }));
  set_value(1750 + random(401));
}
