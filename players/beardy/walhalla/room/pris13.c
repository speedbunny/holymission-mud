inherit"room/room";
#include "../walhalla.h"
#include "../prison.h"
#include "../func.h"
#define PRIS "/players/beardy/walhalla/room/pris15"

int i, time;


reset(int arg)
{ ::reset(arg);
  if(!arg)
  { set_light(0);
    time=0;
    short_desc="Walhalla's prison",
    long_desc="You are in Walhalla's prison. It is very dark in here.\n" +
              "The walls are covered with blood spills and rotten flesh.\n" +
              "Sometimes you see a head, hanging from the ceiling, looking\n" +
              "very strange. You hear lots of strange sounds, some seem to\n" +
              "be very painful shouts. You see a big button in front of\n" +
              "you.\n";
    
    items=({"head","This time there is no head",
            "heads","This time there are no heads",
            "button","It's for opening the secret door to the cells",
            "walls","They are wet",
            "wall","It is wet",
            "flesh","Yum yum yum. It tastes good",
            "blood","Normal blood spills"});

    property =({"no_teleport","no_sneak","no_hide"});

    dest_dir =({ROOM + "pris10","northeast",
                ROOM + "pris16","south",
                ROOM + "pris14","east"});

    smell = "You smell nothing special";

    if(random(GUARD_RANDOM)==1)
      CM("cguard");

    for(i=1;i<=3;i++)
      CM("pmonster");
  }
}


init()
{ ::init();
  add_action("mypush","push");
}

int mypush(string str)
{ if(!str && str!="button") return 0;
  else
  {
   if (PRIS->check_player()==1)
   {  tell_room(TO,"You are lucky, you have found a player.\n");
      tell_room(PRIS,"You are lucky ! "+TPN+" set you free.\n");
      trans_all_room(PRIS,TO);
      return 1;
   }
   else  
   { if(time==0)
     { tell_room(TO,"Oh, its a normal aggressive prisoner.\n");
       CM("prisoner");
       time++;
       return 1;
     }
     else
     { tell_room(TO,"Oh, its empty, what a pity....\n");
       return 1;
     }
   }
  return 1;
  }
}

