inherit "room/room";
 
reset(arg) {
    if (arg) return;
#if 0
    ::reset(arg);
    set_outdoors(4);
#endif
    set_light(1);
    short_desc = "Village street";
    no_castle_flag = 0;
    long_desc =
        "Village\n"
        + "\n"
        + "     This is a intersection where two shops once competed\n"
        + "     for business with each other. To the north lies the\n"
        + "     shop that sells everday items, and to the east is\n"
        + "     the magic shop that sells magic items. But the magic\n"
	+ "     shop is no more, now. To the west lie more shops!\n\n";
        items = ({
        "shop","This is the little shop of Animal's horrors",
        "magic shop", "This place used to sell magic items",
          });
    dest_dir =
        ({
	"players/animal/shops/shop_street4","west",
        "players/animal/shops/shop_street2", "south",
        "players/animal/shops/shop","north",
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
