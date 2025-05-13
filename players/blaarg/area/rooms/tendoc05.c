#include "/players/blaarg/defs.h"
inherit "room/room";
object claws;
int unlocked,lifted,find;
reset(arg) {
	clone_list = ({
		1,1,"ranma",MOB+"ranma",0,
		-1,1,"jacket",ARMOUR+"ranmajac",0,
		-1,1,"cap",ARMOUR+"ranmahat",0,
	});	
	set_light(1);
	unlocked=0;lifted=0;find=0;
	short_desc="Tendo Dojo--Ranma's Bedroom",
	long_desc=
	    "This is Ranma's bedroom. Although he doesn't seem to care\n"+
	    "that you have intruded, he watches you with a wary eye.\n"+
	    "He seems ready for any type of attack, and he looks quite\n"+
	    "strong. In the room there is a rug, a bed, a closet, a window,\n"+
	    "a dresser, and some pictures on the dresser.\n";
	dest_dir=({
	    AROOMS+"tendoc04","southwest",
		 });
	items=({
	   "rug","A beautiful, handcrafted rug, depicting Moose's Claws", 
	   "bed","A very beautiful hardwood bed, with fine silk covers",
	   "window","At this height, you can see all of the village",
	   "dresser","Beautiful hardwood, hand carved. You cannot open it",
	   "picture","A picture of Akane, and a picture of Genma", 
	   "closet","The closet contains Ranma's school outfits",
	   });
	smell = "Ranma's room smells he has just been practicing karate";
	::reset(arg);
	if(arg) return;
}

init()
{
  ::init();
  add_action("search","search");
  add_action("lift","lift");
  add_action("unlock","unlock");
}

  search(str) {
	if (str=="opening" && unlocked){
	  say(this_player()->query_name()+" searches the opening.\n");
	  find_treasure();
	  return 1;
	}
	if (str!="opening"){
	   write("Search What?\n");
	   return 1;
        }
	if (str=="opening" && !unlocked){
	  say(this_player()->query_name()+" tries to search the opening,\n"+
	      "but it is locked!\n");
	  return 1;
	}
  }

  lift(str){
	if (str=="rug" || str=="mat"){
	  if(present("ranma",this_object())) {
	     write("You can't lift the mat with Ranma on it!\n");
	     return 1;
	  } else {
	     say(this_player()->query_name()+" lifts the mat.\n");
	     write("You find a secret door!\n");
	     lifted=1;
	     return 1;
	  }
	}
	say("Lift what?\n"); 
	return 1;
  }

  unlock(str){
  	if (present("clawkey",TP) && lifted) {
	  write("You unlock the door and find an opening.\n");
	  unlocked=1;
     	  return 1;
  	}
  	write("You fail to open the door.\n");
        say(TP->NAME+" fails to open the door.\n");
  	return 1;
  }

find_treasure() {
  object claws;

	if(find) {
	  write("You search and search, but find nothing.\n");
	  return; 
	}
	find=1;
	write("You found Moose's Claws!\n");
	claws=clone_object("/players/blaarg/stuff/quest_stuff/claws");
	transfer(claws,this_player());
	return;
}
