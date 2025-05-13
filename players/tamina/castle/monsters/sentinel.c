/*  This is a Sentinel in Camelot*/

inherit "obj/monster";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if(!arg) 
  {

     set_name("sentinel");
     set_short("A Sentinel");
     set_long(
"This is a tall, supernatural guard, that stalks the halls of Camelot, at\n"+
"Morgan's commands.\n");
     set_level(18);
     set_gender(1);
     set_al(-500);
     set_aggressive(1);
     set_wc(15 + random(7));
     set_ac(14);
     set_spell_mess2("The Sentinel weaves his fingers in an arc round your head!\n");
     set_spell_mess1("The Sentinel has cast a spell at his opponent!\n");
     set_spell_dam(20 + random(21));
     set_chance(19);
     set_move_at_reset(1);
     add_money(2000);
     load_a_chat(25, 
  ({"The Sentinel warns you not to interfere with Morgan's business.\n",
    "The Sentinel asks you politely to leave.\n",
    "The Sentinel wiggles his fingers in a concentrated blur.\n",
    "The Sentinel gets angry!\n" }) );

    }

}
