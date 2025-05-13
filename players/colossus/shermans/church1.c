/* Edited by Colossus 022294 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;

    set_light(1);
    short_desc = "A dimly lit chapel";
    long_desc= 
    "This place is all that remains of a once beautiful chape.\n"+
    "There appears to be evidence of looting and vandalizing\n"+
    "as there is only a pile of wood, a staircase leading down\n"+
    "and an old crumbling altar at the corner of the room.\n";
    items=({
      "stairs","Some stairs made of stone with lots of dust on them",
      "pile", "The pile of wood must be all that remains of the chapel's cross",
      "wood", "The wooden poles must be all that remains of the chapel's cross",
      "pile of wood", "The pile of wood must be all that remains of the\n"+
      "chapel's cross. They are now merely short poles",
      "altar","On a closer look there is only a pile of stones left",
      "stone","The stone is old, crumbling and covered with moss",
      "stones","The stones are the remains of the old altar of this church",
    });
    dest_dir=({ 
      "/players/sherman/church2","down",
      "/players/sherman/bell","up",
      "/players/sherman/grave11","south" 
    });
}

void init(){
    ::init();
    add_action("search","search");
}

status search(string arg){
    object wood;

    if(!arg) {
	notify_fail("Search what?\n");
	return 0;
    }
    if(arg=="pile" || arg=="wood" || arg=="pile of wood") {
	write("You found a sharpened wooden pole.\n");
	say(this_player()->query_name()+" searches the pile of wood.\n");
	move_object(wood=clone_object("obj/weapon"), this_object());
	wood->set_name("wooden pole");
	wood->set_short("Wooden pole");
	wood->set_long("A short oak pole that was formerly part of a cross.\n"+
	  "The tip of the pole is sharp and jagged.\n");
	wood->set_weight(2);
	wood->set_value(10);
	wood->set_class(3);
	wood->set_type(2);
	wood->set_alias("pole");
	return 1;
    }
}
