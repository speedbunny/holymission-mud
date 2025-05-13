

inherit "room/room";

reset(arg) {
    if (!present("sign"))
        move_object(clone_object("players/silas/obj/sign"), this_object());
    if (arg) return;

    set_light(1);
    short_desc = "Upper Path";
    long_desc = 
        "This path leads out onto a large ledge which looms over a yawning chasm. The\n"
        + "scenery along the path is fairly dull, with only rocks and dirt lying around\n"
        + "here.\n";
    items = ({
         "chasm","It looks very impressive, even from here",
         "rocks","Ugly rocks from the time of the creation of F'ghant",
         "dirt","Reddish-brown dirt. Some wafts into your nose and you want to inhale more of the filth"
    });
    dest_dir = 
        ({
        "/players/silas/fghant/ledge", "north",
        "/players/silas/caves/caveexit", "south",
        });
    smell = "The air here smells fresh.\n";
}
