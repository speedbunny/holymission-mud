#define TP this_player()
#define TPN TP->query_name()
#define PATH "/players/goldsun/nottingham/room/"

inherit "/room/room";

#include "/players/whisky/genesis/sys/break_string.h"


void reset (int arg){

if (!arg){

clone_list=({1,1,"rutenos","/players/goldsun/nottingham/monster/rutenos",0});

set_light(1);

short_desc="In the smithy";

     long_desc= break_string(
	"Smoke and steam fill the air here. A toolrack is hanging "+
	"on the east wall and a pile of scrap metal lies in the corner. "+
	"There is a sign on the wall here.\n",65);

items = ({"sign"," A wooden sign. There is something written on it",
          "floor", "It is a polished hardwood floor"
        });

smell = "You smell smoke of hot steel";


dest_dir = ({
	     PATH +"road8","west"
           });
  }
 ::reset(arg);
}

init(){
 ::init();
add_action("read","read"); 
}

int read(string str){
  if (str=="sign"){
    write("Rutenos the very experienced blacksmith can forge\n"+
	  "a lot of things for you :\n"+
	  "  swords, helmets, platemails, shields, etc.\n"+
	  "Just 'ask' him 'to forge <thing>' for you.\n"+
	  "Example: ask rutenos to forge sword for 2000\n\n"+
          "Advice : if you want to save your money, pay max. 23000gc\n");
    return 1;
  }
  notify_fail("Read what?\n");
  return 0;
}

