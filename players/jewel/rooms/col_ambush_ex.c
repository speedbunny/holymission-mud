inherit "room/room";

int cloned; //Global variable for one monster per reset

void reset(int arg){
    cloned = 0; // Setting it back to 0 every reset
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Monster ambushing room";
    long_desc = "This is an example of a room where a monster can\n\
ambush you.\n";
}

void init(){
    ::init();
    /* If the monster is not cloned yet this reset, then clone it */
    if(!cloned)
	call_out("monster_create", 3); // Making the monster enter
}

void monster_create(){
    object *ob;
    int i,j;
    /* The check for all_inventory is to check the room's inventory */
    /* or in simpler terms, what is present in the room */
    ob = all_inventory(this_object());
    j = sizeof(ob); // This is preevaluating the variable for efficiency
    for(i=0;i<j;i++)
	if(ob[i]->query_player()){ // query if the stuff in room is a player
	    move_object("/players/colossus/mearth/shire/frodo",
	      this_object());
	    tell_room(this_object(),
	      "A hobbit wanders in.\n");
	    cloned = 1; // Setting the variable so that monster has been cloned
	    remove_call_out("monster_create"); // For safety's sake
	}

}
