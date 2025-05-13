#include "/players/ambrose/defs.h"
inherit"obj/monster";

object sword,armor,boot,helmet,ring,amulet,cloak,shield;

reset (arg){
  ::reset(arg);
  if(!arg) {
set_name("guard");
set_short("Street Guard");
set_long("This guard patrols the streets of Avalon to protect its citzens.\n"+
         "He has the determined look of a seasoned veteran.  He would not be\n"+
         "be easy to kill.\n");
set_level(30);
set_gender(1);
set_race("human");
set_hp(8000);
set_wc(35);
set_spell_mess1("The guard slices deep into his victim.\n");
set_spell_mess2("The guard slices deep into you and has trouble pulling his sword out.\n");
set_chance(50);
set_spell_dam(150);
set_aggressive(0);
load_chat(20,({
"The guard says: Hello stranger!\n",
"The guard asks: Can I help you?\n",
"The guard says: Be Careful, we have reports of some evil intruders here.\n",
"The guard says:In case of trouble, you can find sanctuary at the Cathedral.\n"}));
sword=clone_object("players/ambrose/avalon/weapons/sword");
armor=clone_object("players/ambrose/avalon/armour/chainmail1");
helmet=clone_object("players/ambrose/avalon/armour/helmet1");
ring=clone_object("players/ambrose/avalon/armour/ring1");
shield=clone_object("players/ambrose/avalon/armour/shield1");
amulet=clone_object("players/ambrose/avalon/armour/amulet1");
cloak=clone_object("players/ambrose/avalon/armour/cloak1");
boot=clone_object("players/ambrose/avalon/armour/boots1");
MOVE(sword,TO);
MOVE(armor,TO);
MOVE(helmet,TO);
MOVE(ring,TO);
MOVE(shield,TO);
MOVE(amulet,TO);
MOVE(cloak,TO);
MOVE(boot,TO);
init_command("powerup");
set_dead_ob(this_object());
set_ac(40);
}
}
monster_died(ob){
  write("You have slain one of the righteous guards of avalon!\n"+
        "You truly must be a evil person!\n");
  return 0;
}
