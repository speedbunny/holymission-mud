inherit "room/room";

object board;


void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Crossroads of the 4th";
    long_desc =
    "This is the crossroads of the 4th or the center of the 4th.\n"+
    "All around the 4th are portals, leading to different times,\n"+
    "parallel dimensions and alternate realities.\n"+
    "\n"+
    "To the east, you hear music and some socialing going on.\n"+
    "\n"+
    "Here is a portal lying in the center of the room.  This portal\n"+
    "is not like the other portals here in the '4th'.\n"+
    "\n";

    dest_dir = ({
      "/players/nylakoorub/4th/4th_vag",
      "north",
      "/players/nylakoorub/4th/timeclub/lobby",
      "east",
    });

    if(!present("portal")) {
	move_object(clone_object("/players/nylakoorub/4th/portalob"),
	  this_object());
    }

    if(!present("board")) {
	board = clone_object("/obj/board");
	board->set_name("The '4th'");
	board->set_file("/players/nylakoorub/4th/boards/4th_main");
	move_object(board,this_object());
    }


    items = ({
      "portal", "You glance into the portal and see a shady vision\n"+
      "of a tree top, as you look, you hear a deep god\n"+
      "like voice which says 'Lurk within to enter back\n"+
      "to were time and realities exist normally",
    });

}

void init() {
    ::init();
    add_action("enter", "enter");
}


int enter(string arg) {
    string destroom;
    destroom = "/players/nylakoorub/4th/portal";
    if(arg=="portal") {
	tell_room(destroom,
	  capitalize(this_player()->query_real_name())+
	  " emerges from the portal.\n");
	move_object(this_player(), destroom);
	tell_room(this_object(),
	  capitalize(this_player()->query_real_name())+
	  " enters the portal.\n");
	command("look", this_player());
    } else {
	write("Enter what?\n");
    }
    return 1;
}


