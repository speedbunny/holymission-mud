/* Axlrose - Room Creator (coded by Sauron) */
inherit "/room/room";

void init() {
    ::init();
    "/players/axlrose/castle"->load_general("/"+file_name(this_object()));
}

