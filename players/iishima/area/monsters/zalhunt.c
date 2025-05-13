inherit "obj/monster";
 
void reset(int arg){
::reset(arg);
if (arg) return;
set_name("Zalpur hunter");
set_level(11);
set_alias("hunter");
set_short("A Zalpur Hunter");
set_race("Zalpur");
set_long("The Zalpur Hunter is dressed all in black and wields a dangerous looking staff.  His body and face are covered with a cloak.  You can only see the faint outline of facial features from the imprint in the cloth.  You can tell that this is a very evil and very dangerous creature.  You do not want to run into him at night.\n");
set_gender(1);
set_hp(150);
set_aggressive(0);
}
