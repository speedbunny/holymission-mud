inherit "room/room";
#include <lw.h>

#define PATH "/players/kawai/areas/games/"
#define NUMS 9

object unlocked;
mixed numbers;
int num;

void reset(int arg) 
  {::reset(arg);
  num=0;
  if(!arg) 
    {numbers=({"two",3,
               "four",4,
               "eight",5,
               "ten",3,
               "fourteen",8,
               "sixteen",7,
               "twenty",6,
               "twentyfour",10,
               "thirty",6});
    set_light(0);
    property=({"no_teleport","lab"});
    short_desc="A dark tunnel";
    long_desc="You have reached a dead-end, so to speak.  Against the wall "+
    "is a swirling vortex, a portal and perhaps the only way out of this "+
    "hellish world.\n";
    dest_dir=({PATH+"labr15","northwest",
    PATH+"start","portal"});
    items=({"room","Just look around",
    "labrynth","A twisting maze of dark tunnels",
    "passage","Various passages lead off in all directions",
    "passages","They lead off in various directions",
    "ground","It is strewn with the bones of many like yourself",
    "floor","It is strewn with the bones of many like yourself",
    "bone","Looks like a tibia..",
    "bones","The bones of many, like you, got lost in this maze",
    "stone","The stone looks to be a blue and grey marble",
    "wall","A wall made of stone",
    "walls","The walls are carved of stone",
    "portal","A shimmering, swirling vortex",
    "vortex","A portal of some sort"});}}
  

void init()
  {::init();
  add_action("block","portal");
  add_action("answer","answer");}

status block()
  {if(this_player()==unlocked)
    {write("You pass through the portal and arrive someplace familiar...\n");
    return 0;}
  writelw("A vision of the Grand Wizard appears before you says: "+
  "I see you've managed to find your way out, but don't celebrate yet.  "+
  "To pass through this portal and to somewhere more comfortable, you "+
  "must answer one simple question for me.  I will give you a number "+
  "and you must answer with its corresponding number.  For example, if "+
  "I say Twelve, you 'answer 6'.  If I say 'Six', you 'answer 3'.  "+
  "Quite simple!\n");
  num=random(NUMS);
  writelw("\nThe number I seek corresponds to "+numbers[num*2]+".\n"+
  "'answer num' to unlock the portal.\n");
  return 1;}

status answer(string str) 
  {int x;
  if(!str)
    {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
    "What is your answer?\n"));
    return 0;}
  if(this_player()==unlocked)
    {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
    "Fortunately I recall you gave the correct answer recently.  You "+
    "may pass.\n"));
    return 0;}
  if(!sscanf(str,"%d",x))
    {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
    "What is your answer?\n"));
    return 0;}
  if(x!=numbers[(num*2)+1])
    {writelw("A vision of the Grand Wizard appears and says: "+
    "Sorry, but it appears that we may be spending a long time together "+
    "after all...\n");
    num=random(NUMS);
    writelw("\nThe new number I seek corresponds to "+numbers[num*2]+".\n"+
    "'answer num' to unlock the portal.\n");
    return 1;}
  else
    {writelw("A vision of the Grand Wizard appears and says: "+
    "Correct!  There may be hope for your species yet... You may pass.\n");
    unlocked=this_player();
    return 1;}}

  
