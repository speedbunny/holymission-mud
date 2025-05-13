inherit "/obj/monster";
object amulet;

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;

	set_name("Darkling Prince");
	set_alias("prince");
	set_race("darkling");  
      	set_gender(1);
	set_short("A Prince of Darkness");
	set_long(
"This menacing character stands a full seven feet tall, a figure of pure\n"+
"darkness gazing placidly at you, through tiny specks of red fire as \n"+
"eyes.  His body seems to a cluster of dissembling shadows...\n");
	set_level(33);
	set_size(4);
	set_wc(30);
	set_ac(19);
	set_al(-750);
	set_aggressive(1);
	set_spell_mess1("The Darkling Prince shoots bolts of darkness across the room !!\n");
	set_spell_mess2("The Darkling Prince shoots bolts of darkness at you !!\n");
	set_spell_dam(20 + random(50));
	set_chance(21);
	add_money(2500);

	amulet = CLO ("obj/armour");

    amulet->set_name("amulet of darkness");
    amulet->set_type("amulet");
    amulet->set_ac(1);
    amulet->set_size(0);
    amulet->set_weight(3);
    amulet->set_value(600);
    amulet->set_short("Amulet of Darkness");
    amulet->set_long(
"This strangely magical amulet seems to suck the light \n"+
"out of the room you are in...\n");
    amulet->set_arm_light(-1);

      MO (amulet, TO);
      command("wear amulet");

}
