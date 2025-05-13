
#define PATH "/players/blade/"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Laboratory";
    long_desc =
    "Bottles and beakers, chemicals still dripping from them, create an almost\n"
    +"unimaginable clutter.  A nearly imperceptible path through the mess leads\n"
    +"to the center of the room, where someone has been experimenting recently.\n";
    items = ({
      "bottles","Foul-smelling liquids of blue, green, and amber drip to the floor",
      "beakers","Disgusting yellow chemicals molder inside"
    });
    dest_dir=({
      "/players/blade/guild/poison/alch_shop","down"
    });
    clone_list = ({

      2,1,"pot",PATH + "guild/poison/pot",0,

      3,1,"parchment",PATH + "guild/poison/parchment",0,

      4,1,"vellum",PATH + "guild/poison/vellum",0,
    });
    ::reset();
    replace_program("room/room");
}
