inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("bracers");
  set_short("Black bracers");
  set_long("A pair of hardened black bracers worn on the arms.\n");
  set_alias("bracers");
  set_type("armour");
  set_ac(2);
  set_weight(2);
  set_value(500);
}

query_summoner_wear() { return 1; }
