

inherit "room/room";

object altar;
object board;

reset(arg) {

    if(!board) {
       board=clone_object("obj/board");
       board->set_file("players/whisky/guild/board");
       board->set_name("board");
       board->set_short("The monks board");
       move_object(board,this_object());
    }
    if (!altar) {
      altar=clone_object("obj/thing");
      altar->set_name("altar");
      altar->set_short("A little black altar");
      altar->set_long("A black altar made of stone.\n");
      altar->set_weight(1000);
      move_object(altar,this_object());
     }
    
    if (arg) return;
    set_light(1);
    short_desc = "In a chapel"; 
    long_desc = 
        "This is the monks meditation-room of the chapel.\n"
        + "There the monks have their peace from the rest\n"
        + "of the world. there is a board hanging on the\n"
        + "wall where the monks can notice their desires\n" 
        + "If you look north you see a little black altar,\n"
        + "where the monks can pray to their gods.\n"
        + "A little corridor leads further to the south\n"
        + "north, east and west.\n";
    items = ({ 
            "walls","White stone walls",
            "bottom","A brown wooden bottom"
             });
    dest_dir = 
        ({
        "players/whisky/guild/room.c", "north",
        "players/whisky/guild/entrance","south",
        "players/whisky/guild/shop","east",
        "players/whisky/guild/bar","west"
        });
}

