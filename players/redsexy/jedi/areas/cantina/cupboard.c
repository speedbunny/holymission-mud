inherit "/obj/container";

reset(arg) {
    if (!arg) {
	set_alias("cupboard");
	set_max_weight(12);
	set_long("A large clothes cupboard in the dressing room.\n");
	set_value(0);
	set_weight(1);
	set_can_get(0);
	::reset(arg);
    }
    move_object(clone_object("/players/redsexy/jedi/objects/hat.c"),this_object());
    move_object(clone_object("/players/redsexy/jedi/objects/cloak.c"),this_object());
    move_object(clone_object("/players/redsexy/jedi/objects/beaker.c"),this_object());

}
