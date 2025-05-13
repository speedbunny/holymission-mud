#define TP  this_player()
#define TPN TP->query_name()
#define TPP TP->query_possessive()

inherit "/room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);

  short_desc="In a cavern";

  long_desc="You are in a big cave that leads into the volcano.  The walls "+
            "are made of shiny black stones and there are lighted torches "+
            "fixed to the walls.  To the north is a big iron pole leading "+
            "down into a deep hole.  Noises emenate from the hole.  On the "+
            "right side of the cave is a net fixed to two large sticks.  "+
            "The only way out would appear to be to the east.\n";

  items=({"cave","The cavern leads back to south",
          "stones","Big black stones lying on the ground",
          "torches","They are lighted and fixed to the walls",
          "net","A big net fixed on 2 sticks",
          "walls","The walls are dark and made of black stones",
          "sticks","You see two big wooden sticks fixed to the ground",
          "hole","A really big hole with some light coming from it",
          "pole","A big iron pole leading down.  It seems possible to "+
                 "slide on it",
          "volcano","You are just inside the volcano"
        });

  dest_dir=({"/players/emerald/island/room/g3","east"
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
    2,1,"sidril","obj/monster",({
      "set_name","sidril",
      "set_gender",1,
      "set_level",25,
      "set_hp",435,
      "set_race","gnome",
      "set_short","Sidril the Gnome",
      "add_money",random(1000),
    }),
    -1,1,"warbag","/players/emerald/island/obj/warbag",0,
    -1,1,"knife","/players/emerald/island/obj/knife",0,
    -2,1,"warbag","/players/emerald/island/obj/warbag",0,
    -1,1,"knife","/players/emerald/island/obj/knife",0,
  });

  ::reset(arg);

}

void init() {
  ::init();
  add_action("do_north","north");
  add_action("do_north","jump");
  add_action("do_slide","slide");
  add_action("do_climb","climb");
}

do_north() {

  write("\n\n################    YOU ARE FALLING   #################\n\n"+
        "\n\n################    YOU ARE FALLING   #################\n\n"+
        "\n\n################    YOU ARE FALLING   #################\n\n"+
        "\n\n################    YOU ARE FALLING   #################\n\n"+
        "OUCH! You fall on the hard ground!!! \n");
  TP->hit_player(random(TP->query_max_hp()/4) );
  TP->move_player(" down into the hole#players/emerald/island/room/g5");
  return 1;
}

do_slide(arg) {
  if(arg!="pole") {
    notify_fail("Slide what?\n");
    return 0;
  }
  write("\n\nZIIIIIIIIIIIIPPPPPPPPPPPP  You slide down the pole.\n\n");
  TP->move_player(" sliding down the pole#players/emerald/island/room/g5");
  return 1;
}

do_climb(arg) {
  if (!arg) {
  notify_fail("Climb what?\n");
  return 0;
  } 
  if (arg=="pole") {
    write("You climb up the pole and bump your head against the cavewall.\n"+
          "OUCH that hurts, you fall down again!\n");
    say(TPN+" tries to climb up the pole, but hurts "+TPP+" head badly on\n"+
        "the cavewall and falls down again.\n");
    TP->hit_player(1+random(4));
    return 1;
  }
}
