inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("sandals");
  set_short("Sandals");
  set_long("Soft black sandals for Summoners.\n");
  set_type("boot");
  set_ac(1);
  set_weight(1);
  set_value(100);
}

query_summoner_wear() { return 1; }
