/* Edited by Colossus 022494 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if(!present("priest")) {
	move_object(clone_object("players/sherman/priest"),this_object());
    }

    if (arg) return;

    set_light(1);
    short_desc="The dark vally";
    long_desc=
    "The small shed is old but well kept and there is an altar in the\n"+
    "north end of the room that emits an aura of goodness and power.\n"+
    "The inscriptions above the altar read: 'Dedicated to Felnor the\n"+
    "God of Wisdom'.\n";
    items=({
      "altar", "A pure white altar that is erected for the Felnor the\n"+
      "God of Wisdom",
    });
    dest_dir=({ "/players/sherman/darkl2","south" });
}

void init(){
    ::init();
    add_action("sacr","sacrifice");
}

status sacr(int arg){
    int cn,cost;
    object o;

    notify_fail("How much coins ?\n");
    if(!arg) return 0;
    if(!intp(arg)) {
	if(sscanf(arg,"%d coins",cn)!=1) return 0;
    } else cn=arg;
    if(this_player()->query_money()<cn) {
	write("You have not that much money.\n");
	return 1;
    }

    cost = -((int)this_player()->query_alignment()-1000) * 10;
    if(cost<1) cost=1;
    this_player()->add_money(-cn);
    if(cn<cost) {
	write("The good gods are not satisfied.\n");
    } else {
	write("As you sacrifice the money, an item appears on the altar.\n");
	say("As "+this_player()->query_name()+" sacrifice some money,\n"+
	  " an item appears.\n");
	move_object(o=clone_object("obj/thing"),this_object());
	o->set_name("holy water");
	o->set_alias("bottle");
	o->set_alt_name("water");
	o->set_short("a bottle of holy water");
	o->set_long("A little bottle of holy water that is blessed by Felnor the\n"+
	  "God of Wisdom. The liquid within shimmers with a pure white light.\n");
	o->set_weight(1);
	o->set_value(500);
    }
    return 1;
}
