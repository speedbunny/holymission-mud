#include "/players/gareth/define.h"

short() {
    return "A slender wand made of glass";
}

long() {
    write("This wand is made of glass and rather beautiful.\n" +
	  "Who knows, it might even be magic!\n" +
	  "Maybe you should try to point it at something, or wave it?\n");
}

reset(arg) { }

init() {
    add_action("point", "point");
    add_action("point", "wave");
}

id(str) {
    return    str == "wand" || str == "glass wand"
	   || str == "slender wand" || str == "id wand" || str == "idwand";
}

point(str) {
    string what, the_creator;
    object the_thing;

    if (environment(TO) != TP)
	return 0;
    if (!str)
	return 0;

    if (id(str)) {
	write("You wave the wand in the air, pointing at nothing special.\n");
	say(TPN + " waves the glass wand in the air.\n");
	the_creator = creator(environment(TP));
	if (the_creator)
	    write("In your mind you see an image of " + capitalize(the_creator) + ".\n" +
		  "Maybe " + capitalize(the_creator) + " built this place?\n");
	else
	    write("You get the impression that this place is very old.\n");
	return 1;
    }

    if (   !sscanf(str, "wand at %s", what)
	&& !sscanf(str, "glass wand at %s", what)
	&& !sscanf(str, "slender wand at %s", what)
	&& !sscanf(str, "id wand at %s", what)
	&& !sscanf(str, "idwand at %s", what)) {
	return 0;
    }

    the_thing = present(what, TP);
    if (!the_thing)
	the_thing = present(what, environment(TP));
    if (!the_thing) {
	write("There is no " + what + " here.\n");
	return 1;
    }

    say(TPN + " points at the " + what +
	" with the glass wand.\n");
    write("You point at the " + what + " with the glass wand.\n");
    the_creator=the_thing->query_creator();
    if(!the_creator) the_creator=creator(the_thing);
    if (the_creator)
	write("In your mind you see an image of " + capitalize(the_creator) + ".\n" +
	      "Maybe " + capitalize(the_creator) + " made the " + what + "?\n");
    else
	write("You see nothing.\n");
    return 1;
} 

get() { return 1; }
query_name() { return "id wand"; }
query_weight() { return 1; }
query_value() { return 200; }
