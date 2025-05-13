inherit "obj/monster";
#include "/players/tatsuo/def.h"
reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("Tatsuo Jr.");
    set_alt_name("tats");
   set_level(11);
   set_hp(500);
   set_ep(250);
   set_gender(1);
   add_money(10000);
   set_race("bad boy");
   set_short("Tats");
   set_long("A small little boy with a big grin on his face. He looks\n"+
            " very mischievious!  Beware of his cunning ways! \n");
   set_wc(5);
   set_ac(8);
   set_size(3);
}
