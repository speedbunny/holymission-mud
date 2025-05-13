inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("scythe");
  set_short("A wicked Scythe");
  set_long("This magically sharpened weapon consists of a black shaft\n" +
           "fitted with a curved silver blade.\n");
  set_class(18);
  set_value(2500);
  set_weight(2);
}

query_summoner_wield() { return 1; }
