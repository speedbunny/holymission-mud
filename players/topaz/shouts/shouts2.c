#ifndef _ninja_communicate_
#define _ninja_communicate_

int noff;

/* --- the shout -------------------------------------------------------------- */
_shout( str )
{
   object *u;
   int    i;

   if ( !str ) {
      write( "Shout what ?\n" );
      return( 1 );
   } 

   if ( !(TP->query_wizard()) && TP->query_sp() < TP->query_max_sp()/5 )
      write( "Your mouth is that dry that you don't manage it to shout.\n" );
   else {
      if ( str == "nihonese" ) {
         write( "Shout what in nihonese ?\n" );
         return( 1 );
      }
      
      if ( explode( str, " " ) && explode( str, " " )[0] == "nihonese" ) {
         str = extract( str, strlen("nihonese")+1, strlen( str )-1 );
         write( "You shout in nihonese:\n   " + str + "\n" );
         
         log_file( "SHOUTS", TP->query_real_name()+": "+TP->query_name() + 
                             " shouts in nihonese:\n  " + str + "!\n\n" );
         
	 u = users();
         for ( i = 0; i < sizeof( u ); i++ ) {
            if ( u[i]->query_guild() == 8 && u[i] != TP ) {
               if ( TP->query_level() >= 25 )
                  tell_object( u[i],
                        TP->query_name() + "-san shouts in nihonese:\n  " + str + "!\n" );
               else
                  tell_object( u[i],
                        TP->query_name() + " shouts in nihonese:\n  " + str + "!\n" );
            }
            else if ( TP != u[i] )
               tell_object( u[i],
                            TP->query_name() + " shouts something in nihonese.\n" );
         }
         
      }
      else {
         write( "You shout:\n  " + str + "!\n" );
         shout( TP->query_name() + " shouts: " + str + "!\n" );
      }
      if ( !TP->query_wizard() )
         TP->restore_spell_points( -1 * (TP->query_max_sp()/5) );
   }
   
   return( 1 );
}

/* --- say -------------------------------------------------------------------- */
_say( what )
{
   int    i;
   object inv;
   string name;

   if ( !what ) {
      write( "Say what ?\n" );
      return( 1 );
   }
   else if ( what == "nihonese" ) {
      write( "Say what in nihonese ?\n" );
      return( 1 );   
   }
   if ( TP->query_level() > 24 )
      name = TP->query_name() + "-san says";
   else
      name = TP->query_name() + " says";

   if ( explode( what, " " ) && explode( what, " " )[0] == "nihonese" ) {
      what = extract( what, strlen("nihonese")+1, strlen( what )-1 );
      write( "You say in nihonese: " + what + "\n" );
      inv = all_inventory( environment( this_player() ) );
      for ( i = 0; i < sizeof(inv); i++ ) {
         if ( living( inv[i] ) ) {
            if ( inv[i]->query_guild() == 8 && inv[i] != TP ) {
               tell_object( inv[i], name + 
                               " in nihonese:\n  " + what + "\n" );
            }
            else if ( inv[i] != TP )
               tell_object( inv[i], name + 
                                    " something in nihonese.\n" );
         }
      }
   }
   else {
      say( name +": " + what + "\n" );
      write( "You say: " + what + "\n" );
   }
      
   return( 1 );
}

