inherit "obj/monster";
object wig, funnel, powder;

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if (!arg) 
  {
     set_name("Roger the Alchemist");
     set_alt_name("roger");
     set_alias("alchemist");
     set_short("Roger the Alchemist");
     set_long(
  "This is a mad-looking old man, who wanders around the room, peering\n"+
  "into odd vials, and giving them a stir now and then.  He looks as\n"+
  "though he could not harm anyone...But don't be misled into thinking\n"+
  "he won't defend himself!!\n");
     set_level(28);
     set_wc(25);
     set_ac(12);
     set_race("human");
     set_gender(1);
     set_al(-100);
     set_spell_mess2("Roger throws a vial of poison at you !!\n");
     set_spell_mess1("Roger throws a vial of poison across the room !!\n");
     set_spell_dam(30);
     set_chance(15);
     set_dead_ob(TO);
     add_money(2500);
     load_chat(19, 
  ({"Roger slaps Bernard on the face!\n",
    "Roger smiles sweetly at you.\n",
    "Roger does a funny impression of Merlin the Wizard.\n",
    "Roger dances around the room like a disco-duck !!\n",
    "Roger says: Bloomers !  Bloomers !\n",
    "Roger swears under his breath...\n",
    "Roger bounces around the room.\n\n"+
    "B O I I N G\n  B O I I N G \n    B O I I N G\n" }) );
     load_a_chat(30,
  ({"Roger hits you with his head !!\n",
    "Roger twangs your ear !!\n",
    "Roger licks you on the nose.\n",
    "Roger runs away from you around the room.\n",
    "Rather luckily, Roger dodges your attack.\n" }) );

       wig = CLO (COBJ + "wig");
    funnel = CLO (COBJ + "funnel");
    powder = CLO (COBJ + "powder");

    MO(wig, TO);
    MO(funnel, TO);
    MO(powder, TO);
    command("wear wig");

  }
}

monster_died(ob)
{
  TRM (E (TO),
   "\nRoger says: Oh poopie !  I've gone and died again.\n");
}

