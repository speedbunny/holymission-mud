


inherit "/room/room";

#define SAY(x) tell_room(this_object(),x)

object pl;  

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
     SAY("Mortar falls from the ceiling and the walls.\n");
      set_heart_beat(1);
  }
}   

void heart_beat()
{
  if (present(pl,this_object()) && interactive(pl))
  {
    if (!random(4))
     SAY("Mortar falls from the ceiling and the walls.\n");
   }
  else 
     set_heart_beat(0);
}
   
     
