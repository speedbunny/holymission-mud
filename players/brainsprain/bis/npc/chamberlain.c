inherit "obj/monster";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg){
    ::reset();
    set_name("chamberlain");
    set_race("elf");
    set_gender(1);
    set_alias("kings chamberlain");
    set_alt_name("man");
    set_short("King's Chamberlain");
            set_long(
"A high ranking official at court.  He is wearing purple tights and a "+
"heavy longcoat.  Under his arm is a clipboard detailing the list of "+
"things to be done for the day.  His curly mop of hair is drenched in sweat.\n")+
    set_level(7);
    set_hp(150);
    set_al(-33);
    set_ac(2);
    set_wc(9);
}

