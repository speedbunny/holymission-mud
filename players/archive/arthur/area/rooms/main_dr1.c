/*This room changes after you finish the quest ARTHUR 11.11.94*/
#define EXTRA_RESET
inherit "/room/room.c";
#include "/players/arthur/defs/ardefs.h"
  
string tc;     

reset(arg) {
	if(!arg) {
	set_light(1);
	short_desc = "Sherwood Village";
	dest_dir=({AAREA+"main_dr2", "north",
		  "room/church", "south"});}
	EXTRA_RESET}

init() {
	add_action("mth","look");
	mth();
	::init();
       }

mth() {
	if (TP()->query_quests("king_arthur") == 0){ 
tc = "     You are on King Arthur's island. This is the road that leads\n"+
"north into the small town built on this island. To the far north, you can\n"+
"see what looks like a forest. The people are hustling around in what looks\n"+
"like a semi-panic.\n";}
    else {
tc="      You are on King Arthur's island. This is the road that leads\n"+
"north into the small town build on this island. To the far north, you can\n"+
"see what looks like a forest. All the people are standing around, in a very\n"+
"calm orderly manner. Every so often people come up and thank you for\n"+
"saving their town.\n";}
long_desc = tc;
	}



