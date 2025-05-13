inherit "obj/monster";
 
void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

  set_name("forest goblin");
  set_race("goblin");
  set_alias("goblin");
  set_short("A Forest Goblin");
  set_level(7);
  set_aggressive(1);
  set_ac(3);
  set_wc(12);
  set_al(-300);

}

