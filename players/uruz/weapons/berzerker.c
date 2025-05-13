inherit "obj/weapon";
#include "/players/patience/guild/nweap/nweap_mess.h"

#define TP   (this_player())

object *att_obj, *wielder;
int is_berzerk, old_wimpy;

reset( arg )
{
   ::reset( arg );
   if ( arg ) return;

   set_name( "berzerker" );
   set_alias( "axe" );
   set_short( "The axe \"berzerker\"" );
   set_long( "This is the famous axe \"berzerker\". It was forged by Gilius,\n"+
             "the Mighty, in the fires of Icee-Litos. Engraved at the hilt\n" +
             "are some dwarvish runes.\n" );

   set_class( 20 );
   set_value( 6000 );
   set_weight( 20 );
   set_light( 1 );

   set_hit_func( this_object() );
}

init( )
{
   ::init();

   add_action( "read_it", "read" );
   add_action( "do_berzerk", "berzerk" );

   add_action( "block_berz", "", 1 );
}

wield(arg)
{
   int ret;

   ret = ::wield(arg);
   if ( ret )
      wielder = TP;

   return( ret );
}

un_wield(arg)
{
   ::un_wield(arg);
   wielder = 0;
}

block_berz()
{
   if ( !is_berzerk )
      return;

   write( "You are busy berzerking, you cannot do something else !!!\n" );
   return( 1 );
}

read_it( arg )
{
   if ( !arg || arg != "runes" )
      return;

   write( "Berzerker is made for berzerk.\n" );

   return( 1 );
}

do_berzerk( )
{
   int dam;
   string *msg;

   if ( !query_wielded() )
      write( "Berzerker wants to be wielded !!!\n" );
   else if ( !(wielder->query_attack()) )
      write( "You aren't fighting !\n" );
   else if ( is_berzerk )
      write( "You are already berzerking.\n" );
   else {
      write("You write some nasty words and start to BERZERK !!!\n" );
      tell_object( wielder->query_attack(),
              wielder->query_name() + " growls some nasty words !!!\n" );
      say( wielder->query_name()+" growls some nasty words !!!\n",
           wielder->query_attack() );
      
      is_berzerk = 1;
      att_obj = wielder->query_attack();
      old_wimpy = wielder->query_wimpy();
      wielder->set_wimpy( -1 );
      call_out( "still_berz", 2 );
   }

   return( 1 );
}

still_berz()
{
   object *inv;
   int    i;

   if ( !is_berzerk )
      return;
   else if (att_obj && living(att_obj) && environment(att_obj)==environment(TP))
   {
      call_out( "still_berz", 2 );
      return;
   }

   att_obj = 0;
   if ( !wielder )
      inv = 0;
   else
      inv = all_inventory( environment(wielder) );
   if ( inv && sizeof( inv ) ) {
      i = 0;
      while ( i < sizeof(inv) && !att_obj ) {
         if ( living( inv[i] ) && inv[i]->query_npc() )
            att_obj = inv[i];
         i++;
      }
   }
   if ( att_obj && interactive( TP ) ) {
      tell_object( wielder, "You turn towards " + att_obj->query_name() +
                       "\n...and continue your berzerk !!!\n" );
      tell_object(att_obj,wielder->query_name()+" starts to attack you !!!\n" );
      say(wielder->query_name()+" starts to attack " + att_obj->query_name() +
           ".\n", att_obj );
      TP->attack_object( att_obj );
      call_out( "still_berz", 2 );
      return;
   }
   
   is_berzerk = 0;
   TP->set_wimpy( old_wimpy );
   return;
}

magic_hit()
{
   int dam, i, max;
   string *msg;

   if ( is_berzerk ) {
      max = 1 + random( 3 );
      for ( i = 0; i < max; i++ ) { 
         dam = wielder->query_str() + random( wielder->query_str() );
         att_obj->reduce_hit_point( dam );
         msg = query_hit_msg( dam, wielder->query_attack()->query_name(),
                              wielder, wielder->query_attack() ); 
         tell_object( wielder, "You " + msg[0] + "\n" );
         tell_object(wielder->query_attack(),
                     wielder->query_name()+" "+msg[1]+"\n" );
         say( wielder->query_name() + " " + msg[2] + "\n", att_obj );
      }
   }
   return( 1 );
}

dump()
{
   write( "att_obj: " );
   if ( att_obj )
      write( att_obj->query_name() );
   else
      write( "none" );
   write( "\nis_berzerk: " +is_berzerk+"\n");
   write( "wielder: " );
   if ( wielder )
      write( wielder->query_name() );
   else write( "none" );
   write( "\n" );
} 
