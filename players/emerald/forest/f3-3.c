inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="Deep forest";
  long_desc="You are in a deep forest.  Dark gnarled trees loom all around " +
            "you, and the eerie silence all about you makes you feel " +
            "somewhat afraid.  You cannot hear even one single bird singing "+
            "here.  There seems to be some great evil in this dark, "+
            "mysterious forest.  No trace of a path can be found, although " +
            "animal tracks lead off in various directions.\n";

  dest_dir=({"/players/emerald/forest/f4-3","north",
             "/players/emerald/forest/f3-4","west",
           });


  items=({"tree", "Any particular tree?",
          "trees","They are very dark and gnarled, maybe centuries old",
          "path","There isn't any",
          "forest","Thick, dense, with a pervasive sense of great evil",
          "bird", "There isn't any",
          "tracks", "They are well trodden, marked out by years of usage",
        });


  ::reset(arg);
  replace_program("/room/room");
}
