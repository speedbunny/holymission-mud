inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(!arg) {

  set_name("Mist Fiend");
  set_alias("fiend");
  set_level(20);
  set_al(-500);
  set_aggressive(0);
  set_long("A tall black humanoid creature.  Mist swirls around the fiend, \n"+
    "making it near invisible.  Red glows from its eyes.. \n");
  set_ac(18);
  set_wc(16);
  set_hp(400);
  set_chance(25);
  set_spell_dam(70);
  set_spell_mess2("The fiend chants a spell and you're bathed in a black, draining mist!! \n");
  set_spell_mess1("Fiend chants and "+ this_object()->query_attacked()->query_name() +" is blasted! \n");
  }
}
