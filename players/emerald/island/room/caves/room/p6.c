inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="On a prairie";

  long_desc="A dark forest borders the northern edge of the prairie.  "+
            "Mountain peaks ring the prairie, and a large cloud of yellow "+
            "vapour hangs in the sky.  Leafy shrubs and tall grass grow "+
            "thickly in the rich prairie soil.\n";


  items=({"forest","It is shrouded in darkness",
          "edge","A forbidding forest edges the prairie to the north",
          "prairie","A prairie on the plateau of the volcano",
          "peaks","The rounded peaks of volcanic mountains",
          "cloud","A cloud of yellow volcano gasses",
          "vapour","Yellow volcano gasses",
          "sky","The sky is almost clear up here",
          "shrubs","They show evidence of having been grazed upon",
          "grass","Thick prairie grass",
          "soil","Rich volcanic soil",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/p7","east",
             "/players/emerald/island/room/caves/room/p5","west",
             "/players/emerald/island/room/caves/room/p2","south",
             "/players/emerald/island/room/caves/room/f2","north",
           });

  clone_list=({
    1,3,"watchman","obj/monster",({
      "set_name","orc watchman",
      "set_alt_name","watchman",
      "set_short","An orc watchman",
      "set_race","orc",
      "set_long","An orc watchman looking around for victims.\n",
      "set_gender",1,
      "set_aggressive",1,
      "set_level",7,
      "set_whimpy",20,
      "set_al",-400,
      "add_money",150+random(50),
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
