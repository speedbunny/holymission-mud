inherit"room/room";
#include "../asgard.h"

reset(int arg)
{ object monster;
  ::reset(arg);
  if(!arg)
  { set_light(1);
    short_desc="DON'T UPDATE THIS ROOM PLEASE....",
    long_desc="The secret heartbeat room.....\n";

    no_obvious_msg="";
    set_heart_beat(1);   

    monster=find_living("jukie");
    
    if(!monster)
    { tell_room("/players/beardy/workroom","Jukie start clone.\n");
      move_object(clone_object(MONST + "jukie"),ROOM + "asg025");
      move_object(clone_object(MONST + "berzerker"),ROOM + "asg025");
      move_object(clone_object(MONST + "berzerker"),ROOM + "asg025");
      move_object(clone_object(MONST + "berzerker"),ROOM + "asg025");
    }
    else
    { if(environment(monster)==0)
      { tell_room("/players/beardy/workroom","Jukie new clone.\n");
        move_object(clone_object(MONST + "jukie"),ROOM + "asg025");
        move_object(clone_object(MONST + "berzerker"),ROOM + "asg025");
        move_object(clone_object(MONST + "berzerker"),ROOM + "asg025");
        move_object(clone_object(MONST + "berzerker"),ROOM + "asg025");
      }
    }
  }
}


void heart_beat()
{ object monster;

  monster=find_living("jukie");
  switch(random(10))
    { case 1 : command("west",monster);break;
      case 2 : command("north",monster);break;
      case 3 : command("east",monster); break;
      case 4 : command("south",monster); break;
      case 5 : command("northwest",monster); break;
      case 6 : command("northeast",monster); break;
      case 7 : command("southeast",monster); break;
      case 8 : command("southwest",monster); break;
    }
}
