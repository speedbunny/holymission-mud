inherit "room/room";
string chest_desc;
int has_done;
object dinges;
status open_chest;
reset(arg) {
    if (arg) return;
    open_chest = 0;
    has_done = 0;
    chest_desc = "A large chest (closed)";
    set_light(1);
    short_desc = "Cellar";
    no_castle_flag = 1;
    long_desc =

    "You are in the cellar of the tower.\n"+
    "It's very cold and dark in here.\n"+
    "A large chest is standing here in the middle of the room.\n"+
    "There must not have been a living soul here for ages.\n";
    dest_dir = ({ "players/dice/quest/tower/to0","up",
    });


    items = ({
      "tower","A dark but not big tower",
      "chest","@@query_chest_desc@@",
      "large chest","@@query_chest_desc@@",
      "cellar","The cellar of the tower",
      "soul","That's not here",

    });

    smell = "The air is fresh.";
}
init(){
    ::init();
    add_action("_open","open");add_action("_close","close");
}
_open(str){
    if(!str||!str=="chest"||!str=="large chest"){
	return 0;
    }
    if(str=="chest"||str=="large chest"){
	if(open_chest == 1 ){
	    write("It's already open.\n");
	    return 1;
	}
    }
    if(!present("dinges",this_player())){
	write("You are mentally not strong enough to open the chest.\n");
	say(this_player()->query_name()+" failed to open the chest.\n");
	return 1;
    }
    if(has_done == 1){
	write("You open the chest\n");
	open_chest = 1;
	return 1;
    }
    write("You open the chest and you hear a voice soflty say :\n"+
      "\n\n\n THANK YOU\n"+
      "You have relieved me from the earthly prison.\n"+
      "You can have all my money that is left as a reward\n");
    open_chest = 1;
    has_done = 1;
     this_player()->add_money(2000);
   this_player()->set_quest("tower_quest");
    return 1;
}
_close(str){
    if(!str||!str=="chest"||!str=="large chest"){
	notify_fail("Close what ?\n");
	return 0;
    }
    if(str=="chest"||str=="large chest"){
	if(open_chest == 0 ){
	    notify_fail("It's not open\n");
	    return 0;
	}
	write("You close the chest.\n");
	say(this_player()->query_name()+" closes a chest.\n");
	open_chest = 0;
	return 1;
    }
}
query_chest_desc(){
    if(open_chest){
	return "A large chest (open)";
    }
    else return chest_desc;
}
