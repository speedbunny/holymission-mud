inherit "/room/room";

void reset(int arg){
  if(arg) return;

  set_light(1);
  short_desc="In a cavern";

  long_desc="This is a really bizarre cavern in the volcano.  The ceiling "+
            "is vaulted far above you.  A few dark openings can be seen "+
            "at intervals on the walls.  Gnomes are flying through the "+
            "air, some landing in the openings, and others crashing into "+
            "nets which magically appear to catch the gnomes which don't "+
            "quite land in the openings.  And in the event that the nets "+
            "fail, a large sponge appears to clean up the gnomish pancakes.\n";

  items=({"cavern","A really huge cavern inside the volcano",
          "ceiling","The ceiling is almost lost in the shadows",
          "openings","Three openings, set at intervals in the walls",
          "walls","Dark, basalt walls of the volcano",
          "volcano","You are inside an active volcano",
          "gnomes","Flying gnomes, but last you knew, gnomes didn't have wings",
          "nets","Some sort of safety nets to catch misfired gnomes",
          "sponge","An enormous sponge to clean up the gory mess",
          "pancakes","What happens to a gnome speeding earthward",
        });

  dest_dir=({"/players/emerald/island/room/g26","west",
           });

  clone_list=({
    1,1,"catapult","/players/emerald/island/obj/catapult",0,
    2,1,"gnome","/players/emerald/island/obj/gnome",0,
    -2,1,"knife","/players/emerald/island/obj/knife",0,
    -2,1,"warbag","/players/emerald/island/obj/warbag",0,
  });

  ::reset(arg);
  replace_program("/room/room");

}
