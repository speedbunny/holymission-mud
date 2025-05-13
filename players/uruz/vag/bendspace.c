#include "/players/nylakoorub/guild/defines.h"

int level,cost;
string roomname, filepath;

get_gender_possessive(ob) {
    string sex;
    sex = ob->query_gender();
    switch(sex) {
    case 0 : 
	return "itself";
	break;
    case 1:
	return "him";
	break;
    case 2:
	return "her";
	break;
    default:
	return "ERROR";
	break;
    }
}





do_bendspace(arg) {
    string type, dest;
    object who, where;


    if(environment(this_player())->query_property("no_teleport") &&
      !this_player()->query_immortal() ) {
	write("This room can not be bend with your destination.\n");
	return 1;
    }

    sscanf(arg, "to %s %s", type, dest);
    if(!type && !dest) {
	write("Usage: bendspace to <type> <destination>\n");
	return 1;
    }
    if(!dest) {
	write("Bendspace to where?\n");
	return 1;
    }
    if(type=="room"){
	switch(dest){
	case "guild" :
	    level= BEND_GUILD_LEVEL;
	    cost= BEND_GUILD_COST;
	    if(check_cost(cost, level)){ return 1; }
	    filepath= "/players/nylakoorub/guild/room";
	    roomname= "The Vagabond Guild";
	    break;
	case "church" :
	    cost= BEND_CHURCH_COST;
	    level= BEND_CHURCH_LEVEL;
	    if(check_cost(cost, level)){ return 1; }
	    filepath= "room/church";
	    roomname= "Village Church";
	    break;
	case "lounge" :
	    cost= 0;
	    if(file_size(STATUS+this_player()->query_real_name()+".tl") > 0 ||
	      file_size(STATUS+this_player()->query_real_name()+".agm") > 0 ||
	      file_size(STATUS+this_player()->query_real_name()+".agm") > 0 ||
	      this_player()->query_real_name() == "nylakoorub") 
	    { filepath= "/players/nylakoorub/guild/rooms/timelords/lounge";
		roomname= filepath->short();
	    }
	    else{ write("You can't travel there!\n"); 
		return 1; }
	    break;
	default: write("You can't bend there!\n");
	    return 1;
	}
    }
    if(type=="player"){
	who= find_living(dest);
	if(this_player()->query_level() < 10 ) {
	    write("You are not high enough yet.\n");
	    return 1;
	}
	/* Nylakoorub : Need a min. level for bendspace to player, I like it
   to be at least level 10, could be higher, can be discussed
   later... */
	if(!dest){
	    write("Who are you trying to find?\n");
	    return 1;
	}
	if(!who){
	    write("You can't seem to find "+capitalize(dest)+"!\n");
	    return 1;
	}
	if(who->query_immortal()){
	    write("You can't bendspace to an immortal!\n");
	    return 1;
	}
	/* Nylakoorub - To prevent vags to bendspace to a testchar, in a
	   workroom or unopen area, etc. */
	if(who->query_testchar()) {
	    write("You can't bendspace to an Immortal's Testcharacter!\n");
	    return 1;
	}
	else{
	    where= environment(who);
	    filepath= where;
	    roomname= filepath->short();
	}
    }
    write("You begin to bend space around you!\n");
    say(capitalize(this_player()->query_real_name())+" begins to "+
      "bend space around "+get_gender_possessive(TP)+"\n");
    tell_room(filepath, "The room around you begins to become "+
      "distorted!\n");
    write("\n");
    call_out("_move", 4, filepath);
    call_out("_say1", 3, roomname);
    call_out("_say2", 3, filepath);

    return 1;
}
int _move(string arg){
    move_object(this_player(), arg);
    write("\n");
    command("look", this_player());
    write("\n");
    return 1;
}
int _say1(string arg){
    write("You finish bending space, and travel to "+roomname+
      " without moving!\n");
    say(capitalize(this_player()->query_real_name())+" finishes "+
      "bending space and travels to "+roomname+" without moving!\n");
    return 1;
}
int _say2(string arg){
    tell_room(filepath, "The rooms returns to normal "+
      "as "+capitalize(this_player()->query_real_name())+" arrives "+
      " without moving!\n");
    return 1;
}


