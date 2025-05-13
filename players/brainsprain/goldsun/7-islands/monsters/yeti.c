inherit "/obj/monster";

#define TH(x) transfer(clone_object(x),this_object())

void reset(int arg)
 {
 ::reset(arg);
if (arg) return;
set_name("yeti");
set_race("yeti");
set_short("Yeti");
set_gender(1);
set_long(
"Before you stands the legendary Yeti, an oriental version of bigfoot.  "+
"He stands upright like humanoid but his entire body is covered in hair and "+
"he has massive hands and feet.  He opens his mouth to show all his teeth in what "+
"you hope is a smile.\n");
set_level(57);
set_wc(39);
set_hp(query_hp()+400);
set_ac(8);
set_spell_mess1("Yeti smashes you with his right hand.\n");
set_spell_mess2("");
set_chance(30);
set_spell_dam(100);
set_size(3);
set_al(40);
add_money(250+random(120));
}

