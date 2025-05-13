#include "/players/blaarg/defs.h"
inherit "room/room";

int find;

#define CNAME   capitalize(NAME)

reset(arg) {
    if(!arg) {
	object bottle;
	set_light(1);
	

	short_desc="Special Shop",

	long_desc=
		"What once used to be a special items shop is now an\n"+
		"abandoned wreck. There is dust everywhere, and what\n"+
		"used to be a counter is rotted away to little much\n"+
		"but sawdust.\n";

	dest_dir=({
		AROOMS+"road5", "east",
		 });

	items=({ 
	    "air","It is quite dusty on this street",
	    "road","The road is well-travelled",
	    "dust","It is so thick who knows what might be underneath!",
	    "sign","Welcome to the special shop",
	      });
	smell = "This place is a bit dusty";

    }
  find=0;
}

init()
{
  ::init();
  add_action("search","search");
}

  search(str) {
	if (str=="dust"){
	  say(this_player()->query_name()+" searches the dust.\n");
	  find_treasure();
	  return 1;
		      }
	if (str!="dust"){
	   write("Search What?\n");
	   return 1;
	     }
  }

find_treasure() {
  object bottle;

	if(find) {
	  write("You search and search, but find nothing.\n");
	  return; 
	}
	find=1;
	write("You found a bottle!\n");
	bottle=clone_object("/players/blaarg/stuff/quest_stuff/bottle");
	transfer(bottle,this_player());
	return;
}


