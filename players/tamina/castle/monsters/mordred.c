/*  This is Mordred, son of Morgan  */

inherit "obj/monster";

#include "/players/tamina/defs.h"

object sword,platemail,helmet,shield,pipe;
  
void reset(int arg) 
{
  ::reset(arg);
  if (arg) return;

     set_name("sir Mordred");
     set_alias("sir");
     set_alt_name("mordred");
     set_short("Sir Mordred");
     set_long(
  "Here stands an ominous figure, a full two-and-a-half metres tall.\n"+
  "He is devastatingly handsome, with fine shoulder-length blond hair,\n"+
  "piercing blue eyes, and smooth, unblemished skin.  However, despite\n"+
  "his obvious grace, poise and skill, an oppressive aura of malevolance\n"+
  "surrounds this usurping Knight of Arthur's Table.\n");
     set_level(45);
     set_race("human");
     set_gender(1);
     set_al(-900);
     set_wc(34);
     set_ac(24);
     set_hp(5000);
     set_dex(50);
     set_aggressive(1);
     set_spell_mess2("Sir Mordred deals you a devastating blow.\n");
     set_spell_mess1("Sir Mordred shows himself to be a competent warrior.\n");
     set_spell_dam(25);
     set_chance(10);
     add_money(2500 + random(2501));
     set_dead_ob(TO);
     load_chat(10,
  ({"Sir Mordred shifts his sword in it's sheath.\n",
    "Mordred says: Come with me stranger, and meet my beautiful mother.\n",
    "Mordred says: Thou shalt never find Merlin.\n"+
    "              The old fool hast long been dead.\n",
    "Mordred growls: Leave here at once, lest thee die!!\n",
    "Mordred says: Arthur is a lowly serf!  He is not the King of England.\n",
    "Sir Mordred glares stonily at you.\n"}) );
     load_a_chat(35,
  ({"Sir Mordred laughs at your obvious inexperience.\n",
    "Sir Mordred shouts a deafening war-cry !!\n",
    "Mordred screams: Thou art in league with Arthur!\n"+
    "                 Prepare to die, traitor !!\n"}) );

      sword = CLO(COBJ + "scabra");
     helmet = clone_object("/players/tamina/castle/obj/seeker");
     shield = CLO("obj/armour");
  platemail = CLO("obj/armour");
/*
       ring = CLO(COBJ + "drinker");
*/

  shield->set_name("golden shield");
  shield->set_ac(1);
  shield->set_weight(3);
  shield->set_size(3);
  shield->set_value(1000);
  shield->set_short("Golden Shield");
  shield->set_long(
  "This is a large, well-made shield fashioned from pure gold.  It has a\n"+
  "strange design engraved upon it, which looks remarkably like enchanted\n"+
  "runes...\n");
  shield->set_type("shield");

  platemail->set_name("golden platemail");
  platemail->set_alias("platemail");
  platemail->set_alt_name("mail");
  platemail->set_type("armour");
  platemail->set_weight(7);
  platemail->set_size(3);
  platemail->set_value(1750);
  platemail->set_ac(4);
  platemail->set_short("Golden Platemail");
  platemail->set_long(
  "This is a fine suit of Platemail fashioned from a pure gold.  You \n"+
  "imagine that this must contain some magical properties, due to the \n"+
  "strange choice of metals as armour...\n");

  MO(sword,    TO);
  MO(platemail,TO);
  MO(helmet,   TO);
  MO(shield,   TO);
/*
  MO(ring,     TO);
*/
  command("wear helmet");
  command("wear shield");
  command("wear platemail");

}

monster_died(ob) 
{
  TRM(E(TO),
    "\nSir Mordred spits his last breath at thee, as he descends\n"+
    "into the pits of Hell!\n");

  write("\nAs Mordred falls, you notice a strange pipe among his possessions.\n");

  pipe = clone_object(COBJ + "quest/pipe");
  MO (pipe, TO);

}
