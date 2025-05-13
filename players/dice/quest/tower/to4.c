inherit "room/room";
reset(arg) {
    if (arg) return;
    set_light(0);
    short_desc = "Walls";
    no_castle_flag = 1;
     long_desc =
        "You are standing between the walls of the tower. \n";

          items = ({
               "walls","They are solid and thick",
               "dust","It's lying on everything",
               "tower","A small and dark tower",
              "wall","A very thick wall",
              "outer wall","The outside wall of the tower",
              "outer walls","The outside walls of the tower",
              });
           dest_dir = ({ "players/dice/quest/tower/to3","up",
                         "players/dice/quest/tower/to5","down"
                      });
  smell = "The air is dull and dusty here.";
}
init(){
   ::init();
  add_action("_move","move");add_action("_move","push");
 add_action("_turn","turn");add_action("_smash","smash");
 add_action("_smash","break");
  }
_move(str){
  notify_fail("You try to move the wall, but you don't succeed.\n");
   say(this_player()->query_name()+" tried to move the wall.\n");
    return 0;
    }
_turn(str){
  notify_fail("You try to turn the wall around, but it won't move.\n");
  say(this_player()->query_name()+" tried to turn the wall around.\n");
 return 0;
 }
_smash(str){
    notify_fail("You try to break the wall down with all your might.\n"+
                "But it seems to have no effect.\n");
    return 0;
 }
