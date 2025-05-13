#include "std.h"

object rasta, client;

/* For the NEW, IMPROVED monster class: */
string chat_str, a_chat_str, function, type, match, function2, type2, match2;

#undef EXTRA_RESET
#define EXTRA_RESET  extra_reset(arg);

extra_reset(arg) {
    object note;

    if (!rasta || !living(rasta)) {
	rasta = clone_object("obj/monster");    /* NEW, IMPROVED monster class! */
	rasta->set_name("prophet");
	rasta->set_alias("rasta prophet");
	rasta->set_level(6);
	rasta->set_ac(16);
	rasta->set_al(1020);
	rasta->set_short("rasta prophet");
	rasta->set_long("A vigilant young Rastafarian.\n");
	rasta->set_aggressive(0);
	rasta->set_spell_mess1("The prophet shouts: lick dem Jah.\n");
	rasta->set_spell_mess2("The prophet shouts: blow over dem top with storm and\n" +
			       "The prophet shouts: thunder!\n");
	rasta->set_chance(10);
	rasta->set_spell_dam(30);
	rasta->set_value(347);

	move_object(rasta, this_object());
      
	if (!chat_str)
	    setup_arrays();
	rasta->load_chat(10, chat_str);
	rasta->load_a_chat(40, a_chat_str);
    }
}

TWO_EXIT("players/rasta/room/path5", "south",
	 "players/rasta/room/top", "north",
	 "A narrow mountain path",
	 "To the south you see the green valleys of Rasta City, the path\n"+
	 "to the ice caves continues to the north.\n", 1)


/* For the NEW, IMPROVED monster class: */
setup_arrays() {

    /* Peaceful chatting: */
    chat_str = ({
"The prophet says: I and I are trodding thru creation in an irie meditation.\n" +
"The prophet says: Grow your dreadlocks! Don't be afraid of the wolf pack.\n",
"The prophet says: Ain't it good to know that Jah will be waiting there?\n",
"The prophet says: The righteous wealth is in His Holy Place.\n",
"The prophet says: Bring the voice of the Rastaman communicating to \n"+
"The prophet says: everyone.\n"
    });

    /* Combat chatting: */
    a_chat_str = ({
"The prophet shouts: You have got the wrong interpretation, mixed up with\n",
"The prophet shouts: vain imagination.\n",
"The prophet says: Destruction of the poor is in their poverty.\n",
"The prophet says: They feel so strong to say we're weak!\n"
    });

} /* setup_arrays */
