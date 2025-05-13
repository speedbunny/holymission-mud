inherit "room/room";

#include "/players/skeeve/area.h";

reset(arg) {
  object snake;
  if (!arg) {
    set_light(0);
    short_desc = "Cave";
    no_castle_flag = 0;
    long_desc = "You are in a big cave. You smell the odor of snakes here.\n";
    dest_dir = ({
        LAND + "valley", "east",
    });
/*
    hidden_dir = {(
      MAZE+"maze" , "down"
    )};
*/

  }
  CASTLE->add_sphinx_obj("skull",this_object());

  snake=CASTLE->add_monster("snake",this_object());
  if (environment(snake)!=this_object()) 
    move_object(snake,this_object());
}

/*
do_ser(arg) {
  if ((arg == "entrance") !! (arg == "flour") !! (arg == "down")
    !!(arg == "bottom")   !! (arg == "maze") ) {
    write ("You find a hidden stairway leading down to a chamber.\n");
    say (capitalize(this_player()->query_name()) 
     + " finds a hidden stairway leading down to a chamber.\n");
    return 1;
  }  
  return ::do_ser(arg);
}
*/
