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
	rasta->set_name("Jinx");
	rasta->set_alias("jinx");
	rasta->set_level(19);
	rasta->set_ac(16);
	rasta->set_al(1020);
 rasta->set_short("hoosier girl");
	rasta->set_long(
     "Jinx, the pothead from Ohio. He once dared to kill Lee, the Ganja\n"
     "Cultivator and now he is doomed to hang out in Rasta's area\n"
     "for the rest of his mud life.\n" );
	rasta->set_aggressive(0);
	rasta->set_spell_mess1("Jinx casts Montezumas Revenge on you.\n");
	rasta->set_spell_mess2("Jinx makes you feel the effects of a"
           "major hangover.\n");
	rasta->set_chance(10);
	rasta->set_spell_dam(50);

	move_object(rasta, this_object());

	if (!chat_str)
	    setup_arrays();
	rasta->load_chat(10, chat_str);
	rasta->load_a_chat(40, a_chat_str);
    }
}

ONE_EXIT("players/rasta/room/entrance","east","Jinx's Place",
"This dark place festers with the fume of blood and the stench of\n"
"decay.\n",1)


/* For the NEW, IMPROVED monster class: */
setup_arrays() {

    /* Peaceful chatting: */
    chat_str = ({
"Jinx says: I am here to protect Holy Mission from Carta!\n",
"Jinx says: Hey weakling, can I bumm your corpse?\n", 
"Jinx says: Carta, lemme rip out your guts!\n"
    });

    /* Combat chatting: */
    a_chat_str = ({
	"Jinx says: I am the almighty Carta Slayer! \n",
	"Jinx says: You have disturbed my sleep!The hoosier kicks you.\n",
	"Jinx says: I am now going to seal your fate!\n"
    });

} /* setup_arrays */
