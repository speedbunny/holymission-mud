/*Room description corrected by Silas*/
inherit "room/room";

reset(arg) {
    if (arg) {
	extra_reset();
	return;
    }

    set_light(1);
    short_desc = "On the garden path";
    no_castle_flag = 0;
    long_desc = 
    "You are at the end of the path. To the north is a hedge and to the\n"
    + "south lies a beehouse. There are bees all around this apiary. It seems that\n"
    + "the gardener is also a beekeeper, maybe he gets the honey for his master.\n";
      items = ({
      "beehouse", "A big wooden beehouse with honey dripping out of the top",
      });
    dest_dir = 
    ({
      "/players/jug/room/garden/garden4", "west",
    });
    extra_reset();
}

extra_reset() {
    object ob, room;
    int i;

    room = this_object();
    ob = first_inventory(room);
    while(ob && !ob->id("bee"))
	ob = next_inventory(ob);
    if (ob) return;

    i = 3;
    while (i > 0) {
	ob = clone_object("players/jug/monster/bee");
	transfer(ob, room);
	i--;
    }
}
