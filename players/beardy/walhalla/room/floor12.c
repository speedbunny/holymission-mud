inherit"room/room";
#include "../walhalla.h"

reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="Ground floor of Walhalla",
    long_desc="This is the ground floor of Walhalla. The room is very\n" +
              "high and bottom is covered with strange fog. Under the\n" +
              "fog you recognize a wooden floor. It seems very old to\n" +
              "you.\n"; 

    items=({"fog","Huh ! It's cold",
            "bottom","What a dense fog",
            "ceiling","There are lots of holes in there",
            "holes","Oops ! They seem to be burned"});

    property =({"no_sneak","no_teleport","no_hide"});

    dest_dir =({"/players/beardy/walhalla/room/floor9","east",
                "/players/beardy/walhalla/room/floor11","west"});

    smell = "It smells divine in here";

  }
}

init()
{ if(TP->query_weight()>=10)
  { write("CRACK ! The wooden floor breaks under you weight.\n" +
          "You fall down into the ancient catacombs.\n");

    move_object(TP,ROOM + "cat1");
    return 1;
  }
  else
  { write("You feel the floor cracking under you feet, "+
          "but is withstands.\n");
  }
  ::init();
} 
