inherit "/room/room";

reset(arg) {

  set_light(1);

  short_desc="The main street in town";

  long_desc="You are approaching the castle that rules over the land.  " +
            "It stands to the north of you, a monument of labour in " +
            "stone, mortar, and glass.  To either side of you are side " +
            "streets leading to other sections of the town.\n";

  dest_dir=({"/players/emerald/town/t21","north",
             "/players/emerald/town/t15","east",
             "/players/emerald/town/t18","west",
             "/players/emerald/town/t13","south",
           });

  items=({"streets","Side streets that look heavily travelled",
          "mortar","It holds the building stone in place",
          "glass","A form of silicate",
          "stone","A hard substance usually made of rock",
          "castle","It dominates the view with its imposing form",
  });

  ::reset(arg);
   replace_program("/room/room");

}
