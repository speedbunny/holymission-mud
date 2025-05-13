inherit "obj/monster";
object coat, beaker, scroll;

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if (!arg) 
  {
     set_name("Bernard the Alchemist");
     set_alt_name("bernard");
     set_alias("alchemist");
     set_short("Bernard the Alchemist");
     set_long("A man in a white coat\n");
     set_level(23);
     set_wc(26);
     set_ac(12);
     set_race("human");
     set_gender(1);
     set_al(-150);
     set_spell_mess2("Bernard throws a vial of acid in your face!\n");
     set_spell_mess1("Bernard throws a vial of acid across the room.\n");
     set_spell_dam(39);
     set_chance(15);
     add_money(2500);
     set_dead_ob(TO);
     load_chat(19,
  ({"Bernard madly spits in your face !!\n",
    "Bernard runs around the room, banging his head on the walls.\n",
    "Bernard the Mad Alchemist shouts: ArOoGgA aRoOgGa\n",
    "Bernard flarghs you feebly.\n",
    "Bernard stirs a vial vigorously.\n",
    "Bernard tickles you playfully.\n"+
    "You fall down laughing.\n",
    "Bernard smacks Roger on the head!\n",
    "Bernard says: Oopsie!  What are you doing 'ere?\n" }) );
     load_a_chat(20,
  ({"Bernard pokes you fiercely in the eye !!\n",
    "Bernard jumps up and down on your foot !!\n",
    "Bernard does the hand-jive while you swing your weapon above his head.\n",
    "Bernard says: I'm going to dance on your grave...\n",
    "Bernard searches in his Lab Coat for a secret weapon...\n" }) );

      coat = CLO (COBJ + "l_coat");
    beaker = CLO (COBJ + "beaker");    
    scroll = CLO (COBJ + "inst");

    MO (coat, TO);
    MO (beaker, TO);
    MO (scroll, TO);
    command("wear coat", TO);

  }
}

monster_died(ob)
{
  TRM (E (TO),
   "\nBernard sighs: Ach, there I go again - dying.\n");
}

