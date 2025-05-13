inherit "/room/room";
void reset(int arg) {
  if(arg) return;
  set_light(0);
  short_desc="In the secret orc chambers";

  long_desc="You are wandering through the dark and dangerous secret orc "+
            "caves.  The dark passage leads further to the north and south.  "+
            "Far off to the north you can see light shining into the "+
            "hallway.  It seems as if there are dark shadows standing in "+
            "the light.  Loud snoring comes from the west.\n";

  items=({"caves","The cruddy secret orc caves",
          "passage","It leads north and south",
          "light","There is light way off to the north",
          "hallway","A dark hallway in the orc caves",
          "shadows","A few silhouettes outlined in the light",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci44","west",
             "/players/emerald/island/room/caves/room/ci45","north",
             "/players/emerald/island/room/caves/room/ci42","south",
           });

  clone_list=({
    1,1,"boy","obj/monster",({
      "set_name","orc boy",
      "set_alt_name","boy",
      "set_short","A busy orc boy",
      "set_race","orc",
      "set_long","An orc kitchen helper.\n",
      "set_gender",1,
      "set_aggressive",1,
      "set_level",5,
      "set_al",-100,
      "add_money",80+random(50),
    }),
    -1,1,"dagger","obj/weapon",({
      "set_name","stone dagger",
      "set_alias","dagger",
      "set_long","A small dagger made of obsidian.\n",
      "set_weight",1,
      "set_short","An obsidian dagger",
      "set_class",8,
      "set_type",1,
      "set_value",60,
    }),
  });

  ::reset(arg);
  replace_program("/room/room");

}
