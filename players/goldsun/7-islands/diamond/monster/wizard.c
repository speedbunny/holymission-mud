inherit "/obj/npc";

#define TH(x) transfer(clone_object(x),this_object())

void add_stuff()
{
TH("players/goldsun/7-islands/diamond/obj/icicle");
TH("players/goldsun/7-islands/diamond/obj/money_holder");
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
set_long("Snow wizard Sighart the human friend of Merlin and Hern.\n"+
	 "He has black long hair. He can turn you\n"+
	 "into statue of ice with his blue eyes.\n"+
	 "Massive muscles hidden under white cloak\n"+
         "doesn't look weakly.\n");
set_level(70);
set_wc(66);
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
add_money(25500);
add_stuff();
}


int query_property(string str){ return str=="no_steal"; }
