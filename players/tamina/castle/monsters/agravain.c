/*  This is Sir Agravain  */

#include "/players/tamina/defs.h"

inherit "obj/monster";
  int count;
  object chainmail,helmet,shield,cloak,boots,sword;

reset(arg) {
  ::reset(arg);
  if(!arg) {
  count = 0;

     set_name("Sir Agravain");
     set_alt_name("sir");
     set_alias("agravain");
     set_short("Sir Agravain");
     set_long(
  "This is Sir Agravain, the friend and ally of the Usurper, Sir Mordred.\n"+
  "He is not particularly tall, not even reaching two metres.  He has \n" +
  "a wily, and cunning look on his face, and wears a limp moustache.\n"+
  "His eyes glint mischievously as you look at him.\n");
     set_level(30);
     set_race("human");
     set_gender(1);
     set_al(-500);
     set_aggressive(0);
     set_hp(1950);
     set_wc(30);
     set_ac(20);
     set_whimpy(25);
     set_spell_mess2("Sir Agravain pokes you in the eye!!!\n");
     set_spell_mess1("Sir Agravain pulls a dirty trick!!\n");
     set_spell_dam(20);
     set_chance(5);
     random_move(1);
     add_money(2500 + random(2001));
     load_chat(5, ({
  "Sir Agravain sneers at you.\n",
  "Agravain appears startled as you look at him.\n",
  "Agravain asks: Art thou with the fiend, Arthur?\n",
  "Agravain asks: What art thou contriving here?\n" }) );
     load_a_chat(35, ({
  "Sir Agravain calls for the guards to aid him!\n",
  "Agravain calls: To arms! To arms, men!!\n",
  "Sir Agravain screams: Leave here, villainous dog!!\n" }) );

  chainmail = CLO ("obj/armour");
  helmet = CLO ("obj/armour");
  shield = CLO ("obj/armour");
  cloak = CLO ("obj/armour");
  boots = CLO ("obj/armour");
  sword = CLO (COBJ + "rapier");
  
  chainmail->set_name("chainmail");
  chainmail->set_alias("mail");
  chainmail->set_type("armour");
  chainmail->set_short("Silver Chainmail");
  chainmail->set_long("A splendid set of brightly polished silver chainmail.\n");
  chainmail->set_weight(6);
  chainmail->set_size(3);
  chainmail->set_value(1500);
  chainmail->set_ac(3);

  helmet->set_name("helmet");
  helmet->set_type("helmet");
  helmet->set_short("Silver Helmet");
  helmet->set_long("A crested helmet made of fine silver.\n");
  helmet->set_weight(2);
  helmet->set_size(3);
  helmet->set_value(900);
  helmet->set_ac(1);

  shield->set_name("shield");
  shield->set_type("shield");
  shield->set_short("Silver Shield");
  shield->set_long("A shield made out of solid silver, with a family emblem "+
                   "engraved upon it.\n");
  shield->set_weight(3);
  shield->set_size(3);
  shield->set_value(1000);
  shield->set_ac(1);

  cloak->set_name("cape");
  cloak->set_type("cloak");
  cloak->set_short("Heavy Cape");
  cloak->set_long("A well knitted woolen cape, that would offer considerable "+
                  "protection.\n");
  cloak->set_weight(2);
  cloak->set_size(3);
  cloak->set_value(700);
  cloak->set_ac(1);

  boots->set_name("boots");
  boots->set_type("boot");
  boots->set_short("Silver Boots");
  boots->set_long("A heavy pair of boots made out of fine silver.\n");
  boots->set_weight(4);
  boots->set_size(3);
  boots->set_value(800);
  boots->set_ac(1);

  MO(chainmail,TO);
  MO(helmet,TO);
  MO(shield,TO);
  MO(cloak,TO);
  MO(boots,TO);
  MO(sword,TO);

  command("wear chainmail");
  command("wear helmet");
  command("wear shield");
  command("wear cloak");
  command("wear boots");
  command("wield sword");

    }

}

heart_beat() 
{
  if (++count > 4) 
  {
    random_move();
    count = 0;
  }
  ::heart_beat();
}
