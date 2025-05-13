/*Room description corrected by Silas*/
inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Jug's shopping center";
    no_castle_flag = 0;
    long_desc = 
        "You enter a well equipped shopping center. To the left is the counter\n"
        + "where a clerk tries to serve all the clients. At the moment it seems that the\n"
        + "shop has problems to get new stuff so the only thing you can buy is a\n"
        + "`typing speeder`.\n"
        + "Type 'buy speeder' if you want one of them.\n"
        + "\nSORRY SORRY SORRY the shop is closed now for restoration.\n"
        + "Go and search for your luck elsewhere!\n";
    dest_dir = 
        ({
        "/players/jug/castle", "north",
        });
    items = ({
        "clerk", "He seems busy",
        });
}

init() {
    ::init();
    add_action("buy", "buy");
}
 
query_light() {
    return 1;
}

buy(str) {
	object iob;
	
    if (str != "speeder") return 0;

    write("SORRY SORRY SORRY sold out, return next year.\n");
    write("The shopkeeper is low on money the japanese are cheaper.\n");
    return 1;

	if (present("speeder", this_player())) {
		write("You have already a Typing Speeder, you cannot get two of them !!!\n");
		return 1;
		}
    if (this_player()->query_money() < 500) {
        write("Not enough cash, come another time\n");
        return 1;
        }
    iob = clone_object("/players/jug/obj/speeder");
    move_object(iob, this_player());
    this_player()->add_money(-500);
    write("You bought a typing speeder.\n");
    return 1;
}
