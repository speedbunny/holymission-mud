inherit "obj/monster";
#include "/players/tatsuo/def.h"
reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Little Jewelsy");
   set_alt_name("jewelsy");
   set_level(11);
   set_hp(500);
   set_ep(250);
   set_gender(2);
   add_money(10000);
   set_race("polished rock");
   set_short("amazon");
   set_long("A cute little girl clad in Amazon garb. She is carrying\n"+
   "a little bow and some arrows. She has a wide grin on her\n"+
    "face.\n");
   set_wc(5);
   set_ac(8);
   set_size(2);
}
