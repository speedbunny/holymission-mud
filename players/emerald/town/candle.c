inherit "/room/room";

void reset (int arg) {

  if(arg) return;
  set_light(1);

  short_desc="The candle shop";

  long_desc="Blocks of tallow and wax are setting around the room.  Thread " +
            "for wicks and dyes are piled up neatly on a little table.  The " +
            "thrifty candle maker is busy cleaning up scraps and molds from " +
            "his last batch of candles to prepare for a new one.\n";
            "the building to the north.\n";

  dest_dir=({"/players/emerald/town/t12","south",
  });

  items=({"tallow","The ingredient for cheap candles",
          "wax","The ingredient for fine candles",
          "thread","It forms the wick of the candle",
          "table","The workspace of the candlemaker",
          "dyes","They give the colour to the candle",
          "scraps","They will be reused in another batch of candles",
          "molds","It shapes the hot wax into a candle",
  });

  clone_list=({
    1,1,"maker","obj/monster", ({
      "set_name","candle maker",
      "set_race","human",
      "set_alias","maker",
      "set_short","A candle maker",
      "set_long","A busy candle maker.  Don't disturb him!\n",
      "set_gender",1,
      "set_level",45,
      "set_ac",17,
      "set_wc",13,
    }),
    -1,1,"candle","obj/torch", ({
      "set_name","candle",
      "set_short","A twisted candle",
      "set_long","A well-crafted candle.  You could light it.\n",
      "set_smell","It has a pleasant fragrance.\n",
      "set_weight",1,
      "set_value",20,
    }),
  });
  ::reset(arg);
   replace_program("/room/room");

}
