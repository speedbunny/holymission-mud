
inherit "obj/monster";
 
reset(arg) {

  ::reset(arg);
  if (!arg) {

    set_name("bunny");
    set_alias("baby bunny");
    set_short("A cute little baby bunny");
    set_long("It looks at you with it's big brown eyes.\n");
    set_level(1);
    set_size(2);
    set_al(100);
    set_aggressive(0);
    set_whimpy();
    set_dead_ob(this_object());

    move_object(clone_object("players/apollo/area2/obj/claws2"),
	this_object());

  }
}

