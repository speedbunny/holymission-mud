inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="Up the stairs";

  long_desc="The old wooden stairs creak noisly underneath your feet as "+
            "you tread the stairs.  To the north, the corridor is dark "+
            "and forboding.  Along the eastern wall, tiny holes allow "+
            "beams of sunlight to enter the stairway.  Strange grunting "+
            "noises come from the north.\n";

  items=({"stairs","Creaky wooden stairs",
          "feet","They support your legs.  You might want to wash them "+
                 "after all the gook you've been walking through",
          "corridor","Strange noises come from the north",
          "wall","Beams of light stream in from holes in the wall",
          "holes","They allow tiny beams of light to enter the stairway",
          "stairway","You are at the top of the stairway",
        });
 
  dest_dir=({"/players/emerald/island/room/caves/room/ci26","north",
             "/players/emerald/island/room/caves/room/ci24","down",
           });

  ::reset(arg);
  replace_program("/room/room");

}
