inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="Misty cloud world";
  long_desc="Swirling mists loom on all sides.  A constant pale grey light "+
            "fills the area.  A few shapes materialize from the mist, "+
            "forming themselves into clouds.  Narrow pathways emerge as the "+
            "clouds settle.  A tension fill the air, as if the elements "+
            "rule here, subjecting the clouds to their whims.\n";

  dest_dir=({"/players/emerald/good/evil/enterhall","south",
             "/players/emerald/good/neutral/n2","north",
           });

  items=({"mists","The whole world seems to be made of insubstantial mists",
          "sides","Mist, mist, and more mist",
          "light","Pale grey light provides adequate illumination",
          "area","A colourless world of clouds",
          "shapes","The shapes form themselves into huge grey clouds",
          "mist","You feel like you will turn to mist if you stay here",
          "clouds","Large mounds of grey clouds",
          "pathways","A pathway leads north and south",
          "air","The air seems tight with anticipation",
          "elements","Air appears to be the ruling element here",
        });

  ::reset(arg);
  replace_program("/room/room");

}
