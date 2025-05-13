/* Edited by Colossus: 070994 */

#pragma strict_types

inherit "room/room";

status query_teeth(object pl);
void kill_vamp(object pl);

void reset(int arg){
    int i;
    if (!present("ghost")) {
	for (i=0;i<5;i++)
	    move_object(clone_object("/players/sherman/ghost2"),this_object());
    }
    if (arg) return;
    set_light(0);
    short_desc="The second level of the vampire tower";
    long_desc=
    "On the second level of the tower is a sight you were not prepared\n\
for. The room looks normal enough except for the pit built into the\n\
corner of the room and in that pit lies heaps upon heaps of dead and\n\
rotting corpses all drained of blood. The atmosphere in the room is\n\
one of dread and a curious feeling of vengenace.\n";
    items=({
      "room", "The room is a normal enough room except for the pit",
      "pit", "The pit is a crudely dug hole in the corner of the room "+
      "containing heaps of corpses",
      "corpses", "The corpses all bear one resemblance, the lack of blood",
    });
    dest_dir=({
      "/players/sherman/vtower4","up",
      "/players/sherman/vtower2","down"
    });
    ::reset(arg);
}

void init(){
    ::init();
    if(present("ghost")) {
	if(query_teeth(this_player())) {
	    call_out("kill_vamp",2,this_player());
	    add_action("up","up",1);
	}
    }
}

status up(){
    if(!present("ghost")) {
	this_player()->move_player("up#players/sherman/vtower4");
    } else { 
	write("The ghosts block your way.\n");
	kill_vamp(this_player());  
    }
    return 1;
}

void kill_vamp(object pl){
    object *gh;
    int i;

    gh=all_inventory(environment(pl));
    for(i=0; i<sizeof(gh); i++) {
	if(lower_case((string)gh[i]->query_name())=="ghost"){
	    gh[i]->attack_object(pl);
	}
    }
}

status query_teeth(object pl){
    object *th;
    int i;

    th=all_inventory(pl);
    for(i=0;i<sizeof(th);i++) {
	if(th[i]->query_wielded())
	    return (int)th[i]->query_teeth();
    }
} 

