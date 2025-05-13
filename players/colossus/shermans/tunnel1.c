/* Edited by Colossus 030494 */

#pragma strict_types

inherit "room/room";

#define hill "players/sherman/entrance"

void reset(int arg){
    if (arg) return;
    set_light(0);
    short_desc = "Tunnel that reeks of foul stench";
    long_desc=
    short_desc = "Tunnel that reeks of foul stench";
    long_desc = 
    "This is the end of the tunnel where the only possible exits\n"+
    "are east and up. This part of the tunnel is reeking of the\n"+
    "stench of some foul beast. Slime covers the walls and more\n"+
    "its touch makes you gag with disgust. The tunnel continues\n"+
    "on to the east and directly above you there is a trapdoor\n"+
    "where a few wispy rays of sunlight stream through.\n";
    items=({
      "tunnel", "The tunnel continues on to the east and it smells of rotting garbage",
      "wall", "The wall is covered with sickly green slime",
      "walls", "The walls are covered with sickly green slime",
      "ceiling", "The ceiling is almost all rock except for a small\n"+
      "trapdoor from which a few rays of sunlight enter",
      "sunlight", "The sunlight brings a bit of life to this otherwise\n"+
      "dank and frightening place",
      "trapdoor", "The trapdoor was the entrance to this dark tunnel\n"+
      "and it leads you back to the world of light and living",
    });
    dest_dir=({
      "/players/sherman/tunnel2","east"
    });
}

void init(){
    ::init();
    add_action("up","up",1);
    add_action("search","search");
    add_action("open","open");
    add_action("close","close");
}

status up(){
    if(hill->query_open()) {
	write("You climb up and leave through the ceiling.\n");
	this_player()->move_player("through the ceiling#"+hill);
	return 1;
    }
}

status search(string arg){
    if(arg=="ceiling") {
	write("You notice a hidden trapdoor at the ceiling.\n");
	if(hill->query_open())
	    write("It is open.\n");
	else
	    write("It is closed.\n");
	return 1;
    }
}

status open(string arg){
    if(arg=="trapdoor") {
	if(hill->query_open()) write("It is already open.\n");
	else {
	    write("You open the trapdoor.\n");
	    say((string)this_player()->query_name()+" moves something at the "+
	      "ceiling.\n");
	    hill->open_door();
	}
	return 1;
    }
}

status close(string arg){
    if(arg=="trapdoor") {
	if(!hill->query_open()) write("It is already closed.\n");
	else {
	    write("You close the trapdoor.\n");
	    say(this_player()->query_name()+" moves something at the "+
	      "ceiling.\n");
	    hill->close_door();
	}
	return 1;
    }
}

void open_door(){
    tell_room(this_object(),"Something moves on the ceiling.\n");
}

void close_door(){
    tell_room(this_object(),"Something moves on the ceiling.\n");
}
