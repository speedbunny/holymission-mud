
inherit "/obj/monster";

  reset(arg) {
    ::reset(arg);
    if (!arg) {
 
   	set_name("mother bear");
   	set_level(15);
   	set_size(4);
   	set_alias("bear");
   	set_short("A dangerous brown mother bear");
   	set_long("It is huge and brown, and very strong.\n");
   	set_spell_mess1("The bear hits you with its claw");
   	set_spell_mess2("The bear bites you hard");
   	set_chance(20);
   	set_spell_dam(8);
	set_aggressive(2);
   
   move_object(clone_object("players/apollo/area2/obj/bear_claw"),
	this_object());
   move_object(clone_object("players/apollo/area2/obj/bear_fur"),
	this_object());

   init_command("wield claw");
  }

}
