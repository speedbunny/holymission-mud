
inherit "room/room";

#include "/players/apollo/guild/barb.h"

void reset(int arg) {
    set_light(1);

    short_desc = "The Shrine of Crom";

    long_desc =
	"A large rocky crag stands like a sentinel over the barren plain. At "+
	"the base of the crag is a stone shrine to the god Crom. This place "+
	"looks like the Barbarians place of sacred or church. The plain "+
	"extends to the north, east, and west. It is impassible to the south "+
	"becoming even more rocky and crevassed.\n";

    dest_dir = ({
	GROOMS+"open14","north",
	GROOMS+"open12","east",
      	GROOMS+"open18","west",
       });

    items = ({
	"crag", "A pillar of rock jetting out of the plain",
      	"shrine", "The wild peoples of this land built this as a\n"+
      		  "worship place to their god, Crom",
      	"plain", "It extends in all directions (except south)",
       });

}

init() {
    ::init();
    AA("_pray","pray");
    AA("_pray","worship");
    AA("_sacrifice","sacrifice");
}

smile() {
    write("You feel the mighty Crom smiling down at you.\n");
    say(TPN+" glows for a moment.\n");
    return 1;
}

_pray() { 
    if((TP->query_ghost())){
	write("Crom breathes life back into you!\n");
	say("Crom returns "+TPN+" from the place of the dead.\n");
	TP->remove_ghost();
	TP->heal(1040);
	return 1;
    }
    if(TP->query_religion()=="Crom"){
	write("You kneel down in worship to the mighty Crom.\n");
	say(TPN+" kneels down in prayer to "+TPPOS+" god.\n");
	call_out("smile", 5+random(5));
	return 1;
    }
    if((TP->query_ghost()) && (TP->query_religion()=="Crom")){
	write("Crom breathes life into you once again.\n");
	say("Crom returns "+TPN+" from the place of the dead.\n");
	TP->set_ghost(0);
	TP->heal(1000);
	return 1;
    }
    if(present("sac_ok",TP)){
	write("You are overwhelmed by a feeling of freedom as\n");
	TP->set_religion("Crom");
	write("you turn your allegence toward Crom.\n");
	destruct(present("sac_ok",TP));
	return 1;
    }
    else {
	write("You must first seek out a place of solitude and return with\n");
	write("a sacrifice pleasing to Crom.\n");
	return 1;
    }
}

int leave_religion() {
    write("Crom's Fury burst forth from the sky and strikes you down.\n");
    tell_room(environment(TP), "A flash of lightning strikes "+TPN+"!\n");
    TP->hit_player(TP->query_hp()-1);
    TP->set_con((TP->query_con()-TP->query_level())*2);
    return 1;
}

_sacrifice(arg) {
    if(!arg) return "Sacrifice what?";
    if(arg=="piece" || arg=="piece of iron" || arg=="iron"){
	if(present("a piece of pure iron",TP)){
	    write("You sense Crom is pleased.  Perhaps you should pray.\n");
	    MO(CO(GOBJS+"sac_ok"),TP);
	    destruct (present("a piece of pure iron",TP));
	    return 1;
	}
	else {
	    write("Crom is not sastisfied with this iron.\n");
	    write("A voice thunders: You do not have the Iron!\n");
	    write("Your body writhes in pain.\n");
	    TP->hit_player(20+random(10));
	    return 1;
	}
    }
    write("You try to sacrifice "+arg+", but Crom does not take it.\n");
    return 1;
}
