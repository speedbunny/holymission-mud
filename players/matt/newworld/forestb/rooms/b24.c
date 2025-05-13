
/* 031495 Colossus: Fixed bug with speak since language */
/*                  interferes with the action, changed */
/*                  to 'say' instead                    */

inherit "/room/room";

#include "/players/matt/defs.h"

int done;

reset(arg) {
    done = 0;
    if(arg) return;
    set_light(1);
    short_desc = "Sacred Grove";
    long_desc =
    "    You are overcome with a joy and peace you have never known\n" +
    "as you look about yourself in wonder. Plants of all varieties\n" +
    "spring forth from the fruitful earth, splashing the prevalent\n" +
    "green with brilliant color; birds sing happily, and the forest\n" +
    "creatures seem unafraid of you here.\n" +
    "    In the center of this grove stands one of the largest oaks\n" +
    "you have ever seen.\n";

    dest_dir = ({
      NWFORESTB + "rooms/b23", "west",
    });

    items = ({
      "plants", "You have never seen most of these varieties anywhere else",
      "earth", "Healthy soil nourishing a thousand different plants",
      "birds", "Exotic birds flitting from treetop to treetop",
      "creatures", "Small forest animals that accept you as a friend",
      "grove", "This grove radiates a sacred aura",
      "oak", "There is a small inscription in its side",
    });
}

init() {
    ::init();
    add_action("read", "read");
    add_action("do_speak", "say");
    add_action("do_speak");add_xverb("'");
    add_action("do_speak", "utter");
}

read(arg) {
    object spec;
    if(arg == "tree" || arg == "oak" || arg == "inscription") {
	spec = present("spectacles", TP);
	if(spec && spec->query_worn()) {
	    write("You peer closely at the strange writing, and read it.\n");
	    write("It says 'Say her name to call her'.\n");
	    return 1;
	}
	write("The writing is in a language you cannot understand.\n");
	return 1;
    }
}

do_speak(arg) {
    object nature;
    object spec;
    if(arg == "Gaiea" || arg == "gaiea") {
	spec = present("spectacles", TP);
	if(spec && (spec->query_reader() == TP->RNAME)) {
	    write("You softly speak the word \"Gaiea\".\n");
	    say(TP->NAME + " softly speaks a strange word.\n");
	    nature = present("goddess", TO);
	    if(!nature && !done) {
		TELLR(TO, "Slowly, an ethereal spirit congeals from the oak " +
		  "before you.\n");
		nature = clone_object(NWFORESTB + "monsters/gaiea");
		MOVE(nature, ENV(TP));
		call_out("vanish", 60);
		return 1;
	    }
	    write("Nothing happens.\n");
	    return 1;
	}
	write("You cannot say the name correctly; perhaps if you saw it " +
	  "spelled out...?\n");
	return 1;
    }
}

vanish() {
    object nature;
    nature = present("goddess", TO);
    if(nature) {
	TELLR(TO, "Gaiea sighs deeply.\n");
	TELLR(TO, "The beautiful woman turns away, dissolves into a " +
	  "sweet-smelling mist,\n");
	TELLR(TO, "and returns to her oak.\n");
	destruct(nature);
	return 1;
    }
}

set_done() {
    done = 1;
    return 1;
}
