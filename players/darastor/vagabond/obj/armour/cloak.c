#include "/players/nylakoorub/guild/defines.h"
#include "/players/nylakoorub/guild/lib/checks/break_string.h"
#include "/obj/adjust.h"
#include "lw.h"


string color;

get() { return 1; }


int id(string str) {
    return str == "vagcloak"  || str == "cloak";
}


string short() {
    return "Cloak of Time and Space ("+
    "worn)";
}

long() {
    write(
      "This is and Vagabond's 'Cloak of Time and Space'.  Its fibers \n"+
      "were woven by the Ancient Timelords of the 4th dimension.\n"+
      "\n");
    write(break_string("The color and design of this cloak is "+
	color+"\n", 75));

}



init() {
    if(environment()->query_invis() > 1)
	environment()->set_vis();
    if(!color) color = "black";
    add_action("set_cloak_color","cloakcolor");
    add_action("drop", "drop");
    add_action("remove", "remove");
    add_action("set_cloak_invis_level", "cloak");
    add_action("do_uncloak", "uncloak");


}

set_cloak_invis_level(arg) {
    int number;
    if(!arg) {
	write(
	  "Usage: cloak <cloak level>.\n");
	return 1;
    }
    sscanf(arg, "%d", number);
    if(!number) {
	write(
	  "Usage: cloak <cloak level>.\n");
	return 1;
    }
    if(number >= environment()->query_level()) {
	write("You can not cloak yourself that high!\n");
	return 1;
    }
    if(number < 0 ) {
	write("Invaild number!\n");
	return 1;
    }
    if(number == 0 ) {
	write("Type 'uncloak' to "+
	  "uncloak yourself.\n");
	return 1;
    }

    if(number == environment()->query_invis()) {
	write("You already cloaked at the level.\n");
	return 1;
    }
    if(environment()->query_invis() > 1 ) {
	call_out("do_change_invis", 0, number);
    } else {
	call_out("do_invis", 0, number);
    }


    return 1;
}


do_invis(int number) {
    int i,j;
    object *u;
    u = all_inventory(environment(environment()));
    j = sizeof(u);
    for(i=0;i<j;i++) {
	if(living(u[i]) && !u[i]->query_npc() &&
	  u[i] != environment() ) {
	    if(u[i]->query_level() > environment()->query_level() ||
	      u[i]->query_level() < number ) {
		tell_object(u[i],
		  environment()->query_real_name()+
		  " wraps his cloak around "+
		  environment()->query_possessive()+
		  " body and cloaks.\n");
	    } else {
	    }
	}
    }
    write("You wrap your cloak around you and cloak out of sight!\n");
    environment()->set_invis(number);
    set_heart_beat(1);
    return 1;
}

do_change_invis(int number) {
    int i,j;
    object *u;
    u = all_inventory(environment(environment()));
    j = sizeof(u);
    for(i=0;i<j;i++) {
	if(living(u[i]) && !u[i]->query_npc() &&
	  u[i] != environment() ) {
	    if(number < u[i]->query_level()) {
		if(u[i]->level() > environment()->query_invis()) {
		} else {
		    tell_object(u[i],
		      "You see "+
		      capitalize(environment()->query_real_name())+

		      " uncloak before you, but you see, that "+
		      capitalize(environment()->query_real_name())+
		      "'s cloak his still wrap around "+
		      environment()->query_possessive()+
		      " body.\n");
		}
	    }
	    if(number > u[i]->query_level()) {
		if(u[i]->query_level() < environment()->query_invis()) {
		} else {
		    tell_object(u[i],
		      environment()->query_real_name()+
		      " wraps his cloak around "+
		      environment()->query_possessive()+
		      " body and cloaks.\n");
		}
	    }
	}
    }
    write("You change the level of your cloak from "+
      environment()->query_invis()+
      " to "+
      number+".\n");
    environment()->set_invis(number);
    return 1;
}



do_uncloak() {
    environment()->set_vis();
    say(
      capitalize(environment()->query_real_name())+
      " uncloaks before you, as "+
      environment()->query_possessive()+
      " cloak unwraps.\n", environment());
    write(
      "You uncloak, as you unwrap your cloak around yourself.\n");
    set_heart_beat(0);
    return 1;


}




void heart_beat() {
    if(environment()->query_sp() == 0 ) {
	tell_object(environment(),
	  "You ran out of spell points, so.... \n");
	command("uncloak", environment());
    } else {
	environment()->restore_spell_points(-1);
    }
}



int drop(string str) {
    if(str=="cloak") {
	write("You do not want to drop your cloak.\n");
	return 1;
    }
    else {
	return 0;
    }
}


int wear(string str) {
    if(id(str)) {
	write("You are already wearing your cloak.\n");
	return 1;
    }
}

int remove(string str) {
    if(id(str)) {
	write("What!! and disrupted the Space/Time Continium!\n");
	return 1;
    }
    else {
	return 0;
    }
}


set_cloak_color(string arg) {
    if(!arg) {
	write("Usage: cloakcolor <color>\n");
	return 1;
    }
    if(arg == color) {
	write("It is the same color.\n");
	return 1;
    }
    else {
	write("You change your cloak color from "+
	  color+
	  " to "+
	  arg+
	  "\n");
	color = arg;
	return 1;
    }
    return 1;
}



