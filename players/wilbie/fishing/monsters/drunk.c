inherit "obj/monster";
#include "/players/wilbie/def.h"
reset(arg) {
::reset(arg);
if (arg) return;

set_name("drunk");
set_alias("man");
set_al(400);
add_money(100+random(300));
set_alt_name("fisher");
set_level(6);
set_gender(1);
set_aggressive(0);
set_short("A drunk");
set_long("A drunk stumbles towards you.\n");
set_wc(2);
set_ac(1);
load_chat(40,({
"The drunk hiccups!\n",
"The drunk burps.\n",
"The drunk pukes on your leg.\n",
"The drunk says: Give me a few gold, small fry!\n",
}));
"The drunk swings wildly.\n",
"The drunk says: I'll kill you!\n",
"The drunk falls all over himself.\n",
}));
return; }
