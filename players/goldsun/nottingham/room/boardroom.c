inherit "room/room";

object board;

reset(arg) {

    if(!board) {
       board = clone_object("/obj/board");
       board->set_file("players/goldsun/nottingham/ideaboard");
       board->set_name("board");
       board->set_short("Nottingham board");
       transfer(board,this_object());
    }

    if (!arg){
    set_light(1);
    short_desc = "Nottingham Board Room"; 
    long_desc = "You are in the Nottingham Board Room. Here you can write\n"+
               "your ideas, bugs, typos (about my areas) or ALL YOU WANT.\n";

    items = ({ 
	    "staircase","It leads down"
             });
    property=({"no_fight"});
    dest_dir = 
        ({
        "players/goldsun/nottingham/room/bank","down"
        });
 }
replace_program("room/room");
}
