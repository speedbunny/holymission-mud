

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "office2";
    long_desc = 
        "This is the RD's office.\n"
+ "He is not in right now.\n"
+ "But he did leave some things lying around.\n";
    dest_dir = 
        ({
        });
}

