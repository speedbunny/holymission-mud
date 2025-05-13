inherit "/room/room";

int boulder_moved;

int move(string str) {
  if(!str)
    str=query_verb();
  switch(str) {
    case "west" :
      if(!boulder_moved) {
        write("What ?\n");
        return 1;
     }
  }
  return ::move(str);
}
void reset(int arg) {
  if(arg) return;

  boulder_moved=0;

  set_light(0);
  short_desc="The chieftains chamber";
  long_desc="A fire flickers against the north wall of the chamber, its "+
            "smoke filtering away through crevices in the walls.  Some "+
            "heavy pieces of cloth are heaped into haphazard beds on the "+
            "floor.  The scent of unwashed orc is heavy the "+
            "chamber.  @@extralong@@\n";

  items=({"boulder","A big, heavy boulder.  It looks like it could moved",
          "fire","The flames glow a bright orange-red",
          "wall","Thick stone walls",
          "chamber","A sleeping chamber in the orc caves",
          "smoke","It eventually finds its way out through crevices in the "+
                  "walls",
          "crevices","Their edges are stained with smoke",
          "walls","Thick stone walls",
          "opening","There is a boulder in front of it",
          "pieces","Thick pieces of dirty cloth",
          "cloth","It has been arranged into a sort of bed",
          "beds","Dirty cloth formed into crude beds",
          "passage","It leads off to the west",
          "floor","The floor is strewn with pieces of cloth",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci8","south",
           });

  hidden_dir=({"/players/emerald/island/room/caves/room/ci13","west",});

  smell="The reek of unwashed orc clings to your nostrils.";

  clone_list=({
    1,3,"warrior","obj/monster",({
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
    -1,1,"axe","obj/weapon",({
      "set_name","war axe",
      "set_alias","axe",
      "set_short","A war axe",
      "set_long","A big iron axe, perfect for chopping off heads.\n",
      "set_weight",2,
      "set_class",16,
      "set_value",450,
    }),
    -1,1,"jacket","obj/armour",({
      "set_name","dirty jacket",
      "set_alias","jacket",
      "set_short","A dirty leather jacket",
      "set_long","A dirty strong leather jacket.\n",
      "set_weight",2,
      "set_ac",3,
      "set_type","armour",
      "set_value",150,
    }),
    -1,1,"helmet","obj/armour",({
      "set_name","leather helmet",
      "set_short","A leather helmet",
      "set_alias","helmet",
      "set_long","A strong leather helmet.\n",
      "set_weight",1,
      "set_ac",1,
      "set_type","helmet",
      "set_value",120,
    }),
    -1,1,"boots","/players/emerald/island/room/caves/obj/boots",0,
    2,1,"chieftain","obj/monster",({
      "set_name","orc chieftain",
      "set_alt_name","chieftain",
      "set_short","An orc chieftain",
      "set_race","orc",
      "set_long","A strong looking orc warrior.\n",
      "set_gender",1,
      "set_aggressive",1,
      "set_level",35,
      "set_al",-800,
      "add_money",2000+random(50),
      "set_number_of_arms",3,
    }),
    -2,1,"mace","/players/emerald/island/room/caves/obj/mace",0,
    -2,1,"boots","/players/emerald/island/room/caves/obj/boots",0,
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
  });

  ::reset(arg);
}
extralong() {
  if(!boulder_moved) return "A large boulder barely covers an opening in "+
                            "the west wall.";
  return "There is a passage leading west here";
}

void init() {
  ::init();
  add_action("do_push","push");
  add_action("do_push","move");
}

int do_push(string str) {
  if(str!="boulder") {
    notify_fail("Move what?\n");
    return 0;
  }
  if(boulder_moved==1) {
    write("Ughh, nothing happens, the boulder was already moved.\n");
    return 1;
  }
  if(str=="boulder") {
  write("You push the boulder and reveal a hidden exit to the west.\n");
  say(this_player()->query_name()+" pushes the boulder aside.\n");
  boulder_moved=1;
  return 1;
  }
}
