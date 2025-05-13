inherit"room/room";
object cor;
reset (arg) {
    if (!cor) {
	cor=clone_object("obj/monster");
	cor->set_alias("soldier");
cor->set_name("corpse");
	cor->set_short("Half-dead soldier");
	cor->set_long("He looks dead\n");
	cor->set_level(1);
	cor->load_chat(20,({
	    "Corpse whispers: They hit me ....too hard\n",
	    "Corpse whispers: They are tough.......\n",
	    "Corpse whispers: Becareful the lord\n",
	    "Corpse whispers: I barely was able to drag myself in here\n",
	  }));
	cor->set_weight(20);
	transfer(cor,this_object());
    }
    if (arg) return;
    set_light(1);
    short_desc="You see a half dead corpse\n";
    long_desc="The room smells of blood and you see a body on the floor.\n";
    items=({
      "body","Its a half-dead corpse",
    });
    dest_dir=({
      "players/warlord/rooms/skel1","west",
    });
}
query_property(arg) {
    arg=="no_fiht";
    return;
}
