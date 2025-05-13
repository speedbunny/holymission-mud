inherit "/obj/npc";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"
#define TH(x) transfer(clone_object(x),this_object())

void add_stuff()
{
TH(ii+"/icicle");
TH(ii+"/money_holder");
}

void reset(int arg)
 {
 ::reset(arg);
if (arg) return;
set_name("sighart");
set_living_name("sighart");
set_race("human");
set_short("Snow wizard Sighart");
set_gender(1);
set_long(
"The Snow wizard Sighart, who is the friend of Merlin and Hern stands before "+
"you .  He has black long hair and wears a cosmic blue robe.  In addition to his "+
"formidable magic skills, his muscles add to his appearance of strength.\n");
set_level(60);
set_wc(56);
set_ac(24);
set_size(3);
set_hp(query_hp()+1000);
set_al(30);
set_spell_mess1("Sighart casts ice storm.\n");
set_spell_mess2("Sighart casts ice storm.\n");
set_chance(32);
set_spell_dam(190);
set_attacks(5);
set_attacks_change(80);
set_no_steal();
add_money(255);
add_stuff();
}


int query_property(string str){ return str=="no_steal"; }
