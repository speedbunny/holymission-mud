inherit "room/room";
reset(arg) {
    if (arg) return;

    set_light(1);
    property = "no_teleport";
    short_desc = "Forest";
    no_castle_flag = 1;
    no_obvious_msg="";
    long_desc=
        "You have entered the dark forest.\n"+
        "You see big trees standing all around you.\n"+
        "The forest looks very thick.\n"+
        "There seem to be no exits.\n";
          items = ({
              "forest","The dark forest",
              "dark forest","The big forest",
              "trees","Big trees standing all around here",
              "tree","Just a normal tree",
              "exit","Maybe you can try to 'leave' this forest",
              "exits","Maybe you can try to 'leave' this forest",
              });

    smell = "SNIIIIFFFFFF, that smells fresh.";
}
init(){  
    ::init(); 
    add_action("out_forest","out"); add_action("out_forest","leave");
     add_action("out_forest","run");
     add_action("climb_tree","climb");
   }
out_forest(str){
  if(!str){
  notify_fail("Leave what? \n");
  return 0;
  }
if((str=="forest")||(str=="dark forest")){
    write("You take a deep breath, and run out of the forest.\n");
    this_player()->move_player("through the woods#players/dice/quest/q5.c");
    return 1;
    }
  }
climb_tree(str){
  if(!str){
  notify_fail("Climb where ?\n");
  return 0;
  }
if ((str=="tree")||(str=="big tree")){
   write("You try to climb the tree, but you fail.\n"+
         "The tree is too steep to climb.\n");
   return 1;
   }
 }
