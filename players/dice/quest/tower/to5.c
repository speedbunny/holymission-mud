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
              "wall","A very thick wall indeed",
              "outer wall","The outer wall of the tower",
              "outer walls","The thick outer walls of the tower",
              });
           dest_dir = ({ "players/dice/quest/tower/to4","up",
                         "players/dice/quest/tower/to6","down"
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
 notify_fail("The wall seems to move a bit, but not enough\n");
   say(this_player()->query_name()+" tried to move the wall.\n");
    return 0;
    }
_turn(str){
 if(!str){
 notify_fail("Turn what ?\n");
 return 0;
 }
  if(str=="wall"||str=="thick wall"){
  write("You turn the wall around, and fall through the hole it made.\n");
  say(this_player()->query_name()+" pushes against the wall, and vanishes.\n");
  this_player()->move_player("through the wall#players/dice/quest/tower/to7");
  return 1;
  }
}
_smash(str){
    notify_fail("You try to break the wall down with all your might.\n"+
                "But it seems to have no effect.\n");
    return 0;
 }
