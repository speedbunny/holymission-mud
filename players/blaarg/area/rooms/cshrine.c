#include "/players/blaarg/defs.h"
inherit "room/room";
reset(arg) {
    if(!arg) {
	set_light(1);
	short_desc="Shrine",
	long_desc=	
		"The shrine, made in the honor of Shinto, is plain\n"+
		"inside and out. However the presence of the Shinto\n"+
		"Gods is ever-present, and their power wards against\n"+
		"attacks of any kind in here. This is truly a safe\n"+
		"haven. A sign is on the west wall.\n";
	dest_dir=({
		AROOMS+"road4", "east",
		 });
	property=({
		     "no_steal","no_fight","no_teleport",
		 });
	items=({ 
	  "altar","A book of shinto worship lies open on the altar",
	  "book","The writing is in a language you do not understand",
	  "sign","You can pray here to resurrect yourself if you are Shinto.\n"+
		 "You may also use this shrine as a safe haven from attacking\n"+
	        "monsters, but if one drop of blood is spilt, may the\n"+
		 "wrath of the gods be merciless in your punishment.\n"+
		 "--Blaarg\n",
	      });
	smell = "This place is a bit dusty";
	::reset(arg);
    }
}

init()
{
  ::init();
  add_action("pray","pray");
}

int pray() {
   if(this_player()->query_religion() == "Shinto") {
        this_player()->remove_ghost(); }
   else {
        this_player()->remove_ghost();
        this_player()->set_religion("Shinto");
   }
}