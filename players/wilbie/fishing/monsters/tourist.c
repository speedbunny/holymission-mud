inherit "obj/monster";
#include "/players/wilbie/def.h"
reset(arg) {
::reset(arg);
if (arg) return;

set_name("tourist");
set_alias("man");
set_al(100);
add_money(500+random(300));
set_alt_name("fisher");
set_level(6);
set_gender(1);
set_aggressive(0);
set_short("A tourist");
set_long("A tourist from the some far off land.\n");
set_wc(2);
set_ac(1);
load_chat(40,({
"The tourist says: Do you know where the church is?\n",
"The tourist says: What village is this?\n",
"The tourist looks puzzled.\n",
}));
load_a_chat(60,({
"The tourist swears at you!\n",
"The tourist says: What have I done to you?",
}));
return; }
