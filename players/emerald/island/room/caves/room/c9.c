inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="A hidden passage";

  long_desc="A tiny beam of light penetrates the darkness of the cave from "+
            "the north.  To the east, the darkness and gloom continues, "+
            "leading deeper into the volcano.  Clinging green slime "+
            "decorates the walls, and kneedeep water covers the bottom of "+
            "the passage.\n";

  items=({"bottom","There is kneedeep water covering the bottom",
          "beam","A small beam of light to the north",
          "light","A slender beam of light to the north",
          "darkness","Thick, oppressive darkness",
          "cave","A hidden cave in the volcano",
          "volcano","An unhappy, active volcano, gurgling and rumbling",
          "slime","Thick and oozing green slime",
          "walls","Rough basalt walls",
          "water","Acidic, standing water",
          "passage","A hidden passage through the volcano",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/c8","east",        
             "/players/emerald/island/room/caves/room/c10","north",
           });

  clone_list=({
    1,3,"snake","obj/monster", ({
      "set_name","watersnake",
      "set_alt_name","snake",
      "set_level",14,
      "set_hp",300,
      "set_al",-10,
      "set_race","reptile",
      "set_short","A big green water snake",
      "set_long","You see a long green watersnake.  It looks harmless, "+
                 "but very strong.\n",
      "set_wc",18,
      "set_ac",6,
      "set_spell_mess2","The snake winds itself around your body!",
      "set_spell_mess1","The snake winds itself in panic!",
      "set_chance",60,
      "set_aggressive",1,
      "set_spell_dam",random(10),
    }),
  });

  ::reset(arg);
  replace_program("/room/room");

}
