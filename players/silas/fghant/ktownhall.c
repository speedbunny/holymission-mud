inherit "room/room";
object board;

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Town Hall";
    no_castle_flag = 0;
    long_desc = 
        "You have entered the town hall of the city of Keidall where people can voice\n"
        + "their opinions about the city or the land of F'ghant. A bulletin board stands\n"
        + "in the back of the room; please use it if you have any questions, remarks or\n"
        + "concerns regarding this area.\n";
    dest_dir = 
        ({
        "/players/silas/fghant/keidall5", "south",
        });
    smell = "Smells damp and musty here.\n";
transfer(clone_object("/boards/private_boards/silas_keidall"),this_object());
}

query_light() {
    return 1;
}
