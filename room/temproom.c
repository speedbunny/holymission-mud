inherit "room/room";

reset(int arg) {
    ::reset(arg);
    if (arg) return;
    short_desc="Temproom";
    long_desc="Exit church to leave.\n";
    set_light(1);
    dest_dir = ({ "room/church","church",
                });
}
