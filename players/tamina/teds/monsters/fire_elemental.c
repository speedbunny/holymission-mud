inherit "obj/monster";
 
void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

  set_name("fire elemental");
  set_race("elemental");
  set_short("An Evil Fire Elemental");
  set_level(10);
  set_aggressive(1);
  set_whimpy(25);
  set_ac(5);
  set_wc(25);
  set_al(-300 );

call_other("/players/ted/random_armor", "make_item", elemental, 10);
}

