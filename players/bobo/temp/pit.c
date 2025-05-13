#define TO this_object()
#define TP this_player()
#define TPN this_player()->query_name()
inherit "/room/room";

int climbing;

void reset(int arg) {
  if(arg) return;

  set_light(0);
  short_desc="Bottom of a pit";
  long_desc="This is the bottom of a deep pit.  The walls and floor are "+
            "cut from the living rock of the mountain.  Ancient armour "+
            "and weapons litter the floor of the pit.  They appear to have "+
            "been cast aside.\n";

  items=({"walls","It looks like you might be able to climb up the "+ 
                  "wall of the pit if you are light and strong",              
          "wall","It looks like you might be able to climb up the "+ 
                 "wall of the pit if you are light and strong"
          "bottom","You have reached the bottom in a most painful manner",
          "pit","Yup, this is a pit allright",
          "floor","Old weapons and armour linger on the floor",
          "armour","Some heavy platemail and chainmail",
          "weapons","Heavy broadswords and maces",
       });

  smell="The smell of death lingers here.";

  ::reset(arg);

}

void init() {
  ::init();
  add_action("_climb", "climb");
}

int _climb(string str) {
  if (str == "wall" || str == "walls") {
    if (climbing) {
      write("Someone else is blocking the way.\n");
      return 1;
    }
    if (TP->query_guild() == 1) {
      write("You easily climb up the side of the pit.\n");
      say(TPN+" climbs up the side of the pit.\n");
      this_player()->move_player("up#players/emerald/perilous/frost/cave13");
      return 1;
    }
    if (TP->query_ghost()) {
      write("You drift up the side of the pit.\n");
      this_player()->move_player("up#players/emerald/perilous/frost/cave13");
      return 1;
    }
    if (TP->query_weight() > (3 + this_player()->query_level()/4)) {
      write("You are carrying too much stuff!\n");
      say(TPN+" tries to climb the wall, but slips back down.\n");
      return 1;
    }
    write("You begin to climb up the wall of the pit.\n");
    say(TPN+" begins to climb the wall of the pit.\n");
    climbing = 1;
    call_out("climb_it", 3);
    return 1;
  }
  if(!str)  {
    notify_fail("Climb what?\n");
    return 0;
  }
}

int climb_it() {
  climbing = 0;
  if(random(100)>42) {
    tell_room(TO, TPN+" slips and falls back to the floor!\n");
    tell_object(this_player(),"You slip and fall back to the floor.  Ouch!\n");
    this_player()->hit_player(6);
    return 1;
  }
  tell_object(this_player(), "You climb out of the pit.\n");
  this_player()->move_player(
    "out of the pit#players/emerald/perilous/frost/cave13");
}
