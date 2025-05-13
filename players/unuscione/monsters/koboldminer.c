inherit "obj/monster";
#include "/players/unuscione/def.h"
object pick;
reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("kobold miner");
   set_alias("kobold");
   set_alt_name("miner");
   set_level(2);
   set_size(2);
   set_hp(60);
   set_ac(1);
   set_wc(0);
   set_ep(50);
   set_al(-50);
   set_gender(1);
   add_money(75);
   set_race("kobold");
   set_short("A kobold miner");
   set_long("A kobold miner loaded down with mining equipment.\n");
   set_aggressive(0);
pick=CO("/players/unuscione/weapons/pickaxe");
MO(pick,TO);
init_command("wield pickaxe");
   return;
}
