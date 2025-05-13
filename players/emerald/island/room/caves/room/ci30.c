inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);
  short_desc="In the orc library";

  long_desc="You have entered the orc library.  The walls are covered in "+
            "strange writing.  Scrolls and books lie strewn about the "+
            "room, as if the shamans that were reading them left in a "+
            "hurry.  A dark corridor leads to the east.\n";

  dest_dir=({"/players/emerald/island/room/caves/room/ci29","east",
           });

  items=({"library","The orc library",
          "walls","Strange inscriptions are carved into the walls",
          "writing","You can't read the language written on the walls",
          "scrolls","Old, crackling scrolls made of human flesh",
          "books","Their leather bindings were once human skin",
          "shamans","The shamans are the only orcs who can read",
          "room","The orc library",
          "corridor","It leads off to the east",
        });

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
    2,1,"chief","/players/emerald/island/room/caves/obj/cshaman",0,
    -2,1,"mace","/players/emerald/island/room/caves/obj/mace",0,
    -2,1,"bracelet","/players/whisky/obj/ruby_bracelet",0,
    -2,1,"robe","obj/armour",({
      "set_name","black robe",
      "set_alias","robe",
      "set_short","A black robe",
      "set_long","A long, black robe.\n",
      "set_weight",1,
      "set_ac",1,
      "set_type","cloak",
      "set_value",75,
    }),
  });

  ::reset(arg);
  replace_program("/room/room");

}
