inherit "obj/monster";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg){
    ::reset();
    set_name("Old man");
    set_race("human");
    set_gender(1);
    set_alias("man");
    set_alt_name("man");
    set_short("An Ancient Magician");
            set_long(
"  This retired magician donates his time to the town by acting as\n"+
"  A provider of transportation to Spiral Island.  He is about seven\n"+
"  feet tall and has flowing white hair.  His piercingly blue eyes\n"+
"  follow you around the room.\n"+
"\n")+
    set_level(10);
    set_hp(230);
    set_al(-40);
    set_ac(4);
    set_wc(14);
    load_chat(5, ({
"  Old man says: Can I help you?\n",
"  Old man says: Would you like to go to Spiral Island?\n",
"  Old man says: I hear an evil sorceror lives on Spiral Island.\n",
}));
    }
