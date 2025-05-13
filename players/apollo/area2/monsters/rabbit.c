
inherit "/obj/monster";

  reset(arg) {
    ::reset(arg);
    if (arg) return;
 
   	set_name("rabbit");
   	set_level(2);
   	set_alias("field rabbit");
   	set_short("A cute field rabbit");
   	set_long("A cute rabbit with big brown eyes.\n");
   	set_whimpy();
   	
	set_spell_mess1("The cute rabbit hits you with it's claw");
   	set_spell_mess2("The rabbit slaps you");
   	set_chance(2);
   	set_spell_dam(2);

   move_object(clone_object("players/apollo/area2/obj/rabbit_claw"),
	this_object());

   init_command("wield claw");

}
