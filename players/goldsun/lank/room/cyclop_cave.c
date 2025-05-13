inherit "/room/room";
#include "/players/goldsun/stand.h"

object cyclop; 

reset(arg){
 ::reset(arg);

  if (!cyclop) 
  {
  cyclop=clone_object("/players/goldsun/lank/monster/cyclop");
  transfer(cyclop,this_object());
  }

  if (!arg) {

  set_light(0);
  short_desc = "A dark cave";
  long_desc =
"You are standing in the middle of a very dark, smelly cave.\n"+
"All around you are signs of some enormous monster that has lived\n"+
"here for some time.  Steaming away in a corner, is a pile of what\n"+
"smells like a heap of dung.  In the middle of the cave, hollowed\n"+
"out of the rock floor, is a pit, in which a large fire is roaring\n"+
"away.  Above the fire is a spit, for roasting food on.  Littered\n"+
"around the whole cave are bones of all shapes and sizes, mostly\n"+
"gnawed, and shattered into small pieces.\n";

  property = ({"has_fire"});
  smell = "The foul odour that is around you almost makes you faint\n"+
	  "due to the disgusting nature of the things in the room.\n";
  no_castle_flag = 1;
  dest_dir = ({"/players/goldsun/lank/room/lank4.c","out"});
  items = ({
  "cave",
"The dark cave you are standing in is very large, with a ceiling way up "+
"out of sight above you",
  "dark cave",
"You are standing in the middle of a very hot, clammy cave that smells "+
"positively awful",
  "fire",
"Flap. Flap. The fire is exceedingly hot.  With the spit above it, it "+
"looks as though you could easily roast something on it",
  "damp cave",
"The cave is damp and dark"
  "bones",
"These look as though they have come from all sorts of animals, ranging "+
"from huge elk and reindeer, to the strangely familiar sized bones "+
"from what appears to be man_sized..",
  "pit",
"A large fire is roaring away from it",
  "spit",
"A spit for roasting food",
  "dung",
"A heap of dung. Wanna search it?"

    });

  }
}

init(){
 ::init();

add_action("roast","roast");
add_action("search","search");
}

int roast(string str){
 object corp,meat;

 if (str=="corpse"){
  if (present("corpse",TP) ){
    write("You roast the meat on the spit.\n");
    say(OPN+" roasts the meat on the spit.\n");
    if (present("corpse of sheep",TP)){
     corp=present("corpse of sheep",TP);
     meat=clone_object("/players/goldsun/lank/obj/meat_ok");
     transfer(meat,TP);
     destruct(corp);
     return 1;
     }
    else{
     corp=present("corpse",TP);
     destruct(corp);
     meat=clone_object("/players/goldsun/lank/obj/meat_bad");
     transfer(meat,TP);
     return 1;
    }
   }
  else write("But you have no corpse.\n");
  return 1;
  }
 write("Roast what ?\n");
 return 1;
 }

int search(string str){
 return 1;
 }
