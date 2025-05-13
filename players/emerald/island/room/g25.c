inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);

  short_desc="In a cavern";
  long_desc="You are in a big cavern inside the volcano.  The walls are "+
            "made of black stone and lighted torches hang from the walls.  "+
            "Tiny footprints cover the ground.  From the east you hear a "+
            "really odd noise.  A large crack is in the wall to the north.\n";

  items=({"cavern","A large cavern inside the volcano",
          "volcano","A rumbling, gurgling, active volcano",
          "walls","Black basalt walls",
          "stone","Thick, rough, basalt",
          "torches","They are fixed to the walls",
          "footprints","Lots of little gnomish footprints",
          "ground","It is covered in footprints",
          "crack","It is big enough to enter",
          "wall","There is a large crack in the north wall",
        });

  dest_dir=({"/players/emerald/island/room/g21","southwest",
             "/players/emerald/island/room/g26","east",
           });

  clone_list=({
    1,1,"cinze","obj/monster",({
      "set_name","cinze",
      "set_gender",2,
      "set_level",18,
      "set_hp",340,
      "set_race","gnome",
      "set_short","Cinze the Gnome",
      "add_money",random(800),
    }),
    2,1,"grndrz","obj/monster",({
      "set_name","grndrz",
      "set_gender",1,
      "set_level",45,
      "set_hp",745,
      "set_race","gnome",
      "set_short","Grndrz the Gnome",
      "add_money",random(3000),
    }),
    3,1,"nadja","obj/monster",({
      "set_name","nadja",
      "set_gender",2,
      "set_level",16,
      "set_hp",315,
      "set_race","gnome",
      "set_short","Nadja the Gnome",
      "add_money",random(550),
    }),
    -1,1,"knife","/players/emerald/island/obj/knife",0,
    -1,1,"warbag","/players/emerald/island/obj/warbag",0,
    -2,1,"knife","/players/emerald/island/obj/knife",0,
    -2,1,"warbag","/players/emerald/island/obj/warbag",0,
    -3,1,"knife","/players/emerald/island/obj/knife",0,
    -3,1,"warbag","/players/emerald/island/obj/warbag",0,
  });

  ::reset(arg);
 
}

void init() {
  ::init();
  add_action("do_enter","enter");
}

int do_enter(string arg) {
  if(arg!="crack") {
    notify_fail("Enter what?\n");
    return 0;
  }
  write("You squeeze yourself through the crack!\n");
  this_player()->move_player(
    "squeezing through a crack#players/emerald/island/room/caves/room/c1");
  return 1;
}
