inherit "/obj/thing";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("glowing gem");
  set_short("Glowing gem");
  set_long("This sparkling gem glows brightly with bluish light.\n");
  set_alias("gem");
  set_alt_name("blue gem");
  set_weight(1);
  set_value(1000);
  set_light(3);
}

query_quest_item() { return 1; }
