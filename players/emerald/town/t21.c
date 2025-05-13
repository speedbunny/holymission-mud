inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="The main street in town";

  long_desc="It is much quieter here.  The crowds are far behind you and " +
            "the castle in front of you is silent.  The lowered drawbridge " +
            "lies to the north, but you can't make out a moat.  Battle " +
            "standards are flying from the top of the towers and a few " +
            "soldiers can be seen patrolling the battlements.\n";

  dest_dir=({"/players/emerald/town/dbridge","north",
             "/players/emerald/town/t14","south",
           });

  items=({"drawbridge","A wooden drawbridge.  It is lowered",
          "standards","They are in green and blue",
          "soldiers","They look tiny from this distance",
          "castle","It is built of stone",
          "towers","Tall stone appendages on the sides of the castle",
          "battlements","The soldiers patrol from there",
  });

  ::reset(arg);
   replace_program("/room/room");

}
