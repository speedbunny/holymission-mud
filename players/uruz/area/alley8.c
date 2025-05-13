inherit "room/room";
#include "/players/trout/defs.h"

reset(arg) {
	if(arg) return;
	set_light(1);
	short_desc= "Dead End";
	long_desc= "You've come to the end of this alley. From the door "+
	"to your left you hear the sounds of music, and cheers. The door "+
	"has no handle on this side. Maybe you should knock? \n";
	DD= ({ ZZ+"/alley7", "north" });
	}
init() {
	::init();
	AA("_knock", "knock");
	AA("_pword", "say");
	AA("_pword2", "'usegi");
	AA("_pword2", "'Usegi");
	    }
	
	_knock(str) {
			if(!str||str=="door"){
					notify_fail("Knock on what? \n");
					return 0;
				}
			if(str=="on door"){
			write("A small peephole slides open on the door. A "+
			"pair of evil looking eyes stare at  you. From the "+
			"peephole a gruff voice tells you, 'Say the pass"+
			"word?' \n");
			return 1; }
		      }
	_pword(str){
		     if(str=="usegi sent me"||str=="Usegi sent me")
			{ write("The door opens, and you walk in. \n");
			  this_player()->move_player("east#"ZZ+"/gamb1"); 
			  return 1; }
		     if(!str){
				   write("The bouncer tells you wrong "+
					    "password! \n");
				     return 1;
			         }
		     }
	_pword2(str){
		if(str=="sent me"){
		       write("The door opens, and you walk in. \n");
		       this_player()->move_player("east#"ZZ+"/gamb1");
			return 1; }
		else { 
			write("The bouncer tells you wrong password! \n");
			 return 1; 
		      }
 		}
