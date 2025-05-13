
inherit "/obj/monster";

  reset(arg) {
    ::reset(arg);
    if (!arg) {
 
   	set_name("Singing nun");
   	set_level(15);
   	set_size(4);
   	set_alias("nun");
   	set_long("A beautiful singing nun.\n");
   	set_chance(20);
   	set_spell_dam(10);
   
   move_object(clone_object("players/misticalla/guild/obj/mace"),
	this_object());

   init_command("wield mace");
  }

}
