inherit "obj/treasure";

int at_shire;

status set_at_shire(int arg){ at_shire = arg; }

status at_shire(){ return at_shire; }

status get(){
    write("You must be nuts!\n");
    return 1;
}

void init(){
    add_action("board", "board");
}

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_name("boat");
    set_alias("small boat");
    set_short("A small boat");
    set_long(
      "This is a small wooden boat but it seems sturdy enough for the trips\n"+
      "between the Shire and the island. You can 'board' the boat.\n");

    set_weight(10000);
    set_value(0);
}

status board(string str){
    if(!str){
	notify_fail("Board what?\n");
	return 0;
    }
    else {
	write("You board the boat.\n");
	this_player()->move_player("boat#players/colossus/mearth/shire/boat");
	tell_room(environment(),
	  this_player()->query_name()+" boards the boat.\n");
	tell_room("/players/colossus/mearth/shire/boat",
	  this_player()->query_name()+" boards the boat.\n");
	return 1;
    }
}
