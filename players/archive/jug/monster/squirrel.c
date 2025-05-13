inherit "/obj/monster";

reset(arg) {
  object ob;

  ::reset(arg);
  if(arg) return;
  set_name("squirrel");
  set_short("A black and red squirrel");
  set_long("The squirrel is accumulate nuts for the hard winter.\n");
  set_race("mammal");
  set_level(1);
  set_al(50);
  set_wc(2);
  set_ac(2);

  ob = clone_object("obj/food");
  ob->set_name("hazelnut");
  ob->set_alias("nut");
  ob->set_short("A hazelnut");
  ob->set_long("This is a fresh and good looking hazelnut.\n");
  ob->set_value(50);
  ob->set_weight(1);
  ob->set_strength(5);
  ob->set_eater_mess("CRACK ... Hmmm ... You feel better now.\n");
  ob->set_eating_mess(" audibly eats a nut. CRACK !? Gnam ...\n");
  transfer(ob, this_object());
  return 1;
}
