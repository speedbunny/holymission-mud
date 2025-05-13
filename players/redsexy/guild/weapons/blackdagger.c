inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("black dagger");
  set_short("Black dagger");
  set_long("A small dagger with a black handle and silver blade\n");
  set_alias("dagger");
  set_class(5);
  set_value(200);
  set_weight(1);
}

query_summoner_wield() { return 1; }
