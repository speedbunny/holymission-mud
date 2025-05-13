
#define _chat "Galonhel says:"
#define _tour ({ "south","west","west","south","climb fence","east","east",\
                 "north","down"})
#define ROOM "/players/whisky/garden/room/dragon_room"

inherit "/obj/npc";

object *help;
int on_the_way;

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
       set_name("galonhel the Paladin");
       set_alt_name("galonhel");
       set_race("human");
       set_short("Galonhel the Paladin");
     set_long("A galant dragon slayer!\n");
       set_level(35);
       set_attacks(4);
       set_attacks_change(50);
       load_chat(20,({
       _chat+" oh hoho me the mighty Galonhel on the way to the Dragon !\n",
       _chat+" adventurers follow me hoho for the big kill !\n",
       _chat+" lets kill the Dragon !\n",
       _chat+" me the mighty Paladin will destroy this evil creature !\n",
       _chat+" follow me to kill this evil creature !\n",
       _chat+" come on fellowers lets do a good deed !\n" }));
       load_a_chat(40,({
       _chat+" dare you bastard !\n",
       _chat+" here comes my mighty strike !\n",
       _chat+" die evil creature !\n",
       _chat+" i will munch your guts bastard !\n" }));
       set_dodge(40);
       on_the_way = 0;
       help = ({});
     }
}
      

void init()
{
  ::init();
  add_action("do_follow","follow");
   environment()->reset(1);
}


int do_follow(string arg)
{    
    if (arg!="galonhel") 
        return 0;
    else if (member_array(this_player(),help)==1)
    {
      tell_room(environment(),
      _chat+" You are already following me "+this_player()->query_name()+".\n");
      return 1;
    }
    else 
    { 
      write("You start following Galonhel.\n");
      help = help + ({ this_player() });
      call_other(ROOM,"???");
      call_out("start_tour",10,this_object());
   }
   return 1;
}

       

void start_tour(object ob)
{
   object drag;
   int i, sz;

     if (on_the_way <=  sizeof(_tour) )       
     {
        for(sz = sizeof(help),i=0; i < sz;i++)
        {
           if (help[i] && environment() == environment(help[i]))   
               command(_tour[on_the_way],help[i]);
               
        }
        command(_tour[on_the_way],ob);
        on_the_way++;
        if (on_the_way == (sizeof(_tour) - 1))
            ROOM->reset(1);
        if ( (on_the_way== sizeof(_tour)) && 
              drag=present("dragon", environment()) )
        {
              tell_room(environment(),
              _chat+" die now evil dragon !\n");
              this_object()->attack_object(drag);
              for(sz = sizeof(help),i=0;i < sz; i++)
              {
                  if (drag && environment() == environment(this_object()))
                      help[i]->attack_object(drag);
              }
              on_the_way = 0;
              return; 
        }
       call_out("start_tour",2,ob);
     }
}

void split_exp()
{
    int i, sz;

    for (sz = sizeof(help),i = 0; i < sz; i++)
    {
         if (help[i] && environment() == environment(help[i]))
             help[i]->add_exp(5000);
    }
    tell_room(environment(),
    _chat+" its fullfilled guys !\n");
    call_out("leave_us",2);
}

void leave_us()
{
    tell_room(environment(),
    "Galonhel disappears in a cloud of mushrooms.\n");
    destruct(this_object());
    return;
}

int run_away()
{
    return 0;
}

    


 
