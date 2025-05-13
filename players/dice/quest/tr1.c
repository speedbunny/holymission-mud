inherit "room/room";
reset(arg) {
    if (arg) return;

    set_light(1);
    property = "no_teleport";
    short_desc = "Tree";
    no_castle_flag = 1;
    no_obvious_msg="";
    long_desc=
        "You are sitting on top of a big tree.\n"+
        "You see the river running at the roots of the tree.\n"+
        "In the distance you can see the steeple of a church but it\n"+
        "seems impossible for you to recognise which church it is.\n"+
        "The leaves are waving in the wind.\n";
          items = ({
               "tree","The top of the tree, maybe you can risk a jump",
               "top","The top of the tree, maybe you can risk a downward jump",
               "river","A river at the roots of this tree",
               "distance","Really far away",
               "church","It looks like the local village church",
               "leaves","Green leaves",
               "wind","Brisk breeze isn't it ??",
               "roots","The roots of this tree",
              });

    smell = "SNIIIIFFFFFF, that smells fresh.";
}
init(){  
    ::init(); 
    add_action("jump","jump");
   }
jump(){
   write("You close you eyes and jump.\n");
   this_player()->move_player("down#players/dice/quest/q4");
  return 1;
  }
