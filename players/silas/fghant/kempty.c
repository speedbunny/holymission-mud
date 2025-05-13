inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Burned Shack";
    no_castle_flag = 0;
    long_desc = 
        "At one time this was the office of Keidall Securities where you could keep\n"
        + "items safely. However, a fire ravaged the office and left nothing but a few\n"
        + "charred blocks of wood in its wake. Maybe a new business will open here\n"
        + "someday, but for now there is nothing of interest here.\n";
    items = ({
         "wood","It has almost been burned to ashes",
            });
    dest_dir = 
        ({
        "/players/silas/fghant/keidall4", "north",
        });
    smell = "The smell of burnt wood and paper wafts around your nose.\n";
}

query_light() {
    return 1;
}
