

/* sislnd18.c */

inherit "/room/south/island";
#include "_defs.h"

string add_long()
{
    return (
    "You are standing among the ruins of the tower of the evil mage,\n" +
	 "Arcanarton. Legend has it that the tower was destroyed in the\n" +
	 "mage wars about five hundred years ago, when all of the mages of\n" +
	 "Lustria combined their forces and attacked Arcanarton. A great \n"+
    "many of them were killed, but they succeeded in destroying the \n" +
	 "mage's tower. His Body was never found, and rumours still abound\n" +
	 "that Arcanarton had become a Lich and has come back to haunt this\n" +
	 "isle. The powerful aura of magical combat still hangs in the air\n" +
	 "here. Lumps of half melted rock lay strewn about, and there is\n" +
    "very little the original structure left standing. To the north of\n" +
	 "the ruins, the hill slopes down to the bridge to the mainland. To the\n" +
	 "east stands a crumbling monument. To the west, an old, disused well.\n" +
	 "To the south of the ruins, the hill slopes away, down to the edge of\n"+
    "Crescent Lake.\n");
}

string *add_items()
{
    return ({ 
    "rock","You see dozens of melted rocks",
    "rocks","You see dozens of melted rocks",
    "ruins","You see the ruins of the tower of Arcanarton",
    "mainland","You see the shore of the Crescent Lake",
    "hill","A small earthy hill",
    "bridge","You see an old ropebridge leading over the lake",
    "well","You see a small well to the east",
    });
}


string *add_dirs()
{
   return ({
   PATH+"sislnd13","north",
   PATH+"sislnd16","south",
   PATH+"sislnd15","east",
   PATH+"sislnd17","west",
   });
}


