#include "/players/tamina/defs.h"

inherit "obj/monster";
object ob;

reset(arg) 
{
  ::reset(arg);
  if (!arg) 
  {
     set_name("Black Bear");
     set_alt_name("bear");
     set_short("A Black Bear");
     set_long(
"This bear stands a full thirteen feet tall, with its fur bristling on\n"+
"end, and long yellow teeth dripping saliva.  It's claws glint sharply in\n"+
"the pitch darkness.\n");
     set_level(29);
     set_race("bear");
     set_gender(1);
     set_al(-50);
     set_aggressive(1);
     set_wc(31);
     set_ac(12);
     set_spell_mess2("The Black Bear rakes your face with its sharp claws.\n");
     set_spell_mess1("The Black Bear swings its sharp claws !!\n");
     set_spell_dam(38);
     set_chance(10);
     set_dead_ob(TO);

    }

}

monster_died(ob)
{

  TRM (E (TO),
  "\nThe Black Bear lets out a deep growl, before keeling over...quite dead.\n\n");

  ob = CLO ("obj/armour");

  ob->set_name("bear fur");
  ob->set_alias("fur");
  ob->set_type("cloak");
  ob->set_ac(1);
  ob->set_short("Black Bear's Fur");
  ob->set_long("This is the fur from the Black Bear.\n"+
	       "You think that it probably offered very good protection \n"+
	       "to the Bear...when it was alive.\n");
  ob->set_weight(3);
  ob->set_value(900);
  ob->set_size(4);

  MO (ob, TO);
}
