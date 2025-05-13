#define TP this_player()
inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="The gopher prairie";
  long_desc="You are in the gopher's prairie.  This place is FULL of holes " +
            "and, of course, gophers!  They are all over the place, making " +
            "more holes.  You are careful not to step in them and twist " +
            "an ankle.  To the east you see the beginnings of the woods.\n";

  dest_dir=({"players/emerald/good/light/light20","east",
             "players/emerald/good/light/light11","west",
           });

  items=({"holes","There are many holes, some are BIG",
          "woods","They are light and open looking",
          "hole","This is one BIG hole",
          "prairie","The gohpers like to live here",
          "gophers","A gopher in plurality",
          });

  clone_list=({
    1,1+random(4),"gopher","obj/monster",({
      "set_name","gopher",
      "set_alias","rodent",
      "set_level",5,
      "set_al",200,
      "set_short","A gopher",
      "set_ac",3,
      "set_wc",7,
    }),
  });

  ::reset();

}

void init()  {
  ::init();
  add_action("_enter","enter");
}

_enter(str) {

  switch(str) {
    case "hole" :
    case "holes" :
    case "gopher hole" :   
      write("That must be one BIG gopher that made this hole!\n");
      TP->move_player("down a hole#players/emerald/good/light/light27");
      return 1;
    default :
      notify_fail("Enter what?\n");
      return 0;
   }
}

