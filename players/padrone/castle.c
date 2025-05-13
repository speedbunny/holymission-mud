/*
 *  castle.c
 *	This is the facade to the Castle of Padrone.
 *	Latest change: Feb 4, 1991.
 */

#include "config.h"
#define DEST "/players/padrone/workroom"

/* prototyping */
void make_quest();
void load_mirrormaze();
void load_walker();

object remembered_pad;          /* A pointer to Padrone */

int id(string str) 
{
    return str == "castle";
}

/*  This is the reset function, that is called with arg 0 when the castle is
 *  loaded. Other objects that have to be loaded, like for example the quest
 *  object, should be loaded from this function. BUT, to speed up game restart,
 *  some of the loading is done later from two different call_out calls.
 */
void reset(int flag) 
{
    object sign;
    object dest;

    if (flag) 
    {
	/* This is the periodic reset */
	load_walker();  /* If it has died.  It shouldn't, but... */
	return;
    }

    /* This is the first reset, when the castle is loaded */

    call_out("load_walker", 240);    /* Load the walker 4 minutes from now! */
    call_out("load_mirrormaze", 300);	/* Load the mirrormaze 5 minutes from now! */

    /* Load some facades and other objects that we need */
    call_other("players/padrone/outside/front_yard","??");
    call_other("players/padrone/secret_police/shop_f","??");

    call_other(DEST,"??");	/* Herp: strange ... we get an error now */
    dest=find_object(DEST);	/* when using present ... */

    if(!present("padrone_sign",dest)) {
	sign = clone_object("players/padrone/obj/thing");
	sign->set_name("sign");
	sign->set_alias("padrone_sign");
	sign->set_short("A sign pointing south");
	sign->set_long("This is a small white wooden sign on a pole.\n" +
	  "It is pointing south, and there is something written on it.\n");
	sign->set_read("It says: This way to the Castle of Padrone.\n");
	sign->set_can_get(0);
	move_object(sign, dest);
    }

    /* And finally, put this castle facade where it should be! */
    move_object(this_object(), dest);
} /* reset */

void load_walker() 
{
    /* This call will load the walking castle, if it is not already loaded. */
    "players/padrone/walker/castle"->xxx();
}

void load_mirrormaze() 
{
    object the_room;

    /* Initialize the magic mirrors and the mirrormaze! */
    the_room = "players/padrone/maze/load_mirrors"->return_me();
    /* There is no reason to keep that room loaded. */
    destruct(the_room);
}

void make_quest() 
{
    object qobj,qobj2;

    if (!present("padrone", find_object("room/quest_room"))) {
	qobj = clone_object("obj/quest_obj");
	qobj->set_name("padrone");
	qobj->set_weight(23);
	qobj->set_killing(3);
	qobj->set_short_hint("Find Padrone's walking castle");
	qobj->set_hint("Padrone is sad. He built a beautiful walking castle,\n" +
	  "but a gang of pirates stole it and now he cannot\n" +
	  "find it any more. Help him to get it back!\n" +
	  "You don't have to be big and dangerous to solve this quest,\n" +
	  "but it's always a good idea to bring a weapon and some armour...\n");
	qobj->add_quest();
    }
    /* HERP: Made the Secret Police a quest, too */
    if (!present("secret_police", find_object("room/quest_room"))) {
	qobj2 = clone_object("obj/quest_obj");
	qobj2->set_name("secret_police");
	qobj2->set_weight(40);
	qobj2->set_killing(6);
	qobj2->set_short_hint("Help the Secret Police with the Chaosdemon");
	qobj2->set_hint("Enemies threaten the Realm, both from within and from without!\n"
	  + "The Secret Police is responsible for national security, and\n"
	  + "now they need some help from a mighty hero in connection with\n"
	  + "an investigation concerning a particularly nasty Chaosdemon.\n"
	  + "Find the local headquarters and talk to the captain,\n"
	  + "and he'll give you further instructions.\n"
	  + "And yes, you do have to be big and dangerous to solve this quest.\n");
	qobj2->add_quest();
    }
}
