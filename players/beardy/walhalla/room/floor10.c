inherit"room/room";
#include "/players/beardy/walhalla/walhalla.h"

int time;

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    time=0;
    short_desc="Ground floor of Walhalla",
    long_desc="This is the ground floor of Walhalla. The room is very\n" +
              "high and the bottom is covered with strange fog. There \n" +
              "are some strange holes in the ceiling. This time there is\n"+
              "a strange hole in the wall too.\n"; 
    
    items=({"fog","Huh ! It's cold",
            "bottom","What a dense fog",
            "ceiling","There are lots of holes in there",
            "holes","They look not like the others. Perhaps you should search it",
            "hole","What a strange searchable hole"});

    property =({"no_sneak","no_teleport","no_hide"});

    dest_dir =({ROOM+"floor8","east",
                ROOM+"floor11","north"});

    smell = "It smells divine in here";

  }
}

init()
{ add_action("search","search");
  ::init();
}

search(str)
{ object ghost;

  if(!str)
  { write("What do you want to search ?\n");
    return 1;
  }
  if(str=="hole" || str =="holes")
  { if(time!=0)
    { write("There is nothing in the hole but a sharp thing\n");
      write("Ouch ! You cut your fingers.\n");
      this_player()->reduce_hit_point(random(20));
      return 1;
    }
    tell_room(TO,"A mighty ghostgod comes out of the hole.\n");
    ghost=clone_object("/players/beardy/walhalla/monster/ghostgod");
    move_object(ghost,TO);
    ghost->attack_object(TP);
    time++;
    return 1;
  }
  return 1;
}
