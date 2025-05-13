inherit "obj/monster";

reset(arg) {
::reset(arg);
if(arg) return;


set_name("fisherman");
set_level(18);
set_short("An Ishikawan fisherman");
set_long("A fisherman offers to ferry you between Ishikawa and Ezo.\n");
set_al(10);
set_hp(1700);
set_wc(18);
set_ac(3);
set_spell_mess2("The fisherman beats you with his oar");
set_spell_mess1("The fisherman beats his opponent with an oar");

set_chance(20);
set_spell_dam(32);

}
