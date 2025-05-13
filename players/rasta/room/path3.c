#include "std.h"

object rasta, client;

string chat_str, a_chat_str, function, type, match, function2, type2, match2;

#undef EXTRA_RESET
#define EXTRA_RESET  extra_reset(arg);

extra_reset(arg) {
    object note;

    if (!rasta || !living(rasta)) {
	rasta = clone_object("obj/monster");
	rasta->set_name("rasta");
	rasta->set_alias("mountain rasta");
	rasta->set_level(6);
	rasta->set_ac(16);
	rasta->set_al(1020);
 rasta->set_short("mountain rasta");
	rasta->set_long("He is smiling at you.\n");
	rasta->set_aggressive(0);
	rasta->set_spell_mess1("The mountain rasta shouts: lick dem Jah.\n");
	rasta->set_spell_mess2("The mountain rasta shouts: blow over dem top with storm and\n" +
			       "The mountain rasta shouts: thunder!\n");
	rasta->set_chance(10);
	rasta->set_spell_dam(30);

	move_object(rasta, this_object());

	if (!chat_str)
	    setup_arrays();
	rasta->load_chat(10, chat_str);
	rasta->load_a_chat(40, a_chat_str);
    }
}

TWO_EXIT("players/rasta/room/path2", "south",
	 "players/rasta/room/path4", "north",
	 "A narrow mountain path",
	 "As you continue walking along the path you feel ital"+
	 "vibrations getting stronger.\n", 1)


/* For the NEW, IMPROVED monster class: */
setup_arrays() {

    /* Peaceful chatting: */
    chat_str = ({
"The mountain rasta says: we gonna break down the wall inna Babylon\n" +
"The mountain rasta says: that seem to devide us.\n",
"The mountain rasta says: You can't destroy the rasta man\n",
"The mountain rasta says: let me tell you about Marcus Garvey\n",
"The mountain rasta says: They are trying hard to destroy I Idren\n"
    });

    /* Combat chatting: */
    a_chat_str = ({
	"The mountain rasta prays for assistance from Jah.\n",
	"The mountain rasta says: watch out I am dangerous.\n",
	"The mountain rasta says: you can kill I-man today but you cyaan stop prophecy!\n"
    });

} /* setup_arrays */
