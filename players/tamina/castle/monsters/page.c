/*  This is a Page Boy  */

inherit "obj/monster";

#include "/players/tamina/defs.h"

reset(arg) 
{
  ::reset(arg);
  if(!arg) 
  {
     set_name("pageboy");
     set_alias("boy");
     set_alt_name("page");
     set_short("A Pageboy");
     set_long(
      "A small boy dressed in rags that look as though they were once\n"+ 
      "smart and formal.\n");
     set_level(3);
     set_race("human");
     set_gender(1);
     set_al(900);
     set_aggressive(0);
     add_money(30);
     load_chat(19,
  ({"The little Pageboy cries sadly.\n",
    "The Pageboy says: Where has King Arthur gone?  Why won't he come back !?\n",
    "The Pageboy says: I wish some brave Knight would bring back Sir Galahad...\n",
    "The Pageboy mumbles something about why Camelot has been deserted for so long.\n",
    "The Pageboy warns you about the Dark Powers in Camelot...\n",
    "The Pageboy says: Poor Queen Guinevere...\n",
    "The Pageboy says: Please help us!! Save us from Morgan !!\n", }) );
     load_a_chat(9,
  ({"OUCH !!   Why are you hitting me ??\n",
    "The Pageboy cries sorely as you hit him again !\n",
    "The Pageboy says: You horrible big Meany !! I hope Morgan eats you alive.\n",
    "The Pageboy tells you: I am going to tell Sir Lancelot on you !!\n", }) );

   }

}
