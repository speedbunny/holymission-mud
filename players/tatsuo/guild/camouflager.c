#include "/players/tatsuo/guild/ndef.h"
int id(string arg) 
{
    return (arg == "camouflager");
}
 void init()
{
  call_out("dest_me", TP->query_int()*6);
}

void dest_me()
{
  TP->set_vis();
   destruct(this_object());
}

int get()
{
    return 1;
}

int drop()
{
  return 1;
}

