inherit "obj/monster";
void reset(int arg) {
    ::reset(arg);
    if(!arg){
	set_name("evil cleric");
	set_race("gnome");
	set_short("Evil cleric");
	set_long("This evil cleric seems to have black gems for eyes. A glowing red gem\n"+
	  "has been placed on his neck, you wonder why.\n");
	set_alias("cleric");
	set_level(20);
	set_al(-300);
	set_ac(9);
	set_wc(25);
	set_spell_mess1("A ray of red light comes out of the evil clerics neck.\n");
	set_spell_mess2("The evil cleric hits you with a red light.\n");
	set_chance(40);
	set_spell_dam(15);
    }
}
