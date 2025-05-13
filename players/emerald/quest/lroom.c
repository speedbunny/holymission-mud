inherit "room/room";

#define TO    this_object()
#define TP    this_player()
#define TPN   this_player()->query_name()
#define CLONE clone_object
#define MOVE  move_object
#define TELLR tell_room

static int is_cleaned = 0;

void set_descs() {

  if(is_cleaned) {
    short_desc="The alchemist shoppe";
    long_desc="You choke a little from all the smoke in here.  A dense " +
              "cloud of the black stuff is hanging around by the ceiling.  " +
              "Vials and beakers neatly arranged in shelves line the walls.  "+
              "There is a counter along one wall, and a somewhat charred " +
              "man standing behind it.  Sunlight enters through the clean " +
              "window, casting a golden beam into the room.  Far off in the " +
              "back corner, you notice a dark passageway.\n";
  }
  else {
    short_desc="The dim alchemist shoppe";
    long_desc=
      "You choke a little from all the smoke in here.  A dense cloud of the " +
      "black stuff is hanging around by the ceiling.  Vials and beakers " +
      "neatly arranged in shelves line the walls.  There is a counter along " +
      "one wall, and a somewhat charred man standing behind it.  It is also " +
      "quite dim in here.  The window is in desperate need of washing.  Far " +
      "off in the back corner, you notice a dark passageway.\n";
  }
}

void set_cleaned(int ans) {
  is_cleaned = ans;
}

void reset(int arg) {

  is_cleaned = 0;
  set_descs();

  if(arg) return;

  set_light(1);

  items=({"vials","They contain various colored liquids",
          "beakers","Glass containers for accurate measurement",
          "smoke","A by-product of combustion",
          "cloud","It looks unhealthy",
          "shelves","Plain wooden shelves holding neatly arranged chemicals",
          "walls","They are solid entities going from floor to ceiling",
          "light","A nice warm beam of sunlight",
          "sunlight","A nice warm beam of sunlight",
          "corner","A dim little back corner",
          "passageway","It looks like it leads into a back room",
          "window","@@window@@",
          "beam","A nice warm beam of sunlight",
          "man","Charles the Alchemist",
          "counter","It's rather sooty from the last explosion",
  });

  smell="Inhaling too deeply may cause permanent lung damage.\n";

  dest_dir=({"/players/emerald/town/t8","north",
  });

  clone_list=({
    1,1,"alchemist","obj/monster", ({
      "set_name","Charles the alchemist",
      "set_race","human",
      "set_short","The town alchemist",
      "set_long","This is Charles the Alchemist.  Explosives are his\n" +
                 "passion.  But now the king wants him to turn lead into\n" +
                 "gold, and he hasn't turned out to be very good at it.\n",
      "set_alt_name","charles",
      "set_gender",1,
      "set_alias","alchemist",
      "set_al",1000,
      "set_level",80,
      "set_wc",20,
      "set_ac",13,
      "add_money",10000,
    }),
  2,1,"leadbar","/players/emerald/quest/leadbar",0,
  });

  ::reset();
}
window() {
  if(!is_cleaned) {
    return "The window is smudged with soot and could stand a washing";
  }
  return "A window with nice clean glass, allowing the sunlight to enter " +
         "the room";
}

void init() {
  ::init();

  add_action("_enter","enter");
  add_action("_wash", "wash");
  add_action("_move", "move");
  add_action("_move", "place");
}

int _enter(string str) {

  if(!id(str)) {
    notify_fail("What do you wish to enter?\n");
    return 0;
  }
  if (str=="passageway") {
    write("You enter the dark passageway.\n");
    TP->move_player("into a passageway#players/emerald/quest/back");
    return 1;
  }

}
int _wash(string str) {
  object bucket;

  switch(str) {
    case "window with water" :
      bucket = present("bucket",this_player());
      if(!bucket || !bucket->query_has_water()) {
        write("Maybe a bucket of water would be useful in this endeavour?\n");
        return 1;
      }
      if(is_cleaned) {
        write("But the window is already clean.\n");
        return 1;
      }
      is_cleaned = 1;
      write("You wash the window and sunlight streams into the room.\n");
      say(TPN + " washes the window, letting light into the room.\n");
      set_descs();
      return 1;
    case "window with" :
    case "window" :
      if(!present("bucket",TP)) {
        write("You need a bucket of water to wash the window with.\n");
        return 1;
      }
      notify_fail("Wash window with what?\n");
      return 0;
    default :
      notify_fail("Wash what?\n");
      return 0;
  }
}

int _move(string str) {
  object item1, item2, item3, tray;

  tray = present("tray", TP);
  if(tray) {
    item1 = present("lead bar", tray);
    item2 = present("green liquid", tray);
    item3 = present("blue liquid", tray);
  }
  else {
    write("The tray must hold the items.\n");
    return 1;
  }

  switch(str) {
    case "tray into the light" :
    case "tray in light" :
    case "tray into light" :
    case "tray into square" :
    case "tray in sunlight" :
    case "tray into sunlight" :
      if(!is_cleaned) {
        write("There is no light in this room in which to place the tray.\n");
        return 1;
      }
      if(!tray) {
        write("You are hallucinating! There is no tray here.\n");
        return 1;
      }
      write("You place the tray into the sunlight.\n");
      say(TPN + " places a tray into the sunlight.\n");
      if(item1 && item2 && item3) {
        destruct(item1);
        destruct(item2);
        destruct(item3);
        item1 = CLONE("/players/emerald/quest/goldbar");
        MOVE(item1, tray);
        TELLR(TO, "POOF! The lead bar has miraculously turned to gold!\n");
      }
      else
        write("Shouldn't something have happened?\n");
      return 1;
    case "tray" :
      notify_fail("Move tray to where?\n");
      return 0;
    default :
      notify_fail("Move what?\n");
      return 0;
  }
}
