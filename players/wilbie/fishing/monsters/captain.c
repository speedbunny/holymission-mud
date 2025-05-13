inherit "obj/monster";
#include "/players/wilbie/def.h"
reset(arg) {
::reset(arg);
if (arg) return;

set_name("captain");
add_money(1000);
set_al(500);
set_alias("man");
set_alt_name("captain");
set_level(14);
set_gender(1);
set_aggressive(0);
set_short("The captain");
set_long("The captain of the ship.  He looks at you and smirks, "+
         "mumbling something about stow-aways.\n");
set_wc(2);
set_ac(1);
set_spell_mess1("The captain lands a kick to the stomach!");
set_spell_mess2("OOOF!! You are hit hard by a kick!");
set_chance(20);
set_spell_dam(10);

load_chat(30,({
"The captain says: Who are you?\n",
"The captain looks you over.\n",
"The captain says: You wanna join crew??\n",
"The captain frowns at the weather.\n",
}));
load_a_chat(60,({
"The captain says: You DIE no!\n",
"The captain growls.\n",
}));
return; }
