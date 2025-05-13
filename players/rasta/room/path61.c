#include "std.h"

object rasta, client;

/* For the NEW, IMPROVED monster class: */
string chat_str, a_chat_str, function, type, match, function2, type2, match2;

#undef EXTRA_RESET
#define EXTRA_RESET  extra_reset(arg);

extra_reset(arg) {
    object note,m,b;
    m=clone_object("players/rasta/obj/mosquito");
    b=clone_object("players/rasta/obj/buzzard");
    move_object(m,this_object());
    move_object(b,this_object());
    if (!rasta || !living(rasta)) {
	rasta = clone_object("obj/monster");    /* NEW, IMPROVED monster class! */
	rasta->set_name("guard");
	rasta->set_alias("valley guard");
	rasta->set_level(6);
	rasta->set_ac(16);
	rasta->set_al(1020);
	rasta->set_short("valley guard");
	rasta->set_long("A vigilant young Rastafarian.\n");
	rasta->set_aggressive(0);
	rasta->set_spell_mess1("The guard chants down Babylon.\n");
	rasta->set_spell_mess2("The guard says: killing is not my thing.\n");
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

TWO_EXIT("players/rasta/room/path51", "south",
	 "players/rasta/room/entranc1", "north",
	 "Entrance of the Valley of Decision",
	 "Welcome to the Valley of Decision.\n", 1)


/* For the NEW, IMPROVED monster class: */
setup_arrays() {

    /* Peaceful chatting: */
    chat_str = ({
"The guard says: Jah got dem in the region, in the Valley of Decision.\n",
"The guard says: Running to the rocks for a hiding place ?\n" +
"                The rocks will be melting!\n",
"The guard says: Natty dub it inna de Valley of Decision.\n",
"The guard says: Hypocrites and parasites, there will be no hiding places.\n"+
"The guard says: Your days are numbered.\n"
    });

    /* Combat chatting: */
    a_chat_str = ({
"The guard shouts: You are a wanmted man in Jah Jah sights.\n",
"The guard shouts: There will be no hidding place for you.\n",
"The guard says: Slave driver! Catch a fire!\n",
"The guard says: Where will you run when Jah come ? And Jah come for sure!\n"
    });

} /* setup_arrays */
