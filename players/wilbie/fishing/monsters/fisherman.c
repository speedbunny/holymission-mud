inherit "obj/monster";
#include "/players/wilbie/def.h"
reset(arg) {
::reset(arg);
if (arg) return;

set_name("fisherman");
set_alias("man");
set_al(400);
add_money(500);
set_alt_name("fisher");
set_level(6);
set_gender(1);
set_aggressive(0);
set_short("A fisherman");
set_long("A fisherman from the village.\n");
set_wc(2);
set_ac(1);

load_chat(30,({
"The fisherman sighs wearily.\n",
"The fisherman yawns.",
}));
load_a_chat(40,({
"The fisherman growls in anger.\n",
"The fisherman mumbles to himself.\n",
}));
return; }
