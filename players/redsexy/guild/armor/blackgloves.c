inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("gloves");
  set_short("Black gloves");
  set_long("Black gloves for Summoners.\n");
  set_type("glove");
  set_ac(1);
  set_weight(1);
  set_value(100);
}

query_summoner_wear() { return 1; }
