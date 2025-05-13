inherit "obj/monster";
#include "/players/wilbie/def.h"
reset(arg) {
::reset(arg);
if (arg) return;

set_name("Daimyo");
set_alias("man");
set_al(600);
add_money(1000+random(222));
set_alt_name("fisher");
set_level(12);
set_gender(1);
set_aggressive(0);
set_short("The Daimyo");
set_long("The Daimyo is the ruler of the village of Fuzhao.  He looks very "+
"worried about something...\n");
set_wc(4);
set_ac(1);

set_spell_mess1("The Daimyo connects with a nice punch!");
set_spell_mess2("The Daimyos fist meets your jaw!");
set_chance(30);
set_spell_dam(9);

load_chat(30,({
"The Daimyo welcomes you.\n",
"The Daimyo smiles brightly.",
}));
load_a_chat(50,({
"The Daimyo glares at you.\n",
"The Daimyo says: You DARE attack me???\n",
}));
return; }
