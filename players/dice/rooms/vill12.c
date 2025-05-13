

inherit "room/room";

reset(arg){::reset(arg);
 if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Village plain";
   long_desc =
     "You are in the northern part of the village, and standing\n"+
     "in the middle of an open plain there are all kinds of ways \n"+
     "out of here, but you can recognise only four. \n"+
     "In the middle of the plain stands a large tree which reaches its \n"+
     "leaves high into the sky in an endless attempt to reach the clouds. \n";
   dest_dir = ({
      "players/dice/rooms/vill9a","south",
      "players/dice/rooms/vill13","north",
      "players/dice/rooms/vill16","east",
      "players/dice/rooms/vill14","west"
       });

   items =({
            "clouds","Huge clouds drifting in the sky",
            "tree","A strange looking tree standing in the middle of the plain",
            "plain","A large open plain",
            "village","A coalminer village",
            "cloud","Clouds drifting through the sky",
            "ways","Four exits",
            "large tree","A strange looking tree, standing in the middle of the plain",
            "leaves","Strange looking leaves"
            });


   smell = "The smell of fresh woods fills the air .\n";

  }

init() {
  ::init();
  add_action("enter","enter");
  add_action("climb","climb");
  }

enter(str){
 if(!str){
  notify_fail("Enter what ? \n");
  return 0;
  }
  if(str=="tree" || str=="strange tree"){
   write ("You step into the tree. \n");
   this_player()->move_player("enters the tree#/players/dice/rooms/tree1");
   return 1;
  }
}

climb(str) {
  if (!str) {
    notify_fail("Climb what ?\n");
    return 0;
    }
  if ((str == "tree")||(str == "large tree")||(str == "strange tree")) {
    this_player()->move_player("climbs the tree#/players/dice/rooms/tree2");
    destruct(this_object());
    return 1;
    }
  }
