inherit "room/room";

reset(arg) {
    if(!arg) {
        set_light(1);
	short_desc="Central point";
        long_desc=
"This is the central point. A lot of traffic seems to have passed through\n"+
"here. If you just wait long enough, some transport might pick you up.\n";
        dest_dir=({
            "room/vill_road2", "up",
                 });

replace_program("room/room");
    }
}
