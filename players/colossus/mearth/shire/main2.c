#include "mroom.h"
int i;
object kid, guard, gaffer, farmer;

void reset(int arg){
    ::reset(arg);
    if(!present("child")){
	for (i=0;i<3;i++)
	    move_object(clone_object(SHIRE+"/hobbit_kid"), this_object());
    }
    if(!present("guard")) {
	for(i=0;i<2;i++) 
	    move_object(clone_object(SHIRE+"/shiriff"), this_object());
    }
    if(!present("gaffer")){
	for(i=0;i<2;i++)
	    move_object(clone_object(SHIRE+"/gaffer"), this_object());
    }
    if(!present("farmer")){
	move_object(clone_object(SHIRE+"/farmer"), this_object());
    }
    if(arg) return;
    set_light(1);
    short_desc = "Under the Party Tree";
    long_desc = 
    "You enter a small park with a huge oak tree. This is the party\n\
tre where the hobbits gather for festive occasions. It happens\n\
that there is a gathering right now. Tables and small stools\n\
are set all around the tree trunk.\n";
    dest_dir = ({
      SHIRE+"/bagend1", "north",
      SHIRE+"/main3", "west",
      SHIRE+"/main1", "east",
    });
    items = ({
      "stools", "The stools are carefully carved from durable wood",
      "tables", "The tables resemble a large chair due to their extreme\n\
small size",
      "oak", "A huge oak tree that you may be able to climb",
      "tree", "A huge oak tree that you may be able to climb",
    });                                                                         
}

void init(){
    ::init();
    add_action("climb", "climb");
}

status climb(string str){
    if(str != "oak" && str != "tree" && str != "party tree"){
	notify_fail("Climb what?\n");
	return 0;
    }
    TP->move_player("up#/"+SHIRE+"/partytree");
    return 1;
}
