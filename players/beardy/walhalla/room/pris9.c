inherit"room/room";
#include "../walhalla.h"
#include "../prison.h"
#include "../func.h"


reset(int arg)
{ ::reset(arg);
  if(!arg)
  { set_light(0);
    short_desc="Walhalla's prison",
    long_desc="This is one of the many cells in Walhalla.\n" +
              "You see some engravings at the wall. The the\n" +
              "you find nothing special about this cell.\n";
 
     items=({"engraving","What have you done to get in here ? Have you\n" +
                         "killed a little nice newbie monster ? Oh, what\n" +
                         "a bad person you are",
             "engravings","Look at the engraving",
             "cell","It is a dark dusty and ugly place\n" +
                    "Perhaps you should shout for help"});
    
    property =({"no_teleport"});

    smell = "You smell nothing special";
  }
}

void init()
{ ::init();
  add_action("myquit","quit");
  add_action("myshout","shout");
  add_action("mytell","tell");
  call_out("get_out",IN_PRIS_TIME,TP);
}

get_out(object tp)
{ tell_object(tp,"You finished you time in prison.\n");
  transfer(tp,ROOM + "cat1");
  return 1;
}

int myquit()
{ write("Oh no ! You cant quit in here.\n");
  return 1;
}



int myshout(string str)
{ shout("Jailed "+TPN+" shouts very helplessly : "+str+" .\n");
  write("OK. You shouted. What's next ?\n");
  return 1;
}

int mytell(string str)
{ write("The walls are to thick to tell, you have to shout.\n");
  return 1;
}
