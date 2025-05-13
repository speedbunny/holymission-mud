inherit"room/room";
#include "../walhalla.h"
#include "../prison.h"
#include "../func.h"
#define PRIS9 "/players/beardy/walhalla/room/pris9"

int i,time;

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
              "be very painful shouts. You see a bit button at the west wall.\n";
     
    
    items=({"head","This time there is no head",
            "heads","This time there are no heads",
            "button","It's for opening the secret door to the cells",
            "walls","They are wet",
            "wall","It is wet",
            "flesh","Yum yum yum. It tastes good",
            "blood","Normal blood spills"});

    property =({"no_teleport","no_sneak","no_hide"});

    dest_dir =({ROOM + "pris3","east",
                ROOM + "pris7","south"});

    smell = "You smell nothing special";

    if(random(GUARD_RANDOM)==1)
      CM("cguard");
    for(i=1;i<=MONSTER_NUMBER;i++)
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
   if (PRIS9->check_player()==1)
   {  tell_room(TO,"You are lucky, you have found a player.\n");
      tell_room(PRIS9,"You are lucky ! "+TPN+" set you free.\n");
      trans_all_room(PRIS9,TO);
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


