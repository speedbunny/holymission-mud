inherit "room/room";
#include "/players/trout/defs.h"
int i, j;
object what;
string a;
object *ob;

reset(arg){
	if(arg) return;

	set_light(1);
	short_desc="Gallery";
	long_desc="You are now in a well furnished gallery. Within this room"+
	" is the personal collection of Daimyo Tokugawa. Vases, paintings, "+

	"and other works of art are on dislay here. These objects have been"+
	" collected from Tokugawa's victories. To steal any one of these "+
	"priceless works would mean immediate execution! \n";
	DD= ({ ZZ+"/guard1", "west",		
		ZZ+"/guard2", "east",
		ZZ+"/tearoom", "stairs" });	
	items= ({ "works", "gotta figure out how to handle this one" });
	clone_list = ({1, 3, "guard", MM+"/guard1", 0});
	::reset(arg);
	for(i=0; i<3 + RAN(5); i++)
	 {
	   switch(RAN(3))
	      {
		case 0: MO(CO(YY+"/obj/painting"), TO());
			        break;
		case 1: MO(CO(YY+"/obj/statue"), TO());
				 break;
		case 2: MO(CO(YY+"/obj/vase"), TO());
				 break;
	       }
	 }
	}
init(){
	::init();
	AA("_take", "take");
	AA("_take", "get");
	}
_take(string str){
 object env, *ob;
 int i, j;
	if(str=="painting" || str=="vase" || str=="statue" ){
		write("You take the "+str+" without the guards noticing!\n");
		MO(CO(YY+"/obj/tag1"), TP());
		MO(CO(YY+"/obj/"+str), TP());
		env= environment(TP());
		ob= all_inventory(env);
		j= sizeof(ob);
		for(i=0; i<j; i++){
		     if(ob[i]->query_name()==str){
			   destruct(ob[i]);
			  }
		   }
		return 1;
		}
	}
