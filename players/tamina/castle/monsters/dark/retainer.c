inherit "/obj/monster";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if(!arg) 
  {
	set_name("Darkling Retainer");
	set_alias("retainer");
	set_race("darkling");
	set_level(25);
	set_short("A Retainer of the Lord of Darkness");
	set_long(
"This is an esteemed retainer of the Lord of Darkness.\n"+
"The supernatural figure stands 6 foot-tall, being animated\n"+
"of pure darkness, that stares right into the depths of your soul.\n");
	set_al(-500);
	set_aggressive(1);
	set_spell_mess1("The Darkling Retainer throws a Bolt of Darkness at you!!!\n");
	set_spell_mess2("A Bolt of Darkness fires from the fist of the Darkling Retainer!!\n");
	set_chance(9);
	set_spell_dam(20 + random(40));
	add_money(1750);
	load_a_chat(30, 
     ({"The Darkling Retainer sneers at your mortality!\n",
       "The Retainer makes a rasping noise in what might be his throat.\n",
       "The Darkling's eyes glow with an eerie red fire!\n", }) );

    }

}
