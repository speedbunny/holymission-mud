inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("vulture");
set_race("bird");
set_short("An evil vulture");
set_long(
"An evil looking vulture.  Its bald head makes you queasy, reminding you of "+
"raw flesh.  Hanging from its beak is a piece of hairy meat, and it stink "+
"of rot.  He ruffles his wings as he alertly looks around for something to eat.\n");
set_level(20);
set_wc(18);
set_ac(3);
set_gender(1);
set_hp(query_hp()+1000);
set_size(3);
set_al(-90);
}

