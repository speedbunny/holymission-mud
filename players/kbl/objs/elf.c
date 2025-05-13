/* Standard random Elf */

inherit "obj/monster"; /* we take the standardobj */
int lvl;


reset(arg) {
    ::reset(arg);
    if (!arg) {

	set_name("elf");
	lvl = random(20)+10;
	set_gender(random(2)+1);
	set_level(lvl);
	set_al(200*(random(3)+1));
	set_alias("elf");
	set_race("elf");
	set_short("Gray Elf");
	set_long("You see a gray elf. Gray elfs hate Drow elfs\n");
	add_money(random(lvl*3)+200);
	set_wc(random(7)+lvl/4);
	set_ac(random(10)+lvl/3);
	set_aggressive(0); /* (1) would be aggressive */
	set_move_at_reset(); /*at every reset it moves one field */
	set_whimpy(); /*it runs away when it is low on hp */
	load_chat(8,({
          "Gray elf says: Demons Of Chaos talk backwards broken phrases.\n",
	  "Gray elf dances around you.\n","Gray elf grins.\n","Gray elf smiles.\n",
	  "Elf sneezes all over you!\n"}));
	set_spell_mess1("Gray elf smacks you hard");
	set_spell_mess2("Gray elf sucker punches you");
	set_chance(10);
	set_spell_dam(20);
    }
}
