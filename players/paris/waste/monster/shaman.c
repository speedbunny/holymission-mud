#pragma strict-types
inherit "/obj/monster";

void reset(int arg) {
  object armour, weapon;
  int i;
  
  ::reset(arg);
  if (arg) 
    return;
  set_race("human");
  set_name("shaman");
  (random(2)) ? set_gender(1) : set_gender(2);
  set_level(80);
  set_ac(60);
  set_wc(60);
  set_hp(100000);
  set_alias("cultist");
  set_long("An old looking shaman.\n");
  set_number_of_arms(2);
  /* now to define some add bits and pieces like chat strings and 
   * and spells, including a call to see if the place has been warned
   */
  set_whimpy();
}
