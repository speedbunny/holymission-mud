inherit "obj/monster";

object pick;

reset(arg){
::reset(arg);
 if(arg) return;

	set_name("duegar");
	set_alt_name("dwarf");
	set_alias("duegar dwarf");
	set_race("duegar");
	set_level(7+random(4));
	set_gender(1+random(1));
	set_aggressive(1);
 	set_wc(15);
	set_size(3);
	set_short("Duegar dwarf");
	set_long("A fierce dugar dwarf. He looks angry and mean.\n");
	set_dex(20);
	set_chance(1);
	set_spell_dam(30);
	set_spell_mess1("The duegar slams his pick into your back!\n");

pick = clone_object("obj/weapon");
pick-> set_name("pick");
pick-> set_class(7+random(9));
pick-> set_value(20);
pick-> set_short("A pick");
pick-> set_long("A duegar pick.\n");
pick-> set_weight(2);

   transfer(pick, this_object());

	init_command("wield pick");

  return 1;

}

