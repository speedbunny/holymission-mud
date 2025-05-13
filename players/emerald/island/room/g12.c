#define TP this_player()
#define TPN TP->query_name()

inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="In a cavern";
  long_desc="You are in a big cave in the volcano.  The walls are made of "+
            "black stones and there are lighted torches fixed to the "+
            "walls.  You see a lot of little footprints leading northeast "+
            "and southwest.  The air is really hot here.  There is a lake "+
            "to the east and a little sign in front of the lake.\n";

  items=({"cave","The cave leads further to the northwest and southeast",
          "stones","Big black stones compose the walls",
          "torches","They are lighted and fixed to the walls",
          "walls","The walls are dark and made of black stones",
          "path","The path leads further to the northeast and southwest",
          "footprints","You see a lot of tiny gnomish footprints",
          "volcano","You are just inside the volcano",
          "sign","Something is written on it",
          "lake","You see a little dark lake with hot steam coming from it"
        });

  dest_dir=({"/players/emerald/island/room/g15","northeast",
             "/players/emerald/island/room/g9","southwest"
           });

  clone_list=({
    1,1,"nizra","obj/monster",({
      "set_name","nizra",
      "set_gender",2,
      "set_level",15,
      "set_hp",295,
      "set_race","gnome",
      "set_short","Nizra the Gnome",
      "add_money",random(500),
    }),
    2,1,"cinze","obj/monster",({
      "set_name","cinze",
      "set_gender",2,
      "set_level",18,
      "set_hp",340,
      "set_race","gnome",
      "set_short","Cinze the Gnome",
      "add_money",random(800),
    }),
    -1,1,"warbag","/players/emerald/island/obj/warbag",0,
    -1,1,"knife","/players/emerald/island/obj/knife",0,
    -2,1,"warbag","/players/emerald/island/obj/warbag",0,
    -2,1,"knife","/players/emerald/island/obj/knife",0,
  });

  ::reset(arg);

}

void init() {
  ::init();
  add_action("do_read","read");
}

do_read(arg) {

  if(arg!="sign") {
    notify_fail("Read what?\n");
    return 0;
  }
  write("You read:\n\nGrnzgrrg (GiantsAreNotAllowedInOurTown) \n\n");
  say(TPN+" reads the sign.\n");
  return 1;
}
