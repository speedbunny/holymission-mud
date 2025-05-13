inherit "room/room";
query_no_teleport() { return 1; }
reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc = "Cave";
    no_castle_flag = 1;
    no_obvious_msg="";
    long_desc=
               "You are standing on what's left of the ledge.\n"+
               "This cave looks a lot like the first cave, but\n"+
               "the heat is not as intense here.\n"+
               "The roof of this cave is high, and unreachable.\n";
          items = ({
                    "ledge","What's left of the ledge",
                    "cave","This cave looks like the other cave",
                    "heat","The temperature has lowered here",
                    "roof","The roof of the cave, giving a small lightbeam",
                    "lightbeam","It looks like sunlight, coming through a hole",
                     "hole","A small hole, maybe you can reach it",
              });

     smell = "The smell of suplher is not that strong anymore.";
}
init(){  
    ::init(); 
  add_action("reach_hole","reach");
  add_action("jump_hole","jump");
   add_action("walk_ledge","walk");
   }
reach_hole(str){
  if(!str){
  notify_fail("Reach what ?\n");
  return 0;
  }
if((str=="hole")||(str=="hole in ceiling")){
write("You stand up straight, and try to reach the hole.\n"+
      "But you are too short to reach the hole.\n"+
       "Maybe if you'd jump up to the hole you could grab on and climb out.\n");
      return 1;
      }
    }
jump_hole(str){
   if(!str){
   notify_fail("Jump to what ?\n");
  return 0;
  }
if((str=="to hole")||(str=="to hole in ceiling")){
  write("You jump with all your might and grab a hold at the ceiling.\n"+
        "With great effort you succeed climbing through the hole, \n"+
        "and see the light of day.\n");
this_player()->move_player("though the hole#players/dice/quest/q9");
  return 1;
  }
 }
walk_ledge(str){
  if(!str){
  notify_fail("Walk where ?\n");
  return 0;
  }
if((str=="over ledge")||(str=="over small ledge")){
 write("That's not possible, there is not enough \n"+
       "left of the ledge to walk over.\n");
return 1;
  }
 }
