/* Nylakoorub's Room Traveller */
#include "/obj/adjust.h"
#define AREAS "/players/nylakoorub/misc/tools/area_list"



object *areaname, *areapath;
object *areastart;
string cur_areaname,cur_areapath;
string cur_room;

int id(string str) {
    return str=="roomboots" || str=="traveller" ||
    str=="rt";
}

int get() { return 1; }
int drop() {
    destruct(this_object());
    return 1;
}


string short() {
    return "Nylakoorub's Room/Area Traveller";
}

void long() {
    write(
      "Nylakoorub's Room/Area Traveller.\n"+
      "This Magical device, knows its way around this mud.\n"+
      "Type 'traveller' to find out what it knows and have it\n"+
      "help find where you want to go.\n"+
      "\n");
}


void init() {
    restore_object(AREAS);
    if(!areaname) areaname=({ ({}) });
    if(!areapath) areapath=({ ({}) });
    if(!areastart) areastart=({ ({}) });
    if(!cur_areaname || cur_areaname != "General Rooms")
	cur_areaname = "General Rooms";
    if(!cur_areapath || cur_areapath != "/room/")
	cur_areapath = "/room/";
    if(!cur_room || cur_room != "adv_guild.c" )
	cur_room = "adv_guild.c";
    add_action("list_areas", "areas");
    add_action("set_area", "setarea");
    add_action("get_rooms", "rooms");
    add_action("set_room", "setroom");
    add_action("go_to_room", "goroom");
    add_action("help_traveller", "traveller");
    if(environment()->query_archwiz() ||
      environment()->query_real_name() == "nylakoorub") {
	add_action("add_area", "addarea");
	add_action("remove_area", "removearea");
    }

}


help_traveller(arg) {
    if(arg == "admin") {
	write("Traveller Admin Commands Info.\n");
	write(
	  "addarea <name>#<path>@<file>\n"+
	  "<name> = Name of Area, you must capitalize words yourself, code\n"+
	  "         in the traveller will not do it for you.\n"+
	  "<path> = FULL path of area, with a '/' at both ends.\n"+
	  "         wrong = /room, wrong = room/, right = /room/ . \n"+
	  "<file> = full filename of preselected room in area room\n"+
	  "         dir.  Most likly the start room.\n"+
	  "\n"+
	  "removearea <number>    - to an area from Traveller.\n"+
	  "\n");

	return 1;
    }
    if(!arg || arg != "admin") {
	write("Nylakoorub's Area/Room Traveller Commands:\n");
	write("\n");
	write(
	  ladjust("Command:", 20)+
	  ladjust("What it does:", 30)+
	  "\n");
	write(
	  ladjust("areas", 20)+
	  ladjust("To list areas already in Traveller.", 40)+
	  "\n");
	write(
	  ladjust("setarea <number>", 20)+
	  ladjust("To select a area.", 30)+
	  "\n");
	write(
	  ladjust("rooms", 20)+
	  ladjust("To list all rooms in selected area", 30)+
	  "\n");
	write(
	  ladjust("setroom <number>", 20)+
	  ladjust("To select a room", 30)+
	  "\n");
	write(
	  ladjust("goroom", 20)+
	  ladjust("To travel to selected room.", 30)+
	  "\n");

	if(environment()->query_archwiz() ||
	  environment()->query_real_name() == "nylakoorub") {
	    write("\n\n");
	    write("Traveller Admin. Commands:\n");
	    write(
	      ladjust("Command:", 40)+
	      ladjust("What it does:", 30)+
	      "\n");
	    write(
	      ladjust("addarea <name>#<path>@<file>", 40)+
	      ladjust("To add area into Traveller.", 30)+
	      "\n");
	    write(
	      ladjust("removearea <number>", 40)+
	      ladjust("To remove area from Traveller.", 30)+
	      "\n");

	    write("\n");
	    write("Type 'traveller admin' for more help on admin "+
	      "commands of Traveller.\n");
	}
	return 1;
    }
    return 1;
}

set_area(arg) {
    int i,j,number;
    if(!arg) {
	write("Usage: setarea <number>.\n");
	return 1;
    }
    sscanf(arg, "%d", number);
    if(!number || !arg ) {
	write("Usage: setarea <number>.\n");
	return 1;
    }
    j = sizeof(areaname);
    if(number<1 || number>j ) {
	write("Invalid choice!\n");
	return 1;
    }
    for(i=0;i<j;i++) {
	if(i+1 == number ) {
	    cur_areaname = areaname[i];
	    cur_areapath = areapath[i];
	    cur_room = areastart[i];
	}
    }
    write("New Area Selected is: "+cur_areaname+"\n");
    write("New Path Selected is: "+cur_areapath+"\n");
    write("New Selected Room is: "+cur_room+"\n");
    return 1;
}


