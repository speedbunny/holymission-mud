inherit "/players/kryll/inherit/std_gem";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("emerald");
  set_short("emerald");
  set_long("A striking green emerald. It has a bluish tint "+
    "to it and it looks quite valuable.\n");
  set_alias_list(({ "gem", "Emerald" }));
  set_value(1000 + random(301));
}
