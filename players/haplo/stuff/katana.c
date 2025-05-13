#define TP             (this_player())
#define OWNERS         "/players/patience/guild/nweap/weap_owners"

inherit "/players/patience/guild/nweap/genNinWeap";

#include "/players/patience/guild/nweap/nweap_mess.h"

reset(arg)
{
   ::reset(arg);
   if (arg) return;

   set_name( "katana" );
   set_short( "A katana" );
   set_long("A katana is a long, slighty curved, sword. It is a nina weapon.\n"+
            "The katana looks extremely sharp.\n" );
   set_class( 20 );
   set_value( 0 );
   set_weight( 8 );

   hit_fact = 6;
   monst_hit_fact = 8;
   needed_lvl_fst = 25;
   needed_lvl_sec = 29;
   raise_block = 100;

   security_check();
}

int security_check()
{
   if ( this_player() ) {
      if ( !(OWNERS->is_kat_owner(this_player()->query_real_name())) ) {
         log_file( "ninja_log",
               this_player()->query_real_name() + " katana: reset-security ("+
                    ctime(time())+")\n" );
         write( "Privilege violation !!!! LOGGED !\n" );
         destruct( this_object() );
      }
      else
         set_owner( this_player()->query_real_name() );
   }
   else {
      log_file( "ninja_log",
            "katana: reset-security, no this_player() ("+ ctime(time())+")\n" );
      destruct( this_object() );
   }
}
