
inherit "obj/monster";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg){
    ::reset();
    set_name("Old man");
    set_race("human");
    set_gender(1);
    set_alias("man");
    set_alt_name("man");
    set_short("The Librarian");
            set_long(
"The librarian's long white hair and bear almost reach the ground.  His "+
"round spectacles are hanging from the tip of his nose.  He is wearing "+
"little more than a bag.  He is intently reading a scroll.\n");
    set_level(10);
    set_hp(230);
    set_al(-40);
    set_ac(3);
    set_wc(12);
    load_chat(5, ({
"  Old man says: Can I help you?\n",
"  Old man says: Are you here on a 'quest' for knowledge?\n",
}));
enable_commands();
    }
