inherit "obj/monster";
#include "/players/wilbie/def.h"
reset(arg) {
::reset(arg);
if (arg) return;

set_name("boy");
set_alias("man");
set_al(300);
add_money(400);
set_alt_name("fisher");
set_level(5);
set_gender(1);
set_aggressive(0);
set_short("A boy");
set_long("A boy tries to look tough.\n");
set_wc(2);
set_ac(1);
load_chat(50,({
"The young boy flexes his puny arms.\n",
"The young boy does a handstand.\n",
"The young boy throws some sand into the sea.\n",
}));
load_a_chat(60,({
"The young boy grins at you.\n",
"The young boy tries to look tough.\n",
}));
return; }
