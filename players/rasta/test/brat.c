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
	rasta->set_name("hoosier");
	rasta->set_alias("girl");
	rasta->set_level(16);
	rasta->set_ac(16);
	rasta->set_al(1020);
 rasta->set_short("hoosier girl");
	rasta->set_long(
	 "Obviously a brat American girl from Indiana. She is not really\n"
       + "a ditsy blonde as she got some redish strands.\n"  );
	rasta->set_aggressive(0);
	rasta->set_spell_mess1("The hoosier girl pouts.\n");
	rasta->set_spell_mess2("The hoosier girl frowns down on you.\n");
	rasta->set_chance(10);
	rasta->set_spell_dam(30);

	move_object(rasta, this_object());

	if (!chat_str)
	    setup_arrays();
	rasta->load_chat(10, chat_str);
	rasta->load_a_chat(40, a_chat_str);
    }
}

ONE_EXIT("players/rasta/room/bulletin","south","Bratty room",
"A store room.\n",1)


/* For the NEW, IMPROVED monster class: */
setup_arrays() {

    /* Peaceful chatting: */
    chat_str = ({
"The hoosier girl says: fluffy Austrians are the best\n",
"The hoosier girl says: Indiana - love it or leave it.\n" +
"The hoosier girl says: I only sort of love it ...\n"+
"The hoosier girl says: Can I live near Chicago ?\n",
"The hoosier girl says: have you seen the football team ?\n",
"The hoosier girl says: I am not really a brat.\n"
    });

    /* Combat chatting: */
    a_chat_str = ({
	"The hoosier girl bobs up like a cork.\n",
	"The hoosier kicks you.\n",
	"The hoosier girl says: don't you hurt me!\n"
    });

} /* setup_arrays */
