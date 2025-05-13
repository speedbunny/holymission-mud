inherit "room/room";
object ob;

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Forest Path";
    long_desc = 
        "This is the entrance to Ragbutho Forest. The occasional hoot of an owl can be\n"
        + "heard over the rustling of the leaves and the creaking of the ancient trees\n"
        + "which make up this forest. Judging from the size of the path you're on not\n"
        + "many people come by this way, and the fact that most of the footprints on the\n"
        + "path are not human makes you even more curious.\n";
    dest_dir = 
        ({
        "/players/silas/ragbutho/rf2", "east",
        "/players/silas/fghant/keidall1", "west",
        });
    smell = "A brisk forest breeze blows the odor of moldy leaves and wildflowers in your face.\n";
}

query_light() {
    return 1;
}
