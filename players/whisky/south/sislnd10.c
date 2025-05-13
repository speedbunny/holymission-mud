

inherit "/room/south/island";
#include "_defs.h"

string add_long() 
{
    return(
     "You are standing in a small grove on the western point of the Isle.\n" +
	  "All of the trees here are either diseased, dead or heavily mutated.\n" +
	  "On the very end of the point stands an old, crumbling stone pedestal.\n" +
	  "Legend has it that Arcanarton mounted some sort of a magic focusing\n"+
	  "device here, and used the energy it collected to increase the power.\n" +
	  "of his spells. The device is now nowhere to be found. The shore of\n" +
	  "of the island continues east and southeast into a small grove from\n" +
	  "here.\n");
}

string *add_items()
{
   return ({
   "pedestal","A crumbling stone pedestal. On it are inscribed the words:\n"+
   "Seek the windy icy wastes, and find the pattern therein,\n"+
   "to find the portal to the lair of that evil creature",
   "grove","A grove of diseased, dead or heavily mutated trees",
   });
}

string *add_dirs()
{
   return ({
   PATH+"sislnd11","east",
   PATH+"sislnd9","southeast",
   });
}

