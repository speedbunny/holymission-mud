#pragma strict-types
inherit "/obj/monster";

void reset(int arg) {
  object armour, weapon;
  int i;
  
  ::reset(arg);
  if (arg) 
    return;
  set_race("orc");
  set_name("cultist");
  (random(2)) ? set_gender(1) : set_gender(2);
  set_level(50);
  set_ac(12);
  set_wc(30);
  set_alias("cultist");
  set_long("This strangly garbed person seems quite dangerous, as if on the "+
	   "verge of sudden movement.\n");
  set_number_of_arms(2);
  armour = clone_object("/obj/armour");
  armour->set_name("buckler");
  armour->set_alias("shield");
  armour->set_short("a small buckler shield");
  armour->set_size(3);
  armour->set_ac(1);
  armour->set_type("shield");
  transfer(armour, this_object());
  init_command("wear shield");
  /* just how many weapons should we start with */
  i = random(2)+1;
  while(i--) {
    weapon = clone_object("/obj/weapon");
    switch(random(3)) {
    case 0:
      weapon->set_name("short sword");
      weapon->set_type("sword");
      weapon->set_long("A slightly dull short-sword.\n");
      break;
    case 1:
      weapon->set_name("dagger");
      weapon->set_type("dagger");
    weapon->set_long("A long curved dagger.\n");
    break;
    case 2:
      weapon->set_name("spear");
      weapon->set_type("spear");
      weapon->set_long("A short spear.\n");
      break;
    }
    /* define some generic stuff for these weapons */
    weapon->set_class(8);
    weapon->set_weight(2);
    weapon->set_value(random(100));
    transfer(weapon, this_object());
    /* cant seem to rely on clone_list to wield the items */
    init_command("wield "+weapon->query_name());
  }
  /* now to define some add bits and pieces like chat strings and 
   * and spells, including a call to see if the place has been warned
   */
  set_whimpy();
}

void init() {
  object *inv;
  int i,j;

  ::init();
  inv = all_inventory(environment());
  for (i=0, j=sizeof(inv); i < j ; i++) {
    tell_object(inv[i]," See you\n");
  }
}
