inherit "obj/monster";
#include "/players/unuscione/def.h"
reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Little Jewelsy");
   set_alt_name("jewel");
   set_level(11);
   set_hp(500);
   set_ep(250);
   set_gender(2);
   add_money(10000);
   set_race("polished rock");
   set_short("blah");
   set_long("A huge rock eating creature, Always a good solid monster.\n");
   set_wc(5);
   set_ac(8);
   set_size(2);
}
