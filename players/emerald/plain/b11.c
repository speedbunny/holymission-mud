inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The water's edge";
  long_desc="A large boulder sits half in, half out, out of water.  Weeds " +
            "have wrapped themselves around it, their tendrils trailing " +
            "in the water.  Mussels and other molluscs have attached " +
            "themselves to the rock, having found a good spot for the " +
            "water to wash over their valves.  Fresh droppings on top of " +
            "the rock show that birds also know that it is good for " +
            "molluscs.\n";

  dest_dir=({"/players/emerald/plain/b13","north",
             "/players/emerald/plain/b09","south",
             "/players/emerald/plain/b10","west",
             "/players/emerald/plain/b12","northwest",
             "/players/emerald/plain/b08","southwest",
           });

  items=({"boulder","It is quite slippery from the water",
          "water","Slightly foamy seawater",
          "weeds","Loose strands of kelp",
          "tendrils","Long stems of kelp",
          "mussels","Black-shelled, small molluscs",
          "molluscs","Soft-bodied marine animals encased in shells",
          "droppings","It is not advisable to touch them",
          "birds","They like to eat molluscs",
        });

  clone_list=({
    1,1,"mussel","obj/monster", ({
      "set_name","mussel",
      "set_race","mollusc",
      "set_ac",10,
      "set_short","A black mussel",
      "set_level",12,
      "set_long","A black mollusc attached to the rock.\n",
      "add_money",145,
    }),
  });

  ::reset();
  replace_program("/room/room");

}
