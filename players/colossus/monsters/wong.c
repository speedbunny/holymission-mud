inherit"obj/monster";

reset (arg) {
    ::reset(arg);
    if (!arg) {
	set_name("wong");
	set_level(40);
	set_gender(1);
	set_race("immortal");
	set_alias("artist");
	set_al(0);
	set_short("Wong Fei Hung, the Reknowned Martial Artist of the East");
	set_long("An immortal stands before you, his name is Wong Fei Hung.\n" +
	  "He looks at you with mixture of disdain and hope.\n");
	set_wc(20);
	set_aggressive(1);
	load_chat(10, ({
	  "Wong Fei Hung says: You barbarian, how dare you challenge me?\n",
	  "You see in his eyes the weariness of living.\n"}));
	set_dead_ob(this_object());
	set_spell_mess2("Wong hits you in the chest with his palm and breaks several ribs!\n");
	set_spell_mess1(capitalize(previous_object()->query_name())+" is struck in the chest by Wong's palm and you hear the sound of breaking bones!\n");
	set_chance(99);
	set_spell_dam(25);
	set_ac(18);
    }
}
monster_died(ob) {
    write("You have killed an immortal!\n" +
      "Electricity and lightning crackles around you and through you as power courses\n" +
      "through your being!\n");
    return 0;
}
