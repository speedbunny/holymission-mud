#define TP             (this_player())
#define OWNERS         "/players/patience/guild/nweap/weap_owners"

inherit "/players/patience/guild/nweap/genNinWeap";
#include "/players/patience/guild/nweap/nweap_mess.h"

int is_allowed( object who );

int vanish, ddt;

reset(arg)
{
   vanish = 1;
   ddt = 10;

   ::reset(arg);

   if (arg) return;

   set_name( "unbelieveable sharp katana" );
   set_alias( "protector" );
   set_short( "An unbelieveable sharp katana" );
   set_long( 
       "An unbelieveable sharp katana. Its blade is covered with ancient,\n"+
       "nihonese runes and the hilt is made of 'zoge'. Connected to the\n"+
       "end of the hilt is an onyx and the blade glows faintly green.\n" );
   set_class( 20 );
   set_value( 0 );
   set_weight( 0 );

   hit_fact = 6;
   monst_hit_fact = 8;
   needed_lvl_fst = 29;
   needed_lvl_sec = 29;
   raise_block = 100;
}

void init()
{
   ::init();

   add_action( "do_vanish", "vanish" );
   add_action( "do_detect", "detect" );
}

int wield( string arg )
{
   if ( !arg || !present(arg,this_player()) || arg != "protector" ) return( 0 );

   if ( !is_allowed(TP) ) {
      write( "The katana refuses to be wielded by you !\n" );
      return( 1 );
   }
   if ( TP->query_wielded(0) ) {
      write( "The katana refuses to be wielded in the off-hand !\n" );
      return( 1 );
   }

   modify_resistance( 9,  TP->query_legend_level()/2 );
   modify_resistance( 15, TP->query_legend_level()/2 );
   modify_resistance( 4,  TP->query_legend_level()/2 );
   modify_immunity( 12, TP->query_legend_level()/4 );

   modify_stat( 1, 2 );
   modify_stat( 2, 1 );
   modify_stat( 3, 2 );
   modify_stat( 4, 2 );

   return( ::wield( arg ) );
}

int get()
{
   if ( !is_allowed( TP ) ) {
      write( "The katana slitters away from you, as you try to get it !\n" );
      return( 0 );
   }

   return( 1 );
}

int is_allowed( object who )
{
   if ( who->query_real_name() == "lamorack" || who->query_immortal() )
      return( 1 );

   return( 0 );
}

int do_vanish( string arg )
{
   string dest;

   if ( arg == "ezo" )
      dest = "to Ezo#/players/patience/ezo/inner-yard1";
   else if ( arg == "church" )
      dest = "to the curch#/room/church";
   else
      return( 0 );

   if ( vanish <= 0 ) {
      write( "Nothing happens...\n" );
      return( 1 );
   }
   vanish--;

   write( "Protector begins to vibrate ....\n" );
   TP->move_player( dest );
   return( 1 );
}

int do_detect( string arg )
{
   string blah, dir, *dest_dirs, fn;
   int    idx;

   if ( !arg || sscanf(arg,"%s %s",blah,dir)!=2 || blah!="deathtrap" )
      return( 0 );

   if ( ddt < 0 ) {
      write( "The onyx stays dark ...\n" );
      return( 1 );
   }

   ddt--;

   dest_dirs = environment(TP)->query_dest_dirs();
   if ( !dest_dirs || (idx=member_array(dir,dest_dirs)) == -1 )
      write( "The onyx glows orange ...\n" );
   else {
      fn = dest_dirs[idx-1];
      if ( fn->is_dt() )
         write( "The onyx glows red ...\n" );
      else
         write( "The onyx stays dark ...\n" );
   }

   return( 1 );
}

_voiinskreiz()
{
   int ex_dam;

   if ( wielded_by && wielded_by->query_attack() &&
        (wielded_by->query_attack()->query_race() == "undead" ||
         wielded_by->query_attack()->query_race() == "Undead") )
   {
      write(
       "Protector vibrates in your hand. You can feel how she hates your "+
       "opponent !!!\n" );
      ex_dam = 30 + TP->query_legend_level();
      return( ::_voiinskreiz()*2 + ex_dam );
   }
   else
      return( ::_voiinskreiz() );
}
