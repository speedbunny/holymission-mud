inherit "/obj/monster";
void reset(int arg)
 {
 ::reset(arg);
 if (arg) return;
set_name("rarah");
set_race("monster");
set_short("An insane Rarah");
set_long("An insane Rarah.\n"
         +"This is mystic monster which scares naughty children.\n");
set_wc(19);
set_ac(3);
set_al(-500);
set_whimpy(4);
set_aggressive(0);
set_level(25);
set_size(3);
set_spell_mess1("\nThe Rarah makes some mysterious gesture.");
set_spell_mess2("\nRarah shows you his magical force."); 
set_chance(19);
set_spell_dam(52);
add_money(2000);
}
