inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
set_name("pocket protector");
  set_type("protector");
set_ac(0);
  set_short("Pocket protector");
  set_long("This is the nerd's pocket protector.\nIt is filled with pens and pencils, along with a ruler.\n");
  set_value(100);
set_weight(0);
  set_info("pocket (created by Mr. Jake using Uranus' Wand)");
  return 1;
}

query_objmaker() { return 1; }
