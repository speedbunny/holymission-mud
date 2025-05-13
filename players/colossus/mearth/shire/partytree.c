#include "mroom.h"
object squirrel;
int i;

void reset(int arg){
    ::reset(arg);
    if(!present("squirrel"))
	for(i=0;i<5;i++){
	    squirrel=clone_object("obj/monster");
	    squirrel->set_level(2);
	    squirrel->set_name("squirrel");
	    squirrel->set_short("Angry squirrel");
	    squirrel->set_long(
	      "As a rule squirrels aren't really very aggressive but this one is because\n"+
	      "you've just woken it up. With teeth that can chew through wood it may be\n"+
	      "small but it sure is dangerous.\n");
	    squirrel->set_aggressive(2);
	    squirrel->set_whimpy(-1);
	    squirrel->set_race("squirrel");
	    squirrel->set_size(2);
	    squirrel->set_spell_mess1(
	      "The squirrel chomps on "+previous_object()->query_name()+"'s feet.\n");
	    squirrel->set_spell_mess2("The squirrel chomps on your feet.\n");
	    move_object(squirrel, this_object());
	}
    if(arg) return;
    set_light(1);
    short_desc = "Top of tree";
    long_desc =
    "You manage to haul yourself up the tree. Midst the tangle of branches\n"+
    "you see a squirrel hole. It's big enough to house several squirrels and\n"+
    "you best not be here when they find you poking around their hole.\n";
    dest_dir = ({
      SHIRE+"/main2", "down",
    });
    items = ({
      "branches", "Firm oak branches",
      "tree", "A huge oak tree",
      "hole", "A squirrel hole that's big enough to hole several squirrels",
    });
}
