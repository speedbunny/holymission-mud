

inherit "room/room";

object soap;

reset(arg){::reset(arg);
      if(!arg){
      if(!soap){
     soap=clone_object("/players/dice/items/soap");
     move_object(soap,this_object());
     }


if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Bath room";
   long_desc =
     "This is the bath room of the coalminer family.\n"+
     "Smells really sweaty here, because working in a mine is really hard \n"+
     "and heavy work. "+
     "But the smell of coals is less strong here.\n"+
     "A huge bath is standing beside the mirror.\n";

   dest_dir = ({
      "players/dice/rooms/house1","southwest",
             });

   items =({
          "shower","An ordinary shower",
          "boiler","A huge boiler used to heat water",
          "bath","A huge bath, smelly and dirty",
          "mirror","WOWooow, thats an ugly face"
            });

   smell = "This bathroom smell like a bunch of football-players have been \n"+
           "taking showers here for ten years, without cleaning";
  }
}
init() {
  ::init();
  add_action("wash","wash");
  }

wash (str) {
  if (!str) {
    notify_fail("What do you want to wash?\n");
    return 0;
    }
  if ((str == "face")||(str == "me")||(str == "myself")) {
    write("You wash yourself with a lot of water and feel refreshed.\n"+
          "You nearly use up all the hot water from the boiler and decide\n"+
          "not to wash any further.\n"+
          "After drying your face you feel better and want to move on.\n");
    return 1;
    }
}
