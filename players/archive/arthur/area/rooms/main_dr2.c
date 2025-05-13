/*This room changes after you finish the quest ARTHUR 11.9.94*/
#define EXTRA_RESET
inherit "/room/room.c";
#include "/players/arthur/defs/ardefs.h"
  
string tc;     

reset(arg) {
	if(!arg) {
	set_light(1);
	short_desc = "Sherwood Village";
	dest_dir=({AAREA+"main_dr3", "north",
		   AAREA+"main_dr1", "south",
		   AAREA+"alley_1", "west",
		   AAREA+"alley_4", "east"});}
	EXTRA_RESET}

init() {
	add_action("mth","look");
	add_action("mth","l");
	mth();
	::init();
       }

mth() {
	if (TP()->query_quests("orc_slayer") == 0){ 
tc = "     You are standing at the entrance to Sherwood. The village\n"+
"continues towards the north. Far to the north, you can see what looks\n"+
"like a forest. People are walking about in a fast pace, trying to avoid\n"+
"visual contact with other people as much as possible.\n";}
    else {
tc="     You are standing at the entrance to Sherwood. The village\n"+
"continues towards the north. Far to the north you can see what looks.\n"+
"like a forest. All of the villagers stop, and start looking at you. \n"+
"their looking at you makes you proud of being their savior.\n";}
long_desc = tc;
	}



