
inherit "obj/monster";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg){
    ::reset();
    set_name("page");
    set_race("human");
    set_gender(1);
    set_alias("slave");
    set_alt_name("man");
    set_short("King's Page");
            set_long(
"This pimply faced teenager runs back in forth as he does errands for the "+
"Count.  He is wearing heavy overalls and loose purple tunic.  He has "+
"short page  cut hair and an innocent smile.  He carries a jug of wine "+
"under his arm.\n");
    set_level(5);
    set_hp(110);
    set_al(100);
    set_ac(1);
    set_wc(7);
    }
