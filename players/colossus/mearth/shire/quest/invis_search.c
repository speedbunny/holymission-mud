#define TP 	this_player()

inherit "obj/treasure";
string weapon, room;

void init(){
    add_action("solution", "think");
}

query_weapon(){ return weapon; }
query_room(){ return room; }
drop(){ return 1; }

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_name("invis_search");
    set_weight(0);
    set_value(0);
}

void set_item_name(string str){
    if(!str) return;
    if(str!="dagger" && str!="axe" && str!="hammer" &&
      str!="rope" && str!="sword") return;
    weapon="/players/colossus/mearth/shire/quest/"+str;
    return;
}

void set_room_name(string str){
    if(!str) return;
    if(str=="forest")
	room = "players/colossus/mearth/shire/forest4";
    if(str=="harbor")
	room = "players/colossus/mearth/shire/pier2";
    if(str=="gate")
	room = "players/colossus/mearth/shire/road1";
    if(str=="island")
	room = "players/colossus/mearth/shire/island1";
    if(str=="tree")
	room = "players/colossus/mearth/shire/partytree";
    return;
}

int search(){
    object weap;
    if(!room){
	write("No room.\n");
	return 1;
    }
    if((string)file_name(environment(TP))!=room){
	write("You're not searching in the room you have picked.\n");
	return 1;
    }
    write((string)file_name(environment(TP)));
    write(room);
    if((string)file_name(environment(TP))==room){
	weap=clone_object(weapon);
	write("You find a "+weap->query_name()+"!\n");
	say(this_player()->query_name()+" searches the room and finds "+
	  weap->query_name()+".\n");
	transfer(weap, this_player());
	destruct(this_object());
	return 1;
    }
}

int solution(){
    write(room+weapon);
    return 1;
}
