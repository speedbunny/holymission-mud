inherit "room/room";
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "Throne room";
    no_castle_flag = 1;
  long_desc = 
        "You are in the middle of a beautiful decorated room.\n"+
        "A woodoaken throne is standing in the middle.\n"+
        "On the walls are some paintings showing the former\n"+
        "owners of the castle. However the tower now seems deserted.\n";

      dest_dir = ({ "players/dice/quest/tower/to0","down",
                    });
          items = ({
               "room","A beautiful decorated room",
       "trone","A woodoaken throne with a wooden crown on it",
  "woodoaken throne","A woodoaken throne with a wooden crown on it",
               "walls","They are solid and decorated with some paintings",
               "paintings","Some paintings showing the former owners of the tower",
               "owners","They seem to have deserted this tower",
               "dust","It's lying on everything",

              });

  smell = "The air is a bit dull here.";
}
init(){  
    ::init(); 
 add_action("_sit","sit");
   }
_sit(str){
    if(!str){
     notify_fail("Sit where ?\n");
     return 0;
     }
     if(str=="on throne"){
      write("You sit down on the throne, and start to think about the former\n"+
            "owners of this tower.\n\n\n"+
            "SUDDENLY,\n"+
            "The throne starts to twist around and turns around into the wall\n"+
            "By the speed of the turning thrown you get thrown into a small room\n"+
          "behind this room.\n");
            this_player()->move_player("X#players/dice/quest/tower/to3");
            say(this_player()->query_name()+ "sits on the throne, and starts to think\n"+
            "SUDDENLY the throne turns around, and reappears empty.\n");
            return 1;
            }
      }

