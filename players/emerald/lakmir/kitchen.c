inherit "room/room";

reset(arg) {

  set_light(1);

  short_desc="Lakmir's kitchen";
  long_desc="This is the kitchen of the Druid Lakmir.  Sunlight streams " +
            "in through an open window, highlighting the stove which sits " +
            "along one wall.  Opposite the stove stands a cupboard.  A " +
            "large sink is located underneath the window.\n";

  dest_dir=({"/players/emerald/lakmir/anteroom","west",
           });

  items=({"kitchen","A room for preparing food",
          "sunlight","It looks nice and warm",
          "window","It is open",
          "sink","A large granite sink",
        });


  clone_list=({
    1,1,"stove","/players/emerald/lakmir/stove",0,
    2,1,"cupboard","/players/emerald/lakmir/cupboard",0,
    3,1,"kettle","/players/emerald/lakmir/kettle",0,
    4,1,"list","/players/emerald/lakmir/list",0,
  });

  ::reset();
  replace_program("/room/room");

}
