
inherit "/room/room";

#define SAY(x) tell_room(this_object(),x)

object pl;  /* one objectvar is enough */

void reset(int arg)
{
  if (arg) return;
  enable_commands();
}

void init()
{
  ::init();
  if (interactive(this_player()))
  {
      pl = this_player();
     SAY("Bulp..\n");
      set_heart_beat(1);
  }
}   

void heart_beat()
{
  if (present(pl,this_object()) && interactive(pl))
  {
    if (!random(4)){
     SAY("Bulp..\n");
     SAY("A cloud of steam raises up.\n");
    }
   }

  else 
     set_heart_beat(0);
}
   
     
   
