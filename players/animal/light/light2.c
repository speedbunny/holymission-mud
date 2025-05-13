inherit "room/room";
 
reset(arg) {
    if (arg) return;
#if 0
    ::reset(arg);
    set_outdoors(4);
#endif
    set_light(1);
    short_desc = "Bright field";
    no_castle_flag = 0;
    long_desc =
        "Bright field.\n"
        + "\n"
        + "     This is a very bright and flowery field. There are flowers\n"
        + "     everywhere. Most are bright red roses.\n"
        + "\n";
	items =   ({
        "roses","The roses are VERY bright and pretty",
        "flowers","The only type of flowers here are roses",
	});
    dest_dir =
        ({
        "players/animal/light/light3", "north",
        "players/animal/light/light1", "south",
        });
}
 
query_long() {
    return long_desc;
}
query_outdoorness() {
    return 4;
}
query_light() {
    return 1;
}
