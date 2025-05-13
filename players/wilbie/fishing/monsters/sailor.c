inherit "obj/monster";
#include "/players/wilbie/def.h"
reset(arg) {
::reset(arg);
if (arg) return;

set_name("sailor");
set_alias("man");
set_al(300);
add_money(700+random(76));
set_alt_name("sailor");
set_level(6);
set_gender(1);
set_aggressive(0);
set_short("A sailor");
set_long("A sailor from the ship.\n");
set_wc(4);
set_ac(1);
load_chat(30,({
"The sailor looks around.\n",
"The sailor smiles at you.\n",
}));
load_a_chat(50,({
"The sailor swears loudly!\n",
}));
return; }
