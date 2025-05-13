
/* commuter */

#define START "/players/patience/ezo/coast/rf10"
#define ISL   "/players/muzmuz/island/rooms/jetty"

int pos;

void reset(int flag)
{
     if (flag == 0)
     {
       pos = 2;
       call_other(START,"???");
       call_other(ISL,"???");
       move_object(this_object(),START);
       tell_room(find_object(START),"A commuter arrives at the shore.\n");
       call_out("start_tour",4);
       move_object(clone_object("/players/muzmuz/island/captain"),
                   this_object());
      }
}
               
void start_tour()
{
   tell_room(environment(),
   "The captain of the commuter shouts: We are leaving in 30 seconds.\n");
   call_out("on_sea",30);
}

void on_sea()
{
   tell_room(environment(),"A commuter leaves the shore.\n");
   tell_room(this_object(),"The commuter leaves the shore.\n");
   move_object(this_object(),"/players/muzmuz/castle");
   if (pos == 0 || pos == 2)
       call_out("trip_isl",30);
   else
       call_out("trip_start",30);
   pos = 3;
}

void trip_isl()
{
   tell_room(this_object(),"The commuter arrives at the island.\n");
   move_object(this_object(),ISL);
   tell_room(environment(),"A commuter arrives at the shore.\n");
   pos = 1;
   call_out("start_tour",8);
}

void trip_start()
{
   tell_room(this_object(),"The commuter arrives at the shore.\n");
   move_object(this_object(),START);
   tell_room(environment(),"A commuter arrives at the shore.\n");
   pos = 0;
   call_out("start_tour",8);
}
    
string short()
{
    return "A commuter";
}

string query_name()
{
     return short();
}

int no_clean_up()
{
   return 1;
} 

int id(string arg)
{
    return (arg=="commuter");
}   

void long()
{
     write(
     "This is the Cargo junk which transfers adventurers  from ezo to the island\n"+
     "of death and back. \n");
}

int query_weight()
{
     return 20000;
}

void init()
{
     add_action("do_enter","enter");
     add_action("do_leave","leave");
}

int do_enter(string arg)
{
   object env;

    if (id(arg) && environment(this_player())==environment(this_object()))
    {
        tell_object(this_player(),"You leave on board.\n");
        env = environment(this_player());
        move_object(this_player(),this_object());
        tell_room(env,this_player()->query_name()+" enters the commuter.\n");
        this_player()->command("look");
        return 1;
     }
    return 0;
}

int do_leave(string arg)
{

     if (environment(this_player())!=this_object())
         return 0;
     else if (!id(arg))
     {
          notify_fail(
          "If you wanna leave the commuter type 'leave commuter'\n");
          return 0;
     }
     else if (pos == 3)
     {
          notify_fail(
          "As you try to jump into the sea the captain holds you back.\n");
          return 0;
     }
     write("You leave the commuter.\n");
     say(this_player()->query_name()+" leaves the board.\n",this_player());
     tell_room(environment(),
     this_player()->query_name()+" leaves a commuter.\n");
     move_object(this_player(),environment());
     command("look",this_player());
    return 1;
}
     
      
 
