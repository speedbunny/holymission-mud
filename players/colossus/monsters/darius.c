inherit "obj/monster";
object broadsword,leather;

reset(arg) {
::reset(arg);
if (arg) return;
set_name("darius");
set_alt_name("gladiator");
set_race("human");
set_level(16);
set_short("Darius the Gladiator");
set_long("Before you stands Darius the gladiator! A mighty opponent!\n");
set_wc(14);
set_ac(13);
set_spell_mess2("Darius outmanuevers you and hacks at your unprotected flan.\n");
set_chance(25);
set_spell_dam(25);
set_aggressive(1);
broadsword = clone_object("players/colossus/weapons/bsword");
leather = clone_object("players/colossus/armors/leather");
move_object(broadsword, this_object());
move_object(leather, this_object());
init_command("wield broadsword");
command("wear leather");
}
