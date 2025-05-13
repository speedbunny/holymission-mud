inherit "/obj/monster";

#define TH(x) transfer(clone_object(x),this_object())

void reset(int arg)
 {
 ::reset(arg);
if (arg) return;
set_name("yetty");
set_race("yetty");
set_short("A yetty");
set_gender(1);
set_long("A yetty. He has two hands and two legs.\n"+
	 "Whole body is covered by long white hair.\n"+
         "He is 12 feet high.\n");
set_level(57);
set_wc(39);
set_hp(query_hp()+400);
set_ac(8);
set_spell_mess1("Yetty smashes you with his right hand.\n");
set_spell_mess2("");
set_chance(30);
set_spell_dam(100);
set_size(3);
set_al(40);
add_money(2500+random(1200));
}

