#include "/players/skeeve/area.h"

inherit "room/room";

reset(arg) {
  object sphinx;
  if (!arg) {
    set_light(1);
    short_desc = "Chamber";
    long_desc = "You have entered a fairly large room under the snakecave.\n"
               +"The floor is covered with sand while the walls are of cracked terra cotta.\n"
               +"There is a stairway leading up and a passage to the north.\n";
    smell="It smells like 1000 cats";
    items = ({
        "stairway", "It's a stairway leading down. There seem to be some strange marks"
                   +"scratched into it's steps",
        "walls",    "The walls are of cracked terra cotta",
        "floor",    "The floor is covered with sand"
      });
  }
  sphinx = CASTLE->add_monster("sphinx",this_object());
  if (environment(sphinx) != this_object()) 
    move_object(this_object());
  (MAZE+"chapel")->set_maze(25,this_object());
}

set_dir(newdir) {
   dest_dir =  newdir + ({ LAND+"cave","up" });
/*   update_actions(); */
}
  
move(dir) {
  object sphinx;
  if (!dir) dir=query_verb();
  if ( (dir=="north") && sphinx=present("sphinx"))
     return (sphinx->riddle(this_player())) ? ::move(dir) : 1;
  else
     return ::move(dir);
}
