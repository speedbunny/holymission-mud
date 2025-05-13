inherit "/players/kryll/inherit/std_gem";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("sapphire");
  set_short("sapphire");
  set_long("A marvelous blue sapphire. It looks quite valuable.\n");
  set_alias_list(({ "gem", "Sapphire" }));
  set_value(800 + random(251));
}
