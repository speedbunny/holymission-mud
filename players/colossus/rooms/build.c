inherit "/players/colossus/rooms/save";
#define  WEALTH  this_player()->query_money()
#define  NAME    (string) this_player()->query_name()

string decide_dir(string direction) {
    string new_dir;

    if (direction == "north") new_dir = "south";
    if (direction == "south") new_dir = "north";
    if (direction == "east")  new_dir = "west";
    if (direction == "west")  new_dir = "east";
    if (direction == "northwest") new_dir = "southeast";
    if (direction == "northeast") new_dir = "southwest";
    if (direction == "southwest") new_dir = "northeast";
    if (direction == "southeast") new_dir = "northwest";
    if (direction == "down") new_dir = "up";
    if (direction == "up")   new_dir = "down";
    return new_dir;
}

string decide_file(object TP) {
    string filename;  
    int num_rooms, new_num;
    string temp;

    filename= "/players/colossus/house/room/";
	new_num = num_rooms + 1;
    filename += TP->query_name() + (string) new_num;
    return filename;
}

int build_func(string filename, string direction) {
    string long,short,new_dir,path,*allowed;
    string *exit_dir, *exit_path;
    string *cur_exits, *cur_commands;
    string cur_long, *temp_long, temp, cur_short;
    int i, cur_light;
    object key;
    string old_extra;  

    allowed =
    ({"north","south","east","west","northwest",
      "northeast","southwest","southeast","up","down"});
    if (!direction) {
	write("Usage: build <direction>\n");
	return 1;
    }
    if (WEALTH < 5000) {
	write("You don't have enough money!\n");
	return 1;
    }
    if (NAME != (string) this_object()->query_owner()) {
	write("Leave that to the owner!\n");
	return 1;
    }
    if (member_array(direction, allowed) == -1) {
	write("That is not a valid direction!\n");
	return 1;
    }
    if (member_array(direction, filename->query_exit_dirs()) > -1) {
	write("A room already exists in that direction!\n"); 

	return 1;
    }
    if (!(path = decide_file(this_player()))) {
	write("You cannot build any more rooms!\n");
	return 1;
    }
    exit_dir = 0;
    exit_path = 0;
    key = present("HOUSE_KEYS",this_player());
    if (!key) return 1;
    long = "This is a newly built room awaiting decoration.\\n";
    short = "A new room";
    new_dir = decide_dir(direction);
    if (!exit_dir) exit_dir = ({new_dir});
    else exit_dir += ({new_dir});
    if (!exit_path) exit_path = ({filename});
    else exit_path = ({filename});
    cur_exits = (string *) this_object()->query_dest_dir();
    cur_commands = (string *) this_object()->query_exit_dirs();
    cur_exits += ({path});
    cur_commands += ({direction});
    cur_short = (string) this_object()->short();
    cur_long = (string) this_object()->long();
    cur_long = implode(explode(cur_long, "\n"), "\\n");
    cur_light = (int) this_object()->query_light();
    old_extra = (string) this_object()->query_extra();
    old_extra = implode(explode(old_extra,"\n"), "\\n");
    save_func(long,short,path,exit_path,exit_dir,1,NAME,"\\n");
    save_func(cur_long,cur_short,filename,cur_exits,
      cur_commands, 1, NAME, old_extra);
    tell_room(this_object(),
      "A new room has been added " + direction + " from here.\n");
    this_player()->add_money(-5000);
    key->swapping(this_player());
    return 1;
}                   
