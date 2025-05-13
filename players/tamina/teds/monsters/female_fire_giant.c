inherit "obj/monster";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

  set_name("female fire giant");
  set_alias("female");
  set_race("giant");
  set_gender(2);
  set_long("A Female Fire Giant Scout.\n"+
           "She looks quite mean.\n");
  set_level(14);
  set_wc(20);
  set_ac(5);
  set_al(-150);
  set_aggressive(1);
}
