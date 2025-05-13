
inherit "/obj/monster";

void reset(int arg) 
{
  ::reset(arg);

  if (arg) return;
     set_name("tuna fish");
     set_alias("fish");
     set_race("fish");
     set_short("A big tuna fish");
     set_long("You see a big fish, looking strong but harmless.\n");
     set_level(15);
     set_has_gills();
     set_size(4);
     set_spell_mess1("");   
     set_spell_mess2("S C H W U P P.. the tuna fish hits you with its flipper");   
     set_chance(50);
     set_spell_dam(8);
}
