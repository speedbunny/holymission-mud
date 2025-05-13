inherit "obj/monster";
#include "/players/wilbie/def.h"
reset(arg) {
::reset(arg);
if (arg) return;

set_name("girl");
set_alias("girl");
set_al(400);
add_money(100);
set_alt_name("fisher");
set_level(3);
set_gender(1);
set_aggressive(0);
set_short("A girl");
set_long("A girl is just wandering around.\n");
set_wc(2);
set_ac(1);
set_spell_mess1("The girl kicks out wildly!");
set_spell_mess2("You get kicked in the shin!!");
set_chance(30);
set_spell_dam(6);

load_chat(40,({
"The young girl yawns.\n",
"The young girl stares at the sky.\n",
"The young girl looks at the sea.\n",
"The young girl glances at you.\n",
}));
load_a_chat(50,({
"The young girl says: You jerk!!\n",
"The young girl says: Who are you?!?\n",
}));
return; }