/* ----- ninjas online ------------------------------------------------------------- */
_ninja( str )
{
   string msg, tmp, name;
   object *u, *nsoul;
   int i, anzWiz, anzPlay;

   u = users();

   /* --- toggle guild on/off ----------- */
   if ( str == "off" ) {
      write( "Ninja-channel now off.\n" );
      noff = 1;
      return( 1 );
   }
   if ( str == "on" ) {
      noff = 0;
      write( "Ninja-channel now on.\n" );
      return( 1 );
   }

   name = TP->query_name();

   /* --- guild emote ------------- */
   if ( str && explode(str," ")  &&
        explode( str, " " )[0] == "emote" ) {
      if ( !str || sizeof( explode(str," ") ) < 2 ) {
         write( "What do you want to emote?\n" );
         return( 1 );
      }
      sscanf( str, "%s %s", msg, str );
      for ( i = 0; i < sizeof( u ); i++ ) {
         if ( u[i]->query_guild() == GUILD_MASTER->query_number(GUILD) ) {
            nsoul = present( "ninja_soul", u[i] );
            if ( !nsoul ) break;
            if ( nsoul->query_noff() == 0 )
               tell_object( u[i], "<<"+name
                            +" "+str+">>\n" );
         }
      }
      write( "Ok.\n" );
      return( 1 );
   }

   /* --- guild-message ----------- */
   if ( str ) {
      for ( i = 0; i < sizeof( u ); i++ ) {
         if ( u[i]->query_guild() == GUILD_MASTER->query_number(GUILD) ) {
            nsoul = present( "ninja_soul", u[i] );
            if ( !nsoul ) break;
            if ( u[i]->query_earmuff_level() < TP->query_level() )
               if ( nsoul->query_noff() == 0 )
               tell_object( u[i], "<<"+name
                            +">> " + str + "\n" );
         }
      }
      write( "Ok.\n" );
      return( 1 );
   }

   /* --- show online ------------- */
   u = sort_array( u, "less_func", this_object() );
   anzWiz = anzPlay = 0;

   msg = right_align( "Name", 25 ) + right_align( "Gender", 8 ) +
         right_align( "Race", 20 ) + right_align( "Level", 12 ) + 
         "Extras\n";
   msg += get_line( "=", 75 ) + "\n";

   for (i=0;i<sizeof(u);i++) {
      if ( u[i]->query_guild() == GUILD_MASTER->query_number(GUILD) ) {
         nsoul = present( "ninja_soul", u[i] );
         if ( !nsoul ) break;
         if ( u[i]->query_immortal() ) {                         /* wizzes */
            if ( !(u[i]->query_invis()) ||
                 TP->query_immortal() ) {
               anzWiz++;
               if ( u[i]->query_invis() )
                  msg += right_align( capitalize(u[i]->query_real_name()), 25 );
               else
                  msg += right_align( process_string(u[i]->query_name()), 25 ); 
               msg += right_align( u[i]->query_gender_string(), 8 ) +
               right_align( u[i]->query_race(), 20 ) +
               right_align( "(immortal)", 12 );
               if ( u[i]->query_earmuff_level() >= TP->query_level() )
                  msg += "(busy) ";
               if ( nsoul->query_noff() )
                  msg += "(off) ";
               if ( u[i]->query_invis() )
                  msg += "(invis)";
               msg += "\n";
            }
         }
         else {                                                    /* player */
            if ( !anzPlay )
               msg += get_line( "-", 75 ) + "\n";
            anzPlay++;
            msg += right_align( NINJA_TITLES->get_pretitle(u[i]->query_level())
                   + " " + capitalize( u[i]->query_real_name() ), 25 ) +
                   right_align( u[i]->query_gender_string(), 8 );
            msg += right_align( u[i]->query_race(), 20 );

            msg += right_align( "(" + u[i]->query_level() + ")", 12 );
            if ( nsoul->query_iscamou() ) {
               if ( TP->query_immortal() )
                  msg+= "(C"+nsoul->query_iscamou()+") ";
               else
                  msg += "(camou) ";
            }
            if ( nsoul->query_noff() )
               msg += "(off)";
            msg += "\n";
         }
      }
   }
   
   msg += get_line( "=", 10 ) + " Wizes: ";
   tmp = (string) anzWiz;
   msg += right_align( tmp, 2 ) + " === Players: ";
   tmp = (string) anzPlay;
   msg += right_align( tmp, 2 ) + " " + get_line( "=", 38 );
   write( msg + "\n\n" );

   return( 1 );     
}
#endif

less_func( ob1, ob2 )
{
   if ( ob1->query_level() < ob2->query_level() )
      return( 1 );

   return( 0 );
}

query_noff()
{
   return( noff );
}

right_align( txt, w )
{
   if ( strlen( txt ) < w )
      txt = txt + "                                     ";

   return( extract( txt, 0, w-1 ) );
}

get_line( c, w )
{
   int i;
   string l;

   l = "";
   for ( i = 0; i < w; i++ )
      l += c;

   return( l );
}


/* ----- beep dice ------------------------------------------------------------- */
_beep( arg )
{
  object obj;
  
  if ( arg != "dice" ) {
     write( "Sorry, but you only can beep Dice.\n" +
            "And this only for a good reason ! (e.g. a bug or something like that)\n" );
     return( 1 );
  }
  
  obj = find_player( "dice" );
  if ( !obj || obj->query_invis() ) {
    write( "Sorry, but Dice isn't on right now.\n" );
    return( 1 );
  }
  
  tell_object( obj, "" );
 tell_object( obj, "---->" + TP->query_name() + " beeped you !\n");
 write("You just called for Dice.\nHe will answer as soon as possible.\n"+
    "Maybe he is off for coffee ( As usual ...)\n");
  
  return( 1 );
}


#endif /*_ninja_communicate_*/
