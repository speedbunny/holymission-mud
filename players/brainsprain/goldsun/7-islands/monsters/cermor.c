inherit "/obj/monster";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"
#define SIZE ({"huge","large","medium","small","tiny"})

void reset(int arg)
 {
string stri;
 ::reset(arg);
if (arg) return;
stri=SIZE[random(5)];
set_name(stri+" cermor");
set_alias("cermor");
set_race("demon");
set_short(name);
set_long("Cermor the demon.  He stands twice your height and smoke rolls "+
"from his nostrils as he carefully eyes you.  Muscles ripple under his "+
"skin as he rocks from his left foot to his right foot and back again.\n"+
"He is "+stri+".\n");
set_level(40);
set_wc(35);
set_ac(10);
set_size(3);
set_gender(1);
set_aggressive(1);
set_number_of_arms(2);
set_spell_mess1("Cermor casts blue storm.\n");
set_spell_mess2("Cermor casts blue storm.\n");
set_chance(33);
set_spell_dam(58);
transfer(clone_object(ii+"/hell_ham"),TO);
transfer(clone_object(ii+"/hell_ham"),TO);
command("wield hammer");
command("wield hammer 2");
}

