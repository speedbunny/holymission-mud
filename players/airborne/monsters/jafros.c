inherit "obj/monster";
object robe;

reset(arg){
	::reset(arg);
if(arg) return 1;
	set_name("jafros");
	set_alias("magi");
	set_level(20);
	set_al(-110);
	set_race("human");
	set_gender(1);
	set_short("Jafros the Magi");
	set_long("The power of the man before you is shocking!\n" + "Never before have you seen such magic radiating from another.\n" + "Jafros is not a man to be toyed with.\n");
	set_wc(10);
	set_aggressive(0);
	  load_chat(8, ({
		"Jafros says: Do not meddle in the affairs of the Magi.\n",
		"Jafros says: I have no need of you, leave!\n"}));
	set_spell_mess1("Your body shakes as Jafros unleashes his magic.\n");
	set_spell_mess2("ZZZAAAPPP!!!!   Ouch that hurt!\n");
	set_chance(50);
	set_spell_dam(40);
   robe=clone_object("players/airborne/armours/jafrobe");
   move_object(robe,this_object());
   init_command("wear robe");
	set_ac(10);
	return 1;
}
