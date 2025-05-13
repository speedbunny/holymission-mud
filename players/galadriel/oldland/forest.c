/* ################################################################################### 
 
           THE INHERITANCE FOREST
           
  ################################################################################### */

inherit "room/room";

#include "/players/skeeve/area.h"
#define CN capitalize(this_player()->query_name())
#define TR(x) tell_room(this_object(),x)
#define RINT random(this_player()->query_int() / 4 +1)
int branch;

reset(arg,DEST_DIRS) {
  branch = 3;
  
  if (arg) return;
  set_light(0);
  short_desc = "In the dark forest of druid Lakmir.";
  long_desc =
    "You are standing in a dark forest. Big dark oaks and beeches\n"+
    "are surrounding you. You feel as they are watching you !\n"+
    "There is a snapping and rustling around you.\n";
  smell="You smell the trees, herbs and the urin of several monsters";
  dest_dir = DEST_DIRS;
  items =
    ({"bottom", "There are so much leaves and stones, that you cannot sea the ground.\n"
                 +"You consider what may be under it",
     "ground", "There are so much leaves and stones, that you cannot sea the ground.\n"
                 +"You consider what may be under it",
     "forrest","This forest consists of oaks and beeches",
     "oaks","Dark big oaks",  
     "oak","There are so many of them,\n",  
           "You can hardly eye any special",
     "beeches","Dark big beeches",  
     "beech","There are so many of them,\n"  
           + "You can hardly eye any special",
     "stones", "There is nothing special on this stones"
    });
}

init() {
  ::init();
  add_action("climb","climb");
  if (!random(5) && this_player()->query_player() &&  !present ("gmonster"))
    move_object(clone_object(MONSTERS+"gmonster")->config(),this_object());
}
    
/* overwirte the standart search routine */
do_ser(str) {
  object br;
  
  if (this_player()->query_ghost()) {
     write("You can't do that in your immaterial state.\n"); 
     return 1; 
  }

  if (!random(4) ) {
    if (!present ("wolf")) {
      TR("Suddenly you get the feeling that you are watched.\n");
      move_object(clone_object(MONSTERS+"gmonster")->config("wolf"),this_object());
      return 1;
    }
    if (!present ("fox")) {
      TR("Suddenly you get the feeling that you are watched.\n");
      move_object(clone_object(MONSTERS+"gmonster")->config("fox"),this_object());
      return 1;
    }
  }

  if (str == "branch") {
    if ( random (branch) && RINT ) {
      write("You search and find a branch!\n");
      say(CN +" searches and finds a branch.\n");
      move_object(br=clone_object("obj/thing"),this_object());
      br->set_id("branch");
      br->set_name("branch");
      br->set_short("A small branch");
      br->set_long("A small brown branch. It looks as if it burns very well.\n");
      br->set_weight(1);
      branch --;
    } else {
      write("You search a branch but you cannot find one.\n");
      say(CN+" searches a branch but cannot find one.\n");
    }
    return 1;
  }  
 
  if ((str == "row") || (str == "rabbit") 
    ||(str == "fox") || (str == "wolf")  ) {
    if (RINT) {
      write("You search a "+str+" and find one.\n");
      say(CN + " finds a "+str+".\n");
      move_object(clone_object(MONSTERS+"gmonster")->config("str"),this_object());
    } else {
      write("You search a "+str+" but you cannot find one.\n");
      say(CN + " searches a "+str+" but cannot find one.\n");
    }
    return 1;
  }

  if ((str == "beech") || (str == "beeches") 
    ||(str == "oak")   || (str == "oaks")  
    ||(str == "under the beech") || (str == "under the beeches") 
    ||(str == "under the oak")   || (str == "under the oaks")   ) {
    if (RINT) {
      TR("Suddenly you get the feeling that you are watched.\n");
      move_object(clone_object(MONSTERS+"gmonster")->config(-1),this_object());
    } else if ( random (branch) && RINT ) {
      write("You search and find a branch!\n");
      say(CN + " searches and finds a branch.\n");
      move_object(br=clone_object("obj/thing"),this_object());
      br->set_id("branch");
      br->set_name("branch");
      br->set_short("A small branch");
      br->set_long("A small brown branch. It looks as if it burns very well.\n");
      br->set_weight(1);
      branch --;
    } else {
      write("You can nothing find.\n");
      say(CN + " searches a "+str+" but cannot find one.\n");
    }
    return 1;
  }
  
  if ((str == "ground") || (str == "at ground") ) {
    if (RINT) {
      TR("Suddenly you get the feeling that you are watched.\n");
      move_object(clone_object(MONSTERS+"gmonster")->config(-1),this_object());
    } else if ( random (branch) && RINT ) {
      write("You search at the ground and find a branch!\n");
      say(CN + " searches at the ground and finds a branch.\n");
      move_object(br=clone_object("obj/thing"),this_object());
      br->set_id("branch");
      br->set_short("A small branch");
      br->set_long("A small brown branch. It looks as if it burns very well.\n");
      br->set_weight(1);
      branch --;
    } else {
      write("You can nothing find at the ground.\n");
      say(CN + " searches a "+str+" but cannot find one.\n");
    }
    return 1;
  }
  
  if ((str == "leaves") || (str == "under leaves") || (str == "under the leaves") ) {
    if (RINT) {
      TR("Suddenly you get the feeling that you are watched.\n");
      move_object(clone_object(MONSTERS+"gmonster")->config(-1),this_object());
    } else if ( random (branch) && RINT ) {
      write("You search under the leaves and find a branch!\n");
      say(CN + " searches under the leaves and finds a branch.\n");
      move_object(br=clone_object("obj/thing"),this_object());
      br->set_id("branch");
      br->set_short("A small branch");
      br->set_long("A small brown branch. It looks as if it burns very well.\n");
      br->set_weight(1);
      branch --;
    } else {
      write("You can nothing find at the ground.\n");
      say(CN + " searches a "+str+" but cannot find one.\n");
    }
    return 1;
  }
  return;
}

climb(arg) {
  if (this_player()->query_ghost()) {
     write("You can't do that in your immaterial state.\n"); 
     return ( 1 ); 
  }

  switch(arg) {
    case "beech":
    case "beeches":
    case "oak":
    case "oaks":
      write("You try to climb one of the oaks, but you stumble and fall down.\n");
      say(CN+" tries to climb one of the oaks , but falls down.\n");
      this_player()->hit_player(random(20),2);
    break;
    
    default:
      write("You can't do that.\n");
  }
  return 1;
}
