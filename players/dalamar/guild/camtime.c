#include "/players/tatsuo/guild/ndef.h"
int id(string arg) 
{
    return (arg == "camtime");
}
 void init()
{
  call_out("dest_me", (100 - TPDEX) *2 +60 +random(60) );
}

void dest_me()
{
   destruct(this_object());
}

int get()
{
    return 1;
}

int drop()
{
    return 0;
}
