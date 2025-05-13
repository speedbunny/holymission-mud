/* Standard random Drow Elf */

inherit "obj/monster"; /* we take the standardobj */
int lvl;


reset(arg) {
    ::reset(arg);
    if (!arg) {

	set_name("drow");
	lvl = random(20)+10;
	set_gender(random(2)+1);
	set_level(lvl);
	set_hp(lvl*30);
	set_sp(lvl*20);
	set_al(-200*(random(3)+1));
	set_alias("dark elf");
	set_race("drow");
	set_short("Dark elf");
	set_long("You see a dark elf. Is looking at you with a evil intent.\n");
	add_money(random(lvl*10)+200);
	set_str(lvl+random(3));
	set_dex(lvl+random(2));
	set_wis(lvl+random(2));
	set_int(lvl+random(3));
	set_con(lvl+random(3));
	set_chr(lvl-random(3));
	set_wc(random(7)+lvl/4);
	set_ac(random(5)+lvl/3);
	set_aggressive(1);
	set_move_at_reset(); /*at every reset it moves one field */
	set_whimpy(); /*it runs away when it is low on hp */
	load_chat(8,({
	  "Drow sneezes.\n","Drow looks around.\n","Drow smirks.\n",
	  "Drow grins evilly.\n"}));
	set_spell_mess1("Drow kicks your teeth in");
	set_spell_mess2("Drow punches your lights out!");
	set_chance(10);
	set_spell_dam(20);
    }
}
