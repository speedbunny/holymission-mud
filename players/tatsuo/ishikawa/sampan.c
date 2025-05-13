
/* sampan */

#define START "/players/patience/ezo/coast/sh14"
#define ISL   "/players/tatsuo/ishikawa/jungle/beach1"

int pos;

void reset(int flag)
{
     if (flag == 0)
     {
       pos = 2;
     set_light(1);
       call_other(START,"???");
       call_other(ISL,"???");
       move_object(this_object(),START);
       tell_room(find_object(START),"The sampan arrives at a dock.\n");
       call_out("start_tour",4);
	move_object(clone_object("/players/tatsuo/ishikawa/monsters/fisher"),
                   this_object());
      }
}
               
void start_tour()
{
   tell_room(environment(),
   "The fisher says: Come I take you to Ishikawa, The Isle of Light.\n");
   call_out("on_sea",30);
}

void on_sea()
{
   tell_room(environment(),"The sampan sails into the horizon.\n");
   tell_room(this_object(),"The sampan sets to sea.\n");
   move_object(this_object(),"/room/void");
   if (pos == 0 || pos == 2)
       call_out("trip_isl",30);
   else
       call_out("trip_start",30);
   pos = 3;
}

void trip_isl()
{
   tell_room(this_object(),"The sampan arrives at shore.\n");
   move_object(this_object(),ISL);
   tell_room(environment(),"A sampan is rowed up to the dock.\n");
   pos = 1;
   call_out("start_tour",8);
}

void trip_start()
{
   tell_room(this_object(),"You arrive at shore.\n");
   move_object(this_object(),START);
   tell_room(environment(),"A small sampan arrives at the shore.\n");
   pos = 0;
   call_out("start_tour",8);
}
    
string short()
{
    return "A small sampan";
}

string query_name()
{
     return short();
}

int id(string arg)
{
    return (arg=="sampan");
}   

void long()
{
     write(
     "This is a small fishing vessel made for 3 persons.  The fisherman\n"+
     "has offered to ferry you between Ishikawa and Ezo.\n");
}

int query_weight()
{
     return 20000;
}

void init()
{
     add_action("do_enter","enter");
     add_action("do_leave","leave");
     add_action("do_leave","out");
}

int do_enter(string arg)
{
   object env;

    if (id(arg) && environment(this_player())==environment(this_object())) 
    {   
     if (this_player()->query_ronin()){
        tell_object (this_player(),
	"The fisherman says: Off my boat RONIN!\n");
        return 1; }
        tell_object(this_player(),"You leave on board.\n");
        env = environment(this_player());
        move_object(this_player(),this_object());
	tell_room(env,this_player()->query_name()+" enters the sampan.\n");
        this_player()->command("look");
        return 1;
     }
    return 0;
}

int no_clean_up()
{
   return 1;
}

int do_leave(string arg)
{

     if (environment(this_player())!=this_object())
         return 0;
     else if (!id(arg))
     {
          notify_fail(
	"If you wanna leave the sampan type 'leave sampan'\n");
          return 0;
     }
     else if (pos == 3)
     {
          notify_fail(
	"As you try to jump into the sea the fisherman holds you back.\n");
          return 0;
     }
     write("You leave the sampan.\n");
     say(this_player()->query_name()+" leaves the board.\n",this_player());
     tell_room(environment(),
     this_player()->query_name()+" leaves a sampan.\n");
     move_object(this_player(),environment());
     command("look",this_player());
    return 1;
}
     
      
 
