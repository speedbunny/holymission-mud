#include "/players/gareth/define.h"
inherit "/obj/npc";
reset(arg) {
    ::reset(arg);
    if(!arg) {
    set_name("coinman");
     set_short("Money Machine");
    set_level(5000);
    set_ac(1);
    set_dex(1);
    set_wc(1);
    set_hp(10);
    set_al(-5);
    set_aggressive(1);
    add_money(100000000);
}

}
