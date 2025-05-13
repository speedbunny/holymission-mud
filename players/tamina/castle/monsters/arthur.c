/*  This is Arthur, son of Uther Pendragon  */

inherit "obj/monster";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if (!arg) 
  {
     set_name("King Arthur");
     set_alt_name("arthur");
     set_alias("king");
     set_short("King Arthur");
     set_long(
  "This is the noble King Arthur.  A wise, and venerable old man,\n"+
  "yet still possessing energy and vitality that would surprise any\n"+
  "able warrior.  Many lines of care, and worry line his brow, where\n"+
  "there rests the King's Crown, upon a thick shock of grey hair.\n");
     set_level(75);
     set_race("human");
     set_gender(1);
     set_al(750);
     set_aggressive(0);
     set_hp(15000);
     set_ac(100);
     set_spell_mess2("King Arthur makes a tremendous swipe at you!\n");
     set_spell_mess1("King Arthur swipes grandly at his opponent!\n");
     set_spell_dam(65);
     set_chance(30);
     add_money(10000);
     load_chat(7,
  ({"King Arthur smiles sadly at you.\n",
    "King Arthur sings a sorrowful song about his woes.\n",
    "Arthur swears: Damn that sorcreress sister of mine!!\n",
    "Arthur says: Beware that Demon .. the Darkling Lord!!\n"+
    "             He managed to defeat us by guile!\n" }) );
     set_own_env("earth");
  }
}

void init()
{
  ::init();
  AA("show", "show");
}
 
int show(string arg)
{
  object ob;
  ob = TP;
  
  if (arg == "grail to arthur" || arg == "chalice to arthur" ||
      arg == "grail to king" || arg == "holy grail to arthur" || 
      arg == "chalice to king")
  {
    if (present("grail", TP))
    {
      write(
"\nKing Arthur rejoices at the sight you have just shown him.\n\n");
      TRM (TO,
"Arthur says: Thou must be a worthy adventurer, "+ob->NAME+".\n"+
"             I shalt let thee retain that relic, in the hope that\n"+
"             thou canst fulfil more quests for the good of our lands.\n\n");
      shout(
"\nKing Arthur shouts: "+ob->NAME+" has just retrieved the Holy Grail !!\n"+
"                    All hail the newest Knight of our Round Table !!\n\n");

      write_file(PATH + "log/quest", ob->NAME+" showed the grail to Arthur at "+ctime(time())+".\n");

      if (ob->query_gender() == 2)
      {  
        ob->set_pretitle("Dame");
	ob->set_title("Honoured Lady of the Round Table\n");
	ob->set_quest("Holy_Grail");

	return 1;
      }
      else
        ob->set_pretitle("Sir");
	ob->set_title("Knight of the Round Table\n");
	ob->set_quest("Holy_Grail");

	return 1;
    }
    else
    {
      write("You do not have the Holy Grail to show to King Arthur !!\n");
      return 1;
    }
    NFAIL("Show what to whom?\n");
    return 0;
  }
}
