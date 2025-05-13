inherit "obj/monster";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg){
  ::reset(arg);
if(arg) return;
    set_name("protester");
    set_race("subhuman");
    set_gender(1);
    set_alias("monster");
    set_alt_name("man");
    set_short("Angry Protester");
            set_long(
"An absurd little man wearing expensive fineries.  He carries a large "+
"sign.  He is wearing thick rimmed, coke-bottle glasses.  He seems to "+
"shake with frenetic energy and his sandy-blonde hair is perpetually "+
"messy.  Windburn and sunburn have combined to prematurely wrinkle and "+
"age this man.\n");
    set_level(6);
    set_hp(130);
    set_al(-100);
    set_ac(2);
    set_wc(8);
    load_chat(20, ({
"Protester says: Lower taxes!\n",
"Protester says: Hell no, we won't go!\n",
"Protester says: Clothe the hungry!\n",
"Protester says: for only a dime a week we can feed the poor.\n",
"Guard arrives and beats the bejesus out of protester.\n",
"Protester says: Hunting is immoral... animals are humans too.\n",
}));
}
