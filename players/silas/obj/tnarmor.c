inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("skin");
  set_type("armour");
  set_ac(3);
  set_short("Tnoggoth's skin");
  set_long("Strong spikes protrude from this armor, and you know that will be of great\nhelp in a battle.\n");
  set_value(5000);
  set_weight(2);
  return 1;
}

