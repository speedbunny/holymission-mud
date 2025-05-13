#include "std.h"

object rasta, client;

string chat_str, a_chat_str, function, type, match, function2, type2, match2;

#undef EXTRA_RESET
#define EXTRA_RESET  extra_reset(arg);

extra_reset(arg) {
    object note;

    if (!rasta || !living(rasta)) {
	rasta = clone_object("obj/monster");
	rasta->set_name("ambassador");
	rasta->set_alias("mister");
	rasta->set_level(6);
	rasta->set_ac(16);
	rasta->set_al(1020);
 rasta->set_short("mister reggae ambassador");
rasta->set_long("You are surprised by his sense of humor, his tolerance,\n"
             +  "even of his temper and uncomperable calmness.\n");
	rasta->set_aggressive(0);
	rasta->set_spell_mess1("Mr. Reggae Ambassador: lick dem Jah.\n");
	rasta->set_spell_mess2("Mr. Reggae Ambassador: blow over dem top with storm and\n" +
			       "Mr. Reggae Ambassador: thunder!\n");
	rasta->set_chance(10);
	rasta->set_spell_dam(30);

	move_object(rasta, this_object());

	if (!chat_str)
	    setup_arrays();
	rasta->load_chat(10, chat_str);
	rasta->load_a_chat(40, a_chat_str);
    }
}

TWO_EXIT("players/rasta/room/path21", "south",
	 "players/rasta/room/path41", "north",
	 "A narrow mountain path",
	 "You have a wonderful view at a mixture of fantastic landscapes, white\n"+
	 "sand beaches, hidden bays, and cliffs dropping into turbulent seas.\n", 1)


/* For the NEW, IMPROVED monster class: */
setup_arrays() {

    /* Peaceful chatting: */
    chat_str = ({
"Mr. Reggae Ambassador says: I ain't gonna stop from loving Jah\n" +
"Mr. Reggae Ambassador says: Jah Jah lovin' is all I-mon is asking for.\n",
"Mr. Reggae Ambassador says: Want I fe play you some dread natty reggae ?\n",
"Mr. Reggae Ambassador says: Back weh with ya wicked plans!\n",
"Mr. Reggae Ambassador says: Come mak' we chant down Babylon!\n"
    });

    /* Combat chatting: */
    a_chat_str = ({
	"Mr. Reggae Ambassador says: pass the spliff pon the right aside.\n",
"Mr. Reggae Ambassador says: emancipate yourselves from mental slavery!\n",
"Mr. Reggae Ambassador says: none but ourselves can free our minds!\n"
    });

} /* setup_arrays */
