inherit"room/room";
#include "../walhalla.h"

int wei;
reset(arg)
{ ::reset(arg);
  if(!arg)
  { set_light(0);
    short_desc="Elevator",
    long_desc="This is the ancient elevator of Walhalla. You see a little chair\n" +
              "and a small window. The rest of the room looks quite normal.\n";

    items=({"chair","Wow ! A real evelator chair",
            "window","You see a little huge box hanging on a big rope.\n" +
                     "I think you should lay something in the box to change\n" +
                     "its weight",
            "box","It looks bottomless..."});
    property =({"no_teleport","no_hide"});
    dest_dir =({ROOM + "floor6","west"});
    smell = "It smells like death in here";
    CO("elevsign");
  }
}

init()
{ ::init();
  write("PLOC ! You think something has fallen somewhere...\n");
  wei=0;
  add_action("myput","put");
}

int myput(string str)
{ int flag,i,j,roomweight;
  object *env2,*env,dummyob;
  string dummy;

  flag=0;
  roomweight=0;

  env2=filter_objects(deep_inventory(this_object()),"query_weight");
  for(i=0,j=sizeof(env2);i<j;i++)
  { roomweight+=env2[i]->query_weight();
  }

  if(!str)
  { write("Put what ?\n");
    return 1;
  }

  sscanf(str,"%s into box",dummy);  
  if(!dummy)
    return 0;
 dummyob=present(dummy,TP);
  if(!dummyob)
  { write("You don't have that item.\n");
  }
  else
  { transfer(dummyob,ROOM + "treasure");
    tell_room(ROOM + "treasure","Something appears from somewhere...\n");
    say(TPN +" puts the "+dummyob->query_name()+" into the box.\n",TP);
    write("You put the "+dummyob->query_name()+" into the box.\n");
    wei+=(dummyob->query_weight())*2;
    tell_room(TO,"You hold on with "+wei+" but need " +roomweight+".\n");
    if(wei>roomweight)
    { write("WWWWWWWWWWOOOOOOOOOOOOSSSSSSSSSSSSHHHHHHHHHH\n" +
            "The elevator moves up...\n");
      env=all_inventory(TO);
      for(i=0,j=sizeof(env);i<j;i++)
       transfer(env[i],ROOM + "first1");

      return 1;
    }
  }
  return 1;

}

