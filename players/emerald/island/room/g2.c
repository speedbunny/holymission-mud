#define TP  this_player()
#define TPN TP->query_name()
#define TPP TP->query_possessive()

inherit "/room/room";


void reset (int arg) {

  if(arg) return;

  set_light(1);

  short_desc="In a cavern";

  long_desc="You are in a big cave that leads into the volcano.  The walls "+
            "are made of shiny black stone, and there are lighted torches "+
            "fixed to the walls.  To the north, there is a big iron pole "+
            "which leads down into a big hole.  Noises emenate from the "+
            "hole.  On the right side of the cave there is a net fixed on "+
            "two large sticks. The only way out would appear to be to the "+
            "south.\n";

  items=({"cave","The cavern leads back to south",
          "stone","There are a lot of stones lying around",
          "torches","They are lighted and fixed to the walls",
          "net","A big net fixed on 2 sticks",
          "walls","The walls are dark and made of black stones",
          "ground","The ground is full of dark stones",
          "sticks","You see two big wooden sticks fixed to the ground",
          "hole","A really big hole, there is some light coming from it",
          "pole","A big iron pole leading down.  It seems possible to slide "+
                 "on it",
          "volcano","You are just inside the volcano"
        });

  dest_dir=({"/players/emerald/island/room/g1","south"
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
    2,1,"rnkzrz","obj/monster",({
      "set_name","rnkzrz",
      "set_gender",1,
      "set_level",12,
      "set_short","Rnkzrz the Gnome",
      "set_hp",230,
      "set_race","gnome",
      "add_money",random(400),
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
  add_action("do_north","north");
  add_action("do_north","n");
  add_action("do_north","jump");
  add_action("do_slide","slide");
  add_action("do_climb","climb");
}
do_north() {

  write("\n\n################    YOU ARE FALLING   #################\n\n"+
        "\n\n################    YOU ARE FALLING   #################\n\n"+
        "\n\n################    YOU ARE FALLING   #################\n\n"+
        "\n\n################    YOU ARE FALLING   #################\n\n"+
        "OUCH!! You fall on the hard ground!!!!!\n");
  TP->hit_player( random(TP->query_max_hp()/4) );
  TP->move_player("into the hole#players/emerald/island/room/g3");
  return ( 1 );
}

do_slide (arg) {
  if(arg!="pole") {
    notify_fail("Slide what?\n");
    return 0;
  } 
  write("ZIIIIIIIIIIIIPPPPPPPPPPPP  You slide down the pole.\n");
  TP->move_player(" sliding down the pole#players/emerald/island/room/g3");
  return 1;
}

do_climb(arg) {

  if (!arg) {
  notify_fail("Climb what?\n");
  return 0;
  } 
  if(arg=="pole") {
    write("You climb up the pole and bump your head against the cavewall.\n"+
          "OUCH! That hurts! You fall down again!\n");
    say(TPN+" tries to climb up the pole, but hurts "+TPP+" head badly on\n"+
        "the cavewall and falls down again.\n");
    TP->hit_player(1+random(4));
    return 1;
  } 
}
