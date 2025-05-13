
/* Gorlin, 4.4.1996 */

/* lvl is only 3 so that no exp-hunting is possible in */
/* player areas. */

inherit "obj/monster";
#include "/players/gorlin/brk_str.h"

reset (arg)
{
   ::reset (arg);
   if (arg) return;

   set_name("gargoyle");
   set_alt_name("statue");
   set_race("gargoyle");
   set_short("Winged Statue");
   set_long( brk_str (
            "A winged statue standing on a small stone pedestal. "+
            "It stares at you with cold stony eyes, and you can "+
            "feel a shimmer of intelligence inhabiting the stone "+
            "statue.\n", 64));
   set_level(3);
   set_n_wc(8);
   set_n_ac(5);
   set_gender(0);
   set_str(12);
   set_dex(10);
   set_con(14);
   set_int(4);
   set_wis(2);
   set_chr(4);
   set_hp(250);
   set_al(-80);
   set_aggressive(0);
}
 
