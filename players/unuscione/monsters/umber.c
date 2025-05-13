inherit "obj/monster";
#include "/players/unuscione/def.h"
reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("umber hulk");
   set_alt_name("hulk");
   set_level(11);
   set_hp(500);
   set_ep(250);
   set_gender(1);
   add_money(1000);
   set_race("umber hulk");
   set_short("A Lumbering Umber Hulk");
   set_long("A huge rock eating creature, Always a good solid monster.\n");
   set_wc(5);
   set_ac(8);
   set_size(6);
  set_aggressive(1);
}
