inherit "room/room";
#include "/players/gareth/define.h"
int searched;

reset(arg) {
  ::reset(arg);
  if(!arg) {

  set_light(1);
  short_desc = "lower level";
  long_desc = 
   "This room appears larger than from it's outside appearance.\n"+
   "Shields and spears decorate three walls, while the fourth\n"+ 
   "wall is taken up by armour.  A large oaken table sits in the\n"+ 
   "center of the room with twelve chairs around it.  A large sign\n"+
   "hangs from the ceiling.\n";
  
  items = ({
    "table","A large wooden table with a spider carved into its surface",
    "shields","Large shields that bare many emblems, they are fimrly secure against the wall",
    "spears","Long golden spears, they are melded to the wall",
    "armour","Armour of all types are imbedded into the wall",
    "sign","why don't ya try reading it dipstick!"
    });

  dest_dir = ({
    ETOWN+"hcell","down",
    ETOWN+"lvl2a","up",
    ETOWN+"excave","out",
  
     });

}
}

init()
{
  AA("read","read");
  AA("_search","search");
  ::init();
}

read(str) {
	if (str =="sign") {
	write("		ONLY THE FIERCE SHALL LIVE!!! \n");

	return 1;
	}
}

status _search(string str) {
       if(!str || !str="armour") {
       NF("What do you want to search?\n");
       return 0;
  }
       if(!searched) {
       write("You find a great piece of armor!!\n");
       TR(CO(ITEM+"mail"), TP);
       searched = 1;
       return 1;
  }
       write("There's nothing but useless armor left. \n");
       return 1;
}	    
