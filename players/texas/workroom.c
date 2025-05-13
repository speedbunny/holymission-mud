/* Tex's workroom
* Created 25 March 1998
*/

inherit "room/room";
int shield;

void reset(int arg)
{
  if(!arg)
  {
   set_light(1);
   short_desc = "Tex's Workroom";
   long_desc = "Tex's Workroom. Not usually a good place to hang around!\n";
   dest_dir = 
   ({
     "/players/texas/forest/rooms/entry","forest",
   });
  }
}

init()
{
  ::init();
  add_action("set_shield","shield");
  check();
  if(!this_player()->short())
    this_player()->vis();
}

set_shield(str)
{
   if(this_player()->query_real_name()!="texas")
   {
     return;
   }
   if(!str)
   {
     write("shields are on\n");
     shield=1;
     return 1;
   }
   if(str=="off")
   {
     write("shields are off\n");
     shield=0;
     return 1;
   }
   write("set shield to what?\n");
   return 1;
}

void check()
{

   if(shield && !(this_player()->query_real_name()=="texas"))
   {
      write("Tex does not want to be disturbed. Maybe you should try later\n");
     say(this_player()->query_name()+" failed to enter\n");
      move_object(this_player(), "/room/church");
      }
      }
