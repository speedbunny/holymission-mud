inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="A hidden passage";

  long_desc="Green fungus grows in profusion on the walls of this passage.  "+
            "The passage continues to the north and east.  Along its "+
            "length is foul standing water that reaches to your knees.  "+
            "This is not a terribly pleasant place to be.\n";

  items=({"water","The water is dirty and mildly acidic",
          "walls","Granite walls covered in fungus",
          "fungus","Its green and smells terrible",
          "passage","A hidden passage in the volcano",
          "knees","Your knees, whose else would they be..",
          "place","You've seen nicer places", 
        });

  dest_dir=({"/players/emerald/island/room/caves/room/c5","north",
             "/players/emerald/island/room/caves/room/c3","east",
           });

  ::reset(arg);
  replace_program("/room/room");

}
