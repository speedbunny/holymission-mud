inherit "room/room";
reset(arg) {
    if (arg) return;

    set_light(1);
    property = "no_teleport";
    short_desc = "Ledge";
    no_castle_flag = 1;
    no_obvious_msg="";
    long_desc=
        "As you emerge from the hole you almost fall into a river of lava.\n"+
        "The intense heat is really painful, but you manage to remain upright.\n"+
        "You are standing on a small and thin ledge, which looks very unstable.\n"+
        "Maybe it will fall apart when you walk over it.\n";
          items = ({
               "hole","The not collapsed part of the red glowing hole",
              "heat","The intense heat coming from the lava",
              "lava","Melted rocks and stones",
              "river","A river of lava",
              "small ledge","A small ledge over the river of lava",
     "ledge","A small ledge over the river of lava.\nMaybe you can walk over it",
              });

    smell = "The air is filled with the smell of sulphur and ashes.";
  }
init(){  
    ::init(); 
    add_action("walk_ledge","walk"); add_action("walk_ledge","step");
    add_action("enter_hole","enter");
   }
walk_ledge(str){
    if(!str){
     notify_fail("walk where ?\n");
     return 0;
     }
     if((str=="over ledge")||(str=="over small ledge")){
     write("You carefully walk over the small and thin ledge.\n"+
       "The heat is tremendous now, and you don't feel very well.\n\n\n");
     this_player()->move_player("over the ledge#players/dice/quest/q8");
     return 1;
     }
    }
enter_hole(str){
  if(!str){
  notify_fail("Enter what ?\n");
  return 1;
  }
if((str=="hole")||(str=="red hole")||(str=="red glowing hole")){
   write("You climb into the hole.\n");
   this_player()->move_player("into the hole#players/dice/quest/hole");
    return 1;
    }
  }
