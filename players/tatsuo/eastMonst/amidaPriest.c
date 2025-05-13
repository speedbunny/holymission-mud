#define PPATH ("/players/tatsuo/eastMonst/")
#define TP    (this_player())
#define TO    this_object()

inherit "obj/monster";

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
   set_name( "priest" );
   set_alias( "buddhistic priest" );
   set_level( random(5) + 1 );
   set_size( 2 );
   set_gender( 1 );

   set_dead_ob( "/players/tatsuo/eastMonst/monst_died" );
}

long( )
{
   write( "This priest is a master of Buddhism!\n" );
}

short()
{
   return( "A buddhistic priest" );
}

attack()
{
   object ob;

   if ( this_player()->query_attack() ) {
      say( "The priest makes a gesture with his right hand and vanishes.\n" );
      if ( !present( "alarm_ten", this_player()->query_attack() ) ) {
         ob = clone_object( "/players/tatsuo/guild/nother/alarm_ten" );
         if ( ob )
            move_object( ob, this_player()->query_attack() );
      }
      destruct( this_object() );
   }
}

/* ----- the info-function ----------------------------------------------- */
catch_tell( arg )
{
   string *words, x;
   int i;
      
   if ( !arg )
      return;

   arg = process_string( arg );

   if ( sscanf( arg, "%s says: %s\n", x, arg ) != 2 )
      return;
      
   words = explode( arg, " " );
   
   if ( words && sizeof( words ) ) {
      i = 0;
      while ( i < sizeof( words ) ) {
         if ( words[i] == "dart" || words[i] == "darts" 
              || words[i] == "poison-dart" ) {
            if ( present( "birch-bark", this_player() ) 
                 && present( "fugu", this_player() ) )
               write( 
                "The buddhistic priest says: I see, you have the bark and the fugu.\n" +
                "   And now you want to know the spell, with which you can create the poison,\n" +
                "   won't you. All right, I see you are a brave pilgrim, so I will teach you.\n\n" +
                "   All you have to do is to put the bark and the fugu in the clayey cup, and\n" +
                "   then mumble the following: \"kayoto sylabatsi\".\n" );
             else
               write( "The buddhistic priest says: Get the proper items first, maybe ... and\n" +
                      "   only maybe ... i will teach you then.\n" );
            break;
         }
         else if ( words[i] == "potion" || words[i] == "potions" ) {
            ltell( TP, "The priest speaks:\n",
                  "There is one potion I know of. It can cure poison. But I\n"+
                  "need a special herb to produce it. If you would bring me\n"+
                  "this herb, I will willingly make one for you.\n", TO );
              break;
         }
         else if ( words[i] == "herb" ) {
            ltell( TP, "The priest speaks:\n",
                   "It is a herb that grows in dark places. Also it is very\n"+
                   "seldom. I haven't found one by myself for years now.\n",TO);
             break;
         }
         i++;
      }
   }

   return( 1 );
}

void enter_inventory( object obj )
{
   object pot;

   if ( obj->id( "_antidodes_herb_" ) ) {
      ltell( TP, "says:", "Thank you for the herbs.\n", this_object() );
      write( "The priest puts the herbs into a flask, adds some liquid "+
             "and spits into it.\n" );
      ltell( TP, "says:", "Here you are, fellow.\n" );
      pot = clone_object( "/players/tatsuo/guild/nother/potion" );
      pot->set_content(1);
      if ( transfer( pot, TP ) ) {
         ltell( TP, "says:", "You cannot carry anymore, so I drop it.\n", TO );
         transfer( pot, environment(TO) );
      }
      write( "The priest gives you a potion.\n" );
   }

   ltell( TP, "says:", "Thank you very much, fellow.\n" );
}

int speaks_in( ) { return( 1 ); }

int act_language_skill( )
{
   return( 100 );
}

// Mangla: corrected number of args.  had only 3 with third being string.
int lcatch_tell( string act, string msg, object who, int kind )
{
   if ( TP->speaks_in() != 1 )
      write("The priest looks at you, seemingly understanding not a "+
            "single word !\n" );
   else
      catch_tell( who->query_real_name()+" "+act+" "+msg );

   return( 1 );
}
