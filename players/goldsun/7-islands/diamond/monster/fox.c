inherit "/obj/monster";

#define TH(x) transfer(clone_object(x),this_object())

void add_stuff()
{
TH("players/goldsun/7-islands/diamond/obj/amulet");
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
set_long("A silver fox. She has a very nice silver fur.\n");
set_level(31);
set_wc(32);
set_ac(23);
set_size(3);
set_al(300);
set_spell_mess1("Silver fox paints circle in the air.\n"+
	        "You are smashed by invisible force.\n");
set_spell_mess2("A circle is painted in the air by fox's tail.\n");
set_chance(52);
set_spell_dam(125);
add_stuff();
}

