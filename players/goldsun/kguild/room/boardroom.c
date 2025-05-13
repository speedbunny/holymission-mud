
inherit "room/room";
#include "../guild.h"

object board;
string extra;
int i;

reset(arg) {

    if(!board) {
       board = clone_object("/obj/board");
       board->set_file("players/goldsun/guild/confer/guildboard");
       board->set_name("board");
       board->set_short("The Knights board");
       transfer(board,this_object());
    }

    if (arg) return;
    set_light(1);
    short_desc = "Knight Board Room"; 
    long_desc =  BS(
          "This is a boardroom of the Knights. There is a board "
        + "hanging on the wall where the Knights can state their desires. " 
        + "A little corridor leads further to the south.");
    items = ({ 
            "walls","White stone walls",
            "bottom","A brown wooden bottom",
	    "wall","A large board is hanging on this wall",
	    "corridor","The corridor leads further to the south"
             });
    dest_dir = 
        ({
        "players/goldsun/guild/room","south",
        });
replace_program("room/room");
}
