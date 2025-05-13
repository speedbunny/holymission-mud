

inherit "room/room";
object rex;

reset(arg) {
    if (!rex) {
	rex=clone_object("/obj/monster");
	rex->set_name("rex");
	rex->set_alias("rex");
	rex->set_short("Tyrannosaurus Rex");
	rex->set_long("This beast is the most carnivorous dinosour.\n");
	rex->set_level(40);
	rex->set_wc(40);
	rex->set_ac(20);
	rex->set_hp(6000);
	rex->set_chance(2);
	rex->set_spell_dam(random(200));
	rex->add_money(5000);
	rex->set_aggressive(1);
	move_object(rex,this_object());
    }
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    long_desc = 
    "You have come to the edge of the stone age. Before you are very \n\
large footprints. They look to be a Rex's. If he's still around you'd \n\
better be prepared to die.\n\n";
    dest_dir = 
    ({
      "players/warlord/stone/stone18", "southeast",
      "players/warlord/stone/stone17", "southwest",
    });
}

