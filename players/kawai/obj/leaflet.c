#include <lw.h>
#define TO this_object()

int n1,n2,n3;

int id(string str)
  {return str=="pamphlet" || str=="kq1-pam" || str=="leaflet";}

string short()
  {return "a pamphlet";}

int query_num(int arg)
  {if(!arg)
    {return 36;}
  if(arg==1) 
    {return n1;}
  else if(arg==2)
    {return n2;}
  else if(arg==3)
    {return n3;}}

void long()
  {writelw("The pamphlet seems to be some sort of propaganda for an underground cult. "+                                                                             "Apparently, a small band of wizards is recruiting people to build an army\n"+
  "of wizards and eventually take over Holy Mission!  While the pamphlet doesn't "+
  "actually say that (they claim only to be uniting to voice complaints to the "+
  "government of Holy Mission, and begin an 'alternative' political party), you get "+
  "the feeling that they are up to no good.  Could it be the picture of the rotting "+
  "corpse they use as a logo?  Or perhaps the catch-phrase \"Come! Join us in a "+
  "child sacrifice to our god, Kazak!\"...Alas, nothing could be as evil as the free "+
  "continental breakfast...not even the frequent-sacrificer bonus plan!\n"+
  "Scrawled on the back are the numbers "+query_num(1)+"-"+query_num(2)+"-"+
  query_num(3)+".\n");}

int query_weight()
  {return 1;}

int query_value()
  {return 0;}

int get(string str)
  {return 1;}

int drop()
  {writelw("As you let go of the pamphlet, it catches a breeze and blows away.\n");
  destruct(TO);
  return 1;}

void init()
  {add_action("read_it","read");}

status read_it(string str)
  {if(!str)
    {notify_fail("Read what?\n");
    return 0;}
  if(str=="pamphlet"||str=="leaflet")
    {long();
    return 1;}
  if(str=="number"||str=="numbers")
    {write("Scrawled on the back are the numbers "+query_num(1)+"-"+query_num(2)+"-"+
    query_num(3)+".\n");
    return 1;}}

void reset(int arg)
  {if(!arg)
    {n1=random(35)+1;
    n2=random(35)+1;
    n3=random(35)+1;}}



