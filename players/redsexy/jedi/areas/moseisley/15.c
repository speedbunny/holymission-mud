inherit "room/room";

void reset(int arg) {

  if(arg) return;

  set_light(1);
  short_desc="Clothesmaker Clive's.";
  long_desc="You have entered the hut of clothesmaker Clive, where he produces garments "+
            "for creatures of many different races.  There are many types of fine cloth "+
            "lying around the floor, and numerous needles and threads on the table, but the "+
            "hut is deserted at this moment in time... perhaps he is on his lunchbreak?\n\n";

  dest_dir=({"/players/redsexy/jedi/areas/moseisley/16","south",
           });
  
  items=({"clive","He seems to be on a lunch break",
          "garments","there are no completed garments here, just cloth of the finest quality",
          "cloth","Velvets and silks of the finest quality",
          "needles","Needles used for sewing are dotted around Clives table",
          "threads","Threads of varying density are threaded through the needles",
          "table", "A large table, where Clive creates his designs",
          "floor","The floor is spread with sawdust",
         });

  ::reset();
   replace_program("/room/room");

}


