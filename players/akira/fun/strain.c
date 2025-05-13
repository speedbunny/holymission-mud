inherit "/obj/treasure";

object mad;
int    time;

id( arg )
{
   return( "_insanity_" );
}

reset( arg )
{
   if ( arg )
      return;
      
   time = 0;
   mad = 0;
}



start_madness( arg )
{  
   mad = arg;

   if ( !mad ) {
      write( "Your Gunna Love This!  Your Freind Akira!\n");
      mad = 0;
      return( 1 );
   }

   mad->move_player( "X#room/church" );
   write("You have no clue how the hell you got here!\n");
   call_out( "handle_insane", 0 );
   time = 0;

   return( 1 );
}

handle_insane()
{
   int    time1, i;
   object *ai;
   
   if ( !mad ) {
      destruct( this_object() );
      return;
   }

   move_object( this_object(), environment( this_object() ) );

   switch( random( 100 ) ) {
      case 0:
      case 1..5:   shout( capitalize( mad->query_real_name() ) + " shouts: " +
                      "Help me! I can't get them out of my head !!!\n");
              this_player()->hit_player(100, 7);
     this_player()->restore_spell_points(-(this_player()->query_sp()/2));
              write("A sharpe pain shoots throught your head!\n");
                   break;
      case 6..14: tell_object( mad, "Blood begins to pour from your nose!\n");
           say(this_player()->query_name()+" begins to bleed from there nose!\n");
               this_player()->hit_player(100, 7);
                   break;
      case 15..22: tell_object( mad, "Your mind is opened up to new thoughts!\n");
                    this_player()->set_int(40);
                   break;
      case 23..29: tell_object( mad, "You fall over and see your guts fall out of you onto the floor!\n");
            say(this_player()->query_name()+" falls over for no reason.\n");
                    this_player()->hit_player(500, 7);
                    this_player()->add_poison(50);
                   break;
      case 30..35: shout( capitalize( mad->query_real_name() ) + " shouts: " +
                     "I can't stop the voices in my head! HELP ME!!\n");
      this_player()->restore_spell_points(-(this_player()->query_sp()/2));
                   break;
      case 36..43: tell_object( mad, "You feel your blodd boil and you begin to glow with a strange light!\n");
                say(this_player()->query_name()+" begins to glow!\n");
                this_player()->set_ac(50);
                this_player()->set_wc(20);
                this_player()->set_str(40);
                this_player()->set_wimpy(0);
                   break;
      case 44..50: tell_object( mad, "You begin to hear peoples thoughts!\n");
                   say(this_player()->query_name()+" looks at you funny!\n");
                   this_player()->set_int(-10);
                   break;
      case 51..58: tell_object( mad, "You grin a evil grin!\n");
                   break;
      case 59..67: tell_object( mad, "The voices will not stop!!!!!\n");
                   say(this_player()->query_name()+" falls over in pain!\n");
                   this_player()->hit_player(50, 7);
                   this_player()->set_wis(-5);
                   break;
                   break;
      case 76..82: tell_object( mad, "Everyone seems to be looking at you!\n");
                   this_player()->run_away();
                   break;
      case 83..87: tell_object( mad, "You see a Teddy Bear Bleeding Milk!\n");
                   this_player()->run_away(2);
                   break;
      case 88..95: tell_room( environment( mad ), capitalize( mad->query_real_name() ) +
                      " says: I can't make them stop! Get them out of my head!\n");
                   break;
      default:     shout( capitalize( mad->query_real_name() ) + " tells you: " +
                      "I'm going INSANE help me! Make it stop!\n");
   }

   time1 = random( 100 );
   time += time1;
   
   ai = all_inventory( environment( mad ) );
   if ( ai ) {
      i = 0;
      while ( i < sizeof( ai ) ) {
         if ( ai[i] != mad )
            tell_object( ai[i], mad->query_name() + " smiles insanly.\n" );
         i++;
      }
   }
    
   if ( time > 200 ) {
      tell_object( mad, "Your head begins to clear! You feel better!\n");
      destruct( this_object() );
   }
   else
      call_out( "handle_insane", time1 );

   return;
}



   

 
