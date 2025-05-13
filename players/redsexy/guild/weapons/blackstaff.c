inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("black staff");
  set_short("Black staff");
  set_long("A gnarled black staff made of petrified wood.\n");
  set_alias("staff");
  set_class(8);
  set_value(500);
  set_weight(2);
}

query_summoner_wield() { return 1; }
