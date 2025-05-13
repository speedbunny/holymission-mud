inherit "room/room";


reset(arg) {

    if(arg) return;
    set_light(1);
    short_desc="A tree";
   long_desc="You are standing on a tree. The branches of the tree are bare.\n"
             +"There is a glowing portal that looks a little out of place.\n"
              +"A wooden ladder leads down.\n";

    dest_dir=({
        "players/portil/games/othello","portal",
    });

    items = ({
        "branches", "They are all bare",
        "branch","They all look the same",
        "ladder","Its made of wood and it leads down",
       "tree", "It looks like it could have died. There are no leaves on any of the branches",
         "leaves", "There aren't any leaves here the tree is bare",
         "portal","It shines a light blue"
    });	

}

init() {
      ::init();
      add_action("dwn","down");
      add_action("dwn","climb");
      }

dwn() {
      say(this_player()->query_short_name()+" climbs down the ladder.\n");
      move_object(this_player(),"/players/cashimor/extend/village1");
      write("You climb down the ladder.\n");
     command("look",this_player());
     say(this_player()->query_short_name()+" climbs down the ladder.\n");
      return 1;
      }
