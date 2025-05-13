
inherit "/obj/monster";

  reset(arg) {
    ::reset(arg);
    if (!arg) {
 
   	set_name("bear");
   	set_level(15);
   	set_size(4);
   	set_alias("brown bear");
   	load_chat(8,({"Bear searches the water for trout and pounces.\n"}));
   	set_short("A dangerous brown bear");
   	set_long("It is huge and brown, and very strong.\n");
   	set_spell_mess1("The bear stands on his hind legs and growls.");
   	set_spell_mess2("The bear bites and claws at the air.");
   	set_chance(20);
   	set_spell_dam(8);
   
   move_object(clone_object("players/apollo/area2/obj/bear_claw"),
	this_object());
   move_object(clone_object("players/apollo/area2/obj/bear_fur"),
	this_object());

   init_command("wield claw");
  }

}
