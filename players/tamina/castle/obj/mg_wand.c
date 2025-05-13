inherit "obj/weapon";

#include "/players/tamina/defs.h"

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return 0;
 
  set_name("red wand");
  set_alias("wand");
  set_short("A Red Wand");
  set_long("A small, red wand, with a spidery scrawl etched on it.\n"); 
  set_class(3);
  set_type(3);
  set_value(100);
  set_weight(2);
  set_read("-=- K..l M.r..n -=-\n");
  set_hit_func(TO);
}

int weapon_hit(object attacker) 
{
  if (attacker->id("morgan")) 
  {
    write(
"\n   **               **  ********  ********  *******  **    **\n"+
"    **     ***     **   **    **  **    **  *        **    **\n"+
"     **   ** **   **    **    **  **    **  *******  ********\n"+
"      ** **   ** **     **    **  **    **        *  **    **\n"+
"       ***     ***      ********  ********  *******  **    **\n\n"+
"You see sparks fly from the tip of your wand to -=>SLAY<=- Morgan!\n");
    say(TPN+" -=>SLAYS<=- Morgan la Fey!!\n");
    return 50;
  }
}
