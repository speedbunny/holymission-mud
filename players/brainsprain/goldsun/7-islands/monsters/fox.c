inherit "/obj/monster";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"
#define TH(x) transfer(clone_object(x),this_object())

void add_stuff()
{
TH(ii+"/amulet");
command("wear amulet");
}

void reset(int arg)
 {
 ::reset(arg);
if (arg) return;
set_name("silver fox");
set_alias("fox");
set_race("fox");
set_short("A silver fox");
set_gender(2);
set_long(
"A silver fox runs back in forth in this area.  She seems to be searching for "+
"something, perhaps a rabbit is hiding nearby.  A subtle shine surrounds the "+
"fox and you wonder if it might be magical. She has very nice silver fur.\n");
set_level(31);
set_wc(32);
set_ac(23);
set_size(3);
set_al(300);
set_spell_mess1("Silver fox paints a circle in the air.\n"+
	        "You are smashed by invisible force.\n");
set_spell_mess2("A circle is painted in the air by fox's tail.\n");
set_chance(52);
set_spell_dam(125);
add_stuff();
}

