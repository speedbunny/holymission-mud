inherit "room/room";

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="Sun alley";
        long_desc="Sun alley runs east-west.\n";
        dest_dir=({
            "room/sunalley2","west",
            "room/eastroad3","east",
                 });

/* Airborne - 05/12/93 */
replace_program("room/room");

    }
}
