inherit "room/room";

object leather;

reset(arg) {
    if(!arg) {
        short_desc="End of maze";
        long_desc= "The end of the maze.\n";
        dest_dir=({
            "room/maze1/maze4","south",
                 });
    }
    if (!leather || !present(leather)) {
	leather = clone_object("obj/armour");
	leather->set_ac(3);
	leather->set_name("armour");
	leather->set_alias("leather armour");
	leather->set_value(110);
	leather->set_short("A leather armour");
        leather->set_long("A tough leather armour, which will give you a good armour for you body.\n");
	leather->set_weight(3);
        leather->set_size(3);
	leather->set_type("armour");
	move_object(leather, this_object());
    }
}