list_areas() {
    int i;
    write("List of Areas: \n");
    for(i=0;i<sizeof(areaname);i++) {
	write(((i+1) +". ")[0..3]);
	write((areaname[i] + "                  ")[0..25]);
	if(i%3==2)
	    write("\n");
    }
    if(sizeof(areaname)%3)
	write("\n");
    write(
      "Current Area Selected: "+cur_areaname+"\n");
    write(
      "Current Path Selected: "+cur_areapath+"\n");
    write(
      "Current Room Selected: "+cur_room+"\n");
    return 1;
}


add_area(arg) {
    string name,path,filename;
    if(!arg) {
	write(
	  "Usage: addarea <name>#<path>@<file>.\n"+
	  "<name> = name of area, you must capitilize stuff, code will "+
	  "not do it.\n"+
	  "<path> = full path, with '/' at begin and end of path.\n"+
	  "<file> = full file name with '.c', of start room.\n"+
	  "\n");
	return 1;
    }
    sscanf(arg, "%s#%s@%s", name,path,filename);
    if(!name || !path || !filename ) {
	write(
	  "Usage: addarea <name>#<path>@<file>.\n"+
	  "<name> = name of area, you must capitilize stuff, code will "+
	  "not do it.\n"+
	  "<path> = full path, with '/' at begin and end of path.\n"+
	  "<file> = full file name with '.c', of start room.\n"+
	  "\n");
	return 1;
    }
    areaname+=({ name });
    areapath+=({ path });
    areastart += ({ filename });
    save_object(AREAS);
    write(
      "You have added to the Traveller: \n"+
      "Area Name: "+name+"\n"+
      "Area Path: "+path+"\n"+
      "Area Room: "+filename+"\n"+
      "\n");
    return 1;
}


remove_area(arg) {
    int i,j,number;
    if(!arg) {
	write("Usage: removearea <number>.\n");
	return 1;
    }
    sscanf(arg, "%d", number);
    if(!number) {
	write("Usage: removearea <number>.\n");
	return 1;
    }
    j = sizeof(areaname);
    if(number<1 || number>j ) {
	write("Invalid choice!\n");
	return 1;
    }
    for(i=0;i<j;i++) {
	if(i+1 == number ) {
	    if(areaname[i] == cur_areaname &&
	      areastart[i] == cur_room &&
	      areapath[i] == cur_areapath ) {
		write("You can't delete the current selection.\n");
	    } else {
		write(
		  "You have remove from the Traveller: \n"+
		  "Selection: "+number+"\n"+
		  "Area Name: "+ areaname[i] +"\n"+
		  "Area Path: "+ areapath[i] +"\n"+
		  "Area Room: "+ areastart[i] +"\n"+
		  "\n");
		areaname -= ({ areaname[i] });
		areapath -= ({ areapath[i] });
		areastart -= ({ areastart[i] });
		save_object(AREAS);
	    }
	}
    }
    return 1;
}


get_rooms() {
    int i,j;
    string *room_dir;
    room_dir = get_dir(cur_areapath + ".");
    j = sizeof(room_dir);
    write("Area: "+cur_areaname+"\n");
    write("\n");
    write(
      "Current Room Selected: "+cur_room+"\n");
    write("\n");
    for(i=0;i<j;i++) {
	write(((i+1) + ".  ")[0..3]);
	write(" ");
	write((room_dir[i] +
	    "     ")[0..8]);
	write(" ");
	if(find_object(cur_areapath+room_dir[i])) {
	    write((
		find_object(cur_areapath+room_dir[i])->short() +
		"              ")[0..10]);
	} else {
	    write((
		"Not loaded  ")[0..10]);
	}
	write(" ");
	if(i%3==2)
	    write("\n");
    }
    if(j%3)
	write("\n");
    return 1;
}


set_room(arg) {
    string *room_dir;
    int number;
    int i,j;
    if(!arg) {
	write("Usage: setroom <number>.\n");
	return 1;
    }
    sscanf(arg, "%d", number);
    room_dir = get_dir(cur_areapath + ".");
    j = sizeof(room_dir);
    if(!number) {
	write("Usage: setroom <number>.\n");
	return 1;
    }
    if(number<1 || number>j ) {
	write("Invalid choice!\n");
	return 1;
    }
    for(i=0;i<j;i++) {
	if(i+1 == number ) {
	    if(room_dir[i] == cur_room ) {
		write("That room is already selected.\n");
	    } else {
		cur_room = room_dir[i];
		write("New Selected Room: "+
		  room_dir[i] +
		  "\n");
	    }
	}
    }
    return 1;
}


go_to_room() {
    write(
      "The Traveller activites itself and pulls you off to "+
      "\n"+
      cur_areapath+cur_room+" "+
      "in "+cur_areaname+"\n");
    say(
      capitalize(environment()->query_real_name())+
      "'s Traveller activites itself and pulls "+
      capitalize(environment()->query_real_name())+
      " off to\n"+
      cur_areapath+cur_room+" "+
      "in "+cur_areaname+"\n", environment());
    move_object(environment(), cur_areapath+cur_room);
    command("look", environment());
    return 1;
}


