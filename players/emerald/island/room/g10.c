#define TP  this_player()
#define TPN TP->query_name()
#define TPP TP->query_possessive()

inherit "/room/room";

void reset(int arg) {


  if(arg) return;

  set_light(1);

  short_desc="In a cavern";

  long_desc="You are in a big cave in the volcano.  The walls are made of "+
            "black stones and there are lighted torches fixed to the "+
            "walls.  You see a lot of little footsteps leading northwest "+
            "and southeast.  The air is really hot down here.  There is "+
            "a lake to the east and a little sign in front of the lake.\n";

  items=({"cave","The cave leads further to the northwest and southeast",
          "stones","Big black stones lying on the ground",
          "torches","They are lighted and fixed to the walls",
          "walls","The walls are dark and made of black stones",
          "footsteps","You see a lot of tiny gnomish footsteps",
          "volcano","You are just inside the volcano",
          "sign","Something is written on it",
          "lake","You see a little dark lake with hot steam coming from it"
        });

  dest_dir=({"/players/emerald/island/room/g13","northwest",
             "/players/emerald/island/room/g9","southeast"
           });


  clone_list=({
    1,1,"grndrz","obj/monster",({
      "set_name","grndrz",
      "set_gender",1,
      "set_level",45,
      "set_hp",745,
      "set_race","gnome",
      "set_short","Grndrz the Gnome",
      "add_money",random(3000),
    }),
    2,1,"xentran","obj/monster",({
      "set_name","xentran",
      "set_gender",1,
      "set_level",12,
      "set_hp",230,
      "set_race","gnome",
      "set_short","Xentran the Gnome",
      "add_money",random(400),
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
    -1,1,"warbag","/players/emerald/island/obj/warbag",0,
    -1,1,"knife","/players/emerald/island/obj/knife",0,
    -2,1,"warbag","/players/emerald/island/obj/warbag",0,
    -2,1,"knife","/players/emerald/island/obj/knife",0,
    -3,1,"warbag","/players/emerald/island/obj/warbag",0,
    -3,1,"knife","/players/emerald/island/obj/knife",0,
  });

  ::reset(arg);

}
 
void init() {
  ::init();
  add_action("do_enter","enter");
  add_action("do_read","read");
}

do_read(arg) {
  if (arg!="sign") {
    notify_fail("Read what?\n");
    return 0;
  }
  write("You read:\n\nGrnzgrrg (GiantsAreNotAllowedInOurTown) \n\n");
  say(TPN+" reads the sign.\n");
  return 1;
}

do_enter(arg) {
   if(arg!="lake") {
     notify_fail("Enter what ?\n");
     return 0;
   } 
   write("You enter the hot lake.  OUCH!  The water is HOT!  You jump back "+
         "on the path!\n");
  say(TPN+" screams in pain!\n");
   TP->hit_player(1+random(4));
   return 1;
}
