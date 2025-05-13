inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="A hidden passage";
  long_desc="Foul water reaches up to your knees in this dark, hidden "+
            "passage in the volcano.  The walls are covered in green "+
            "fungus.  The dark passage reaches further north and south.\n";

  items=({"water","The water is dirty and mildly acidic",
          "walls","Granite walls",
          "knees","Your knobbly knees",
          "passage","A hidden passage in the volcano",
          "volcano","You are inside an active volcano.  Very brave (or "+
                     "stupid) of you", 
          "fungus","Green stinking fungus covers the walls",
        });
 
  dest_dir=({"/players/emerald/island/room/caves/room/c3","north",
             "/players/emerald/island/room/caves/room/c1","south",
           });

  ::reset(arg);
  replace_program("/room/room");

}
