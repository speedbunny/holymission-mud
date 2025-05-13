inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="A grassy plain";
  long_desc="The plain is quite narrow here.  The Ilkin Forest extends " +
            "along the southeastern border, forming an impenetrable " +
            "barrier to the grassland.  A range of high grey mountains " +
            "blocks the plain's extension to the northwest.  In between " +
            "lies the rippling golden beauty of ripening grass, punctuated "+
            "here and there with colourful flowers.\n";

  dest_dir=({"/players/emerald/plain/p29","north",
             "/players/emerald/plain/p22","east",
             "/players/emerald/plain/p20","west",
             "/players/emerald/plain/p12","south",
             "/players/emerald/plain/p30","northeast",
             "/players/emerald/plain/p11","southwest",
           });

  items=({"plain","A flat area of grassland",
          "forest","The trees loom tall and dark, casting an aura of evil",
          "border","The meeting of plain and forest",
          "barrier","The tree branches grow thickly together",
          "grassland","A flat area of grass",
          "range","A line of silent grey mountains",
          "mountains","They cannot be climbed",
          "grass","The tall stalks ripen in the sunlight",
          "flowers","They provide splashes of colour to the golden monotony",
        });

  clone_list=({
    1,1,"falcon","obj/monster", ({
      "set_name","falcon",
      "set_race","raptor",
      "set_short","A majestic falcon",
      "set_long","A falcon with long talons and sharp eyes.\n",
      "set_aggressive",1,
      "set_level",16,
      "set_wc",10,
      "add_money",200,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
