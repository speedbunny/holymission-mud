#define TP this_player()
inherit "/room/room";

void reset(int arg) {
  if(arg) return;

  set_light(1);

  short_desc="Outside the dark tower";
  long_desc="As you come to the gates of the huge dark tower, you realise " +
            "that it is in fact even taller than you had thought.  It " +
            "quite dwarfs the huge trees of the the dark forest that is " +
            "all around you.  On top of the tower, you see a strange " +
            "fluctuating glowing, which is contrasted against the sky, " +
            "which is black as night at all times here - day never enters " +
            "this part of the realm.\n";

  dest_dir=({"/players/emerald/forest/tower_g","east",
             "/players/emerald/forest/f7-0","west",
            });

  items=({"gates","They are wide open",
          "tower","The gates of the huge dark tower are wide open",
          "trees","The huge trees of the dark forest are dwarfed by the tower",
          "forest","The huge trees of the dark forest are dwarfed by the tower",
          "glowing","It must be some kind of magical beacon, sometimes it " +
                    "is red, sometimes yellow",
          "sky", "It is black, and there no stars" 
        });

  clone_list=({
    1,2,"guard","/players/emerald/forest/guard",0,
    -1,1,"sword","obj/weapon", ({
      "set_name","bastardsword",
      "set_alias","sword",
      "set_short","A huge bastardsword",
      "set_long","This is a heavy, but very effective weapon.\n",
      "set_class",20,
      "set_value",3000,
    }),
    -1,1,"platemail","obj/armour", ({
      "set_name","platinum platemail",
      "set_alias","platemail",
      "set_ac",4,
      "set_weight",3,
      "set_short","Platinum platemail",
      "set_long","This platinum platemail is very light, but provides " +
                 "excellent protection.\n",
      "set_value",700,
    }),
    -1,1,"helmet","obj/armour",({
      "set_name","metal helmet",
      "set_type","helmet",
      "set_ac",1,
      "set_weight",1,
      "set_short","Metal helmet",
      "set_long","A light but well crafted metal helmet.\n",
      "set_value",100,
    }),
    -1,1,"boots","obj/armour", ({
      "set_name","combat boots",
      "set_alias","boots",
      "set_type","boot",
      "set_ac",1,
      "set_weight",1,
      "set_short","Combat boots",
      "set_long","A nifty pair of combat boots.\n",
      "set_value",250,
    }),
    -1,1,"shield","obj/armour",({
      "set_name","large shield",
      "set_type","shield",
      "set_ac",1,
      "st_alias","shield",
      "set_weight",2,
      "set_short","Large shield",
      "set_long","A large heavy shield.\n",
      "set_value",400,
    }),
  });

  ::reset();

}

int move(string str) {
  if(query_verb()=="east") {
    if(present("tower guard")) {
      tell_room(this_object(), "Tower Guard says: Go away.  " +
                               "We don't like your type here.\n");
    }
    else
      TP->move_player("into the tower#players/emerald/forest/tower_g");
    return 1;
  }
  return ::move(str);
}
