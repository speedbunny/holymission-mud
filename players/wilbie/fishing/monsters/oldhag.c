inherit "obj/monster";
#include "/players/wilbie/def.h"
reset(arg) {
::reset(arg);
if (arg) return;

set_name("old hag");
set_alias("hag");
set_al(400);
add_money(300+random(45));
set_alt_name("old");
set_level(4);
set_gender(1);
set_aggressive(0);
set_short("An old hag");
set_long("An old hag from the village looks at you and cackles.\n");
set_wc(2);
set_ac(1);
load_chat(30,({
"The old woman shivers a bit.\n",
"The old hag shows you a toothless grin.\n",
}));
load_a_chat(50,({
"The old hag cries for help!\n",
"The old hag says: Leave me alone!\n",
}));
return; }
