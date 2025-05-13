inherit "obj/treasure";
string weapon, room;
string item_name, room_name;

void init(){
    add_action("search","search");
}

string query_weapon() { return weapon; }
string query_room() { return room; }

drop() { return 1; }
get(){ return 1; }

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_name("invis_search");
    set_weight(0);
    set_value(0);
}

void set_item_name(string str) {
    if (!str) return;
    if (str != "dagger" && str != "axe" && str != "hammer" &&                     
      str != "rope" && str != "sword") return;
    item_name = str;
    weapon = "/players/colossus/mearth/shire/quest/"+str;
    return;
}

void set_room_name(string str) {
    if (!str) return;
    if (str == "forest")
	room = "players/colossus/mearth/shire/forest4";
    if (str == "harbor")
	room = "players/colossus/mearth/shire/pier2";
    if (str == "gate")
	room = "players/colossus/mearth/shire/road1";
    if (str == "island")
	room = "players/colossus/mearth/shire/island1";
    if (str == "tree")
	room = "players/colossus/mearth/shire/partytree";
    room_name = str;
    return;
}

int search() {         
    object weap;

    if (room && (string)file_name(environment(this_player())) != room) {
	write("You are searching at the wrong place!\n");
	write("Your assumption for murder location was at " + room_name + ".\n");
	say(this_player()->query_name() + " searches the room.\n");
	return 1;
    }
    if (room && !weapon) {
	write("You seach around but cannot find the murder weapon.\n");
	destruct(this_object());
	return 1;
    }
    if (room && weapon) {
	weap = clone_object(weapon);
	write("You find a " + weap->query_name() + "!\n");
	this_player()->message(this_player()->query_name() +
	  " searches the room and finds " + weap->query_name());
	move_object(weap, this_player());
	destruct(this_object());
	return 1;
    }
    write("You find nothing of interest.\n");                                     
    say(this_player()->query_name() + " searches the room.\n");
    destruct(this_object());
    return 1;                                                                     
}
