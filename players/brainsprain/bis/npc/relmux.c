inherit "obj/monster";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg){
    ::reset();
    set_name("relmux");
    set_race("human");
    set_gender(1);
    set_alias("man");
    set_alt_name("keeper");
    set_short("Relmux");
            set_long(
"Relmux is the shopkeeper of the Towpath Town Shop.  His hair is "+
"braided into many small braids and then tied back.  He is wearing "+
"a leather jerkin and long pantaloons.  He keeps one hand under the "+
"counter at all times and wears a silver star signifying his membership "+
"in the Towpath Magician's League\n");
    set_level(10);
    set_hp(230);
    set_al(400);
    set_ac(4);
    set_wc(14);
}
