inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In a dark mixed forest";
  long_desc="You are crashing through a thick, tangled forest.  From "+
            "somewhere to the north, you can hear the bubbling of flowing "+
            "water.  Its sound is slightly muffled by the rubling volcano.  "+
            "The rustling leaves and snapping twigs add to the noise and "+
            "fill your heart with fear.\n";

  items=({"forest","A dark forest",
          "water","There is a water source nearby",
          "volcano","You are somewhere on an active volcano",
          "leaves","They flap in your face",
          "twigs","They crunch under feet which are not your own",
          "heart","You can't see your heart, it's under your skin",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/f4","east",
             "/players/emerald/island/room/caves/room/f2","west",
             "/players/emerald/island/room/caves/room/p7","south",
             "/players/emerald/island/room/caves/room/f7","north",
           });

  clone_list=({
    1,3,"hart","obj/monster",({
      "set_name","hart",
      "set_level",10,
      "set_size",4,
      "set_short","A big hart",
      "set_long","A hart.  It looks dangerous.\n",
      "set_race","ruminant",
      "set_spell_mess1","The hart hits you with its antler",
      "set_spell_mess2","The hart hurts you badly",
      "set_chance",20,
      "set_spell_dam",4,
    }),
    -1,1,"antler","obj/weapon",({
      "set_name","antler",
      "set_short","An antler",
      "set_long","The deadly antler of the hart.\n",
      "set_class",8,
      "set_weight",2,
      "set_value",400,
    }),
  });

  ::reset(arg);
  replace_program("/room/room");

}
