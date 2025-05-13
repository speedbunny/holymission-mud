inherit "room/room";

reset(arg) {

  set_light(1);

  short_desc="The office";
  long_desc="This is the office of the Druid Lakmir's manager.  This room " +
            "is devoid of any aesthetic warmth or beauty. It is purely " +
            "functional, with no concern for the trivialities of interior " +
            "design.  The floor is inlaid stone while the walls are of " +
            "cracked terra cotta.\n";

  dest_dir=({"/players/emerald/lakmir/anteroom","east",
          });

  items=({"office","An office",
          "room","An office",
          "floor","A stone floor",
          "walls","They are of cracked terra cotta",
        });

  clone_list=({
    1,1,"manager","/players/emerald/lakmir/manager",0,
  });

  ::reset();
  replace_program("/room/room");

}
