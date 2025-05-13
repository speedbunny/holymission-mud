

inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Valley Road";
    no_castle_flag = 0;
    long_desc = 
        "The road which you are traveling on is surrounded by towering mountains. You\n"
        + "are surprised that any light manages to reach the valley floor at all, but the\n"
        + "sun shines just as brightly here as anywhere else. You can enter the outskirts\n"
        + "of a village to the east or head further into the valley by walking in a\n"
        + "westerly direction.\n";
    dest_dir = 
        ({
        "/players/silas/fghant/keidall6", "east",
        "/players/silas/fghant/valley2", "west",
        });
}

query_light() {
    return 1;
}
