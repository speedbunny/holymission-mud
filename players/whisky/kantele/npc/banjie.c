
/* banjie */

inherit "obj/npc";

void reset(int arg)
{
   ::reset( arg );
   
   if ( arg )
      return;

   set_race( "elf" ) ;
   set_name( "shy banjie" );
   set_alias( "banjie" );
   set_level( 20 );
   set_size( 3 );
   set_short( query_name() );
   set_long(
   "You see a female white haired, awful looking elf.");
   set_gender( 2 );
   set_ep( 1500000 );
   set_al( -500 );
   add_money( 2000 );
   set_aggressive( 1 );
   set_n_wc( 3 );
}

int detect_invis()
{
   return( 1 );
}

int infravision()
{
   return( 1 );
}

varargs mixed attack(object wep,object hand)
{
   int chr;
   object sz;

    if (!random(5))  
    {
        chr = apply(call,attacker_object,"query_chr");
        tell_room(environment(this_object()),
        "The banjie sings an awful song !\n");       
        sz = first_inventory(environment());

        while(sz)
        {
           if (apply(call,sz,"query_hp") && !random(chr))
           {
              if (random(3))
                  apply(call,sz,"run_away");
              else
                  apply(call,sz,"hit_player",10000,7);
           }
        }
        sz = next_inventory(environment());
     }
     return ::attack(wep,hand);
}

                 


