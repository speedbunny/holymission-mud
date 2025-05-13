#define TO this_object()
#define TP this_player()
#define TPN TP->query_name()
inherit "/room/room";

int move(string str) {
  if(!str)
    str=query_verb();
  switch(str) {
    case "up" :
      if(present("troll",TO) && !TP->query_immortal()) {
        write("The troll prevents you from going further in.\n");
        say(TPN+" tries to go up, but is stopped by the orc.\n");
        return 1;
      }
  }
  return ::move(str);
}

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="Next to a stone stairway";
  long_desc="You are standing at the foot of a small stone stairway.  "+
            "A growling sound and some light come from the top of the "+
            "stairway.  A small doorway stands at the top of the stairs, "+
            "and the passage continues to the south.\n";

  items=({"foot","The base of a small stone stairway",
          "stairway","A small stone stairway",
          "light","There is light in the doorway at the top of the small "+
                  "stone stairway",
          "top","The top of the small stone stairway",
          "doorway","A doorway at the top of the small stone stairway",
          "passage","It leads off to the south",
        });

  dest_dir=({"/players/emerald/island/room/caves/room/ci47","up",
             "/players/emerald/island/room/caves/room/ci45","south",
           });

  clone_list=({
    1,2,"troll","obj/monster",({
      "set_name","troll cave guard",
      "set_alt_name","guard",
      "set_short","troll cave guard",
      "set_race","troll",
      "set_long","The troll cave guard is enormously strong and towers about "+
                 "20 feet over your head.  The length of its body seems to "+
                 "be nothing but rippling muscles.\n",
      "set_gender",1,
      "set_aggressive",1,
      "set_level",30,
      "set_al",-1200,
      "add_money",500+random(50),
    }),
    -1,1,"club","obj/weapon",({
      "set_name","wooden club",
      "set_alias","club",
      "set_short","A spiked, wooden club",
      "set_long","A heavy, spiked wooden club.\n",
      "set_weight",2,
      "set_class",16,
      "set_type",1,
      "set_value",2000,
    }),
    2,1,"shaman","/players/emerald/island/room/caves/obj/shaman",0,
    -2,1,"mace","/players/emerald/island/room/caves/obj/mace",0,
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

}
