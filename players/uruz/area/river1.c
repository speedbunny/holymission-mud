inherit "room/room";
#include "/players/trout/defs.h"

int i, j, rnd;
int  done;
object *ob;

reset(arg){
	::reset(arg);
	done=0;
        if(arg) return;
	set_light(0);
	short_desc="A Cavern at the Bottom of the Ane";
	long_desc="You have entered a hollowed out cavern at the bottom of "+
	"the Ane river. It is very difficult to see in here. The walls "+
	"seem to almost absorb the light. You get an erie feeling being in "+
	"here! \n";
	"dark down here. The light here is barely visible. The floor "+
	"is very soft, and littered with stones. \n";
	
	items= ({ "floor", "It's soft and squishy" });
	rnd= 1+RAN(4);
	for(i=0; i<rnd; i++){
			MO(CO(YY+"/mobs/fish"), TO());
	}
	DD= ({ ZZ+"/river2", "up" });
	}
init(){
	::init();
	AA("_bait", "bait");
	}
_bait(str){
	if(!str){
		notify_fail("Bait who? \n");
		return 0; }
	if(str=="leviathan"){
		notify_fail("Bait Leviathan with what?\n");
		return 0;}
	if(str=="leviathan with bloody fish" || str=="leviathan with fish")
		{
		if(!present("bloody fish", TP()))
		   { notify_fail("You don't have any bloody fish!\n");
		     return 0;
		   }
		if(done){
			write("You set the bait, but nothing happens!\n");
			return 1;
			}
		if(present("bloody fish", TP()))
			{  write("You set up a fish blood bait.\n");
			 TLR(TO(), "A large, dark shadow moves from the "+
			  "distance! \n");
			 TLR(TO(), "A huge leviathan has arrived! \n");
			 MO(CO(MM+"/leviathan"), TO());
			done= 1;
			ob= all_inventory(this_player());
			j= sizeof(ob);
			for(i=0; i<j; i++){
			    if(ob[i]->query_name()== "bloody fish"){
				destruct(ob[i]);
				 }
 			}
			return 1;
			 }
		}
	}
