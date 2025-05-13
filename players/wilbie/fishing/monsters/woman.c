inherit "obj/monster";
#include "/players/wilbie/def.h"
reset(arg) {
::reset(arg);
if (arg) return;

set_name("woman");
set_alias("woman");
set_alt_name("fisher");
set_level(6);
set_gender(1);
set_aggressive(0);
set_short("A woman");
set_long("A woman from the is looking for her children.\n");
set_wc(2);
set_ac(1);
set_hp(60);
set_spell_mess1("The woman lands a nice backhand!");
set_spell_mess2("You get slapped in the face!");
set_chance(10);
set_spell_dam(5);

load_chat(30,({
"The woman says: Have you seen a little boy and girl?\n",
"The woman looks around.\n",
"The woman looks worried.\n",
}));
load_a_chat(60,({
"The woman screams!\n",
"The woman says: What do you want??\n",
}));
return; }
