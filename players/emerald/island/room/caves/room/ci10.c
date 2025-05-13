inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="In the orc caves";
  long_desc="An ominous black altar lurks against the north wall of the "+
            "cave.  A terrible stench lingers in the air.  Blood is caked "+
            "on the walls and floor.  Bones are scattered throughout the "+
            "room.  Pieces of black, rotting flesh are heaped in corners.\n";

  items=({"altar","It is stained with blood",
          "wall","The wall is caked with old, black blood",
          "cave","This is obviously some sort of a temple",
          "air","The air is foul",
          "blood","There is lots of blood in here",
          "walls","The walls are plastered with blood",
          "floor","The floor is drowning under blood",
          "bones","They have teeth marks in them",
          "room","Some sort of evil temple",
          "pieces","Hunks of rotting, mangled flesh",
          "flesh","It looks rather rotten",
          "corners","The meeting of walls and floor",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci9","west",
             "/players/emerald/island/room/caves/room/ci11","north",
           });

  smell="The smell of slaughter.";

  clone_list=({
    1,3,"shaman","/players/emerald/island/room/caves/obj/shaman",0,
    -1,1,"mace","/players/emerald/island/room/caves/obj/mace",0,
    -1,1,"robe","obj/armour",({
      "set_name","black robe",
      "set_alias","robe",
      "set_short","A black robe",
      "set_long","A long, black robe.\n",
      "set_weight",1,
      "set_ac",1,
      "set_type","cloak",
      "set_value",75,
    }),
    2,2,"warrior","obj/monster",({
      "set_name","orc warrior",
      "set_alt_name","warrior",
      "set_short","orc warrior",
      "set_race","orc",
      "set_long","A strong looking orc warrior.\n",
      "set_gender",1,
      "set_aggressive",1,
      "set_level",25,
      "set_al",-800,
      "add_money",300+random(50),
      "set_number_of_arms",2,
    }),
    -2,1,"axe","obj/weapon",({
      "set_name","war axe",
      "set_alias","axe",
      "set_short","A war axe",
      "set_long","A big iron axe, perfect for chopping off heads.\n",
      "set_weight",2,
      "set_class",16,
      "set_value",450,
    }),
    -2,1,"jacket","obj/armour",({
      "set_name","dirty jacket",
      "set_alias","jacket",
      "set_short","A dirty leather jacket",
      "set_long","A dirty strong leather jacket.\n",
      "set_weight",2,
      "set_ac",3,
      "set_type","armour",
      "set_value",150,
    }),
    -2,1,"helmet","obj/armour",({
      "set_name","leather helmet",
      "set_short","A leather helmet",
      "set_alias","helmet",
      "set_long","A strong leather helmet.\n",
      "set_weight",1,
      "set_ac",1,
      "set_type","helmet",
      "set_value",120,
    }),
    -2,1,"boots","/players/emerald/island/room/caves/obj/boots",0,
  });

  ::reset(arg);
  replace_program("/room/room");

}
