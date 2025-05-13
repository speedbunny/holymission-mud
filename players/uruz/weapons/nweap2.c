#define TP             (this_player())
#define OWNERS         "/players/patience/guild/nweap/weap_owners"

inherit "/players/patience/guild/nweap/genNinWeap";
#include "/players/patience/guild/nweap/nweap_mess.h"

int is_allowed( object who );

int heal, removep;

reset(arg)
{
   heal = 1;
   removep = 5;

   ::reset(arg);

   if (arg) return;

   set_name( "unbelieveable sharp katana" );
   set_alias( "healer" );
   set_short( "An unbelieveable sharp katana" );
   set_long( 
       "An unbelieveable sharp katana. Its blade is covered with ancient,\n"+
       "nihonese runes and the hilt is made of 'zoge'. Connected to the\n"+
       "end of the hilt is a diamond and the blade glows faintly blue.\n" );
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

   add_action( "do_remove", "remove" );
   add_action( "do_heal", "heal" );
}

int wield( string arg )
{
   if ( !arg || !present( arg, this_player() ) || arg != "healer" ) return( 0 );

   if ( !is_allowed(TP) ) {
      write( "The katana refuses to be wielded by you !\n" );
      return( 1 );
   }
   if ( TP->query_wielded(0) ) {
      write( "The katana refuses to be wielded in the off-hand !\n" );
      return( 1 );
   }

   modify_resistance( 2,  TP->query_legend_level()/2 );
   modify_resistance( 7, TP->query_legend_level()/2 );
   modify_resistance( 11,  TP->query_legend_level()/2 );
   modify_immunity( 8, TP->query_legend_level()/4 );

   modify_stat( 3, 5 );
   modify_stat( 4, 3 );

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
   if ( who->query_real_name() == "prince" || who->query_immortal() )
      return( 1 );

   return( 0 );
}

int do_heal( string arg )
{
   int val;

   if ( !arg || arg != "me" ) return( 0 );

   if ( !wielded_by ) return( 0 );

   if ( heal <= 0 ) {
      write( "Nothing happens...\n" );
      return( 1 );
   }
   heal--;

   val = random( 200 ) + 100;
   if ( TP->query_hp() + val > TP->query_max_hp() )
      val = TP->query_max_hp() - TP->query_hp();

   TP->reduce_hit_point( -1 * val );
   write( "You feel life floating back to your obdy.\n" );

   return( 1 );
}

int do_remove( string arg )
{
   if ( !arg || arg != "poison" ) return( 0 );

   if ( !wielded_by ) return( 0 );

   if ( removep <= 0 ) {
      write( "Nothing happens.\n" );
      return( 1 );
   }
   removep--;

   TP->add_poison( -1 * TP->query_poisoned() );
   write( "You feel poison leaving your veins !\n" );

   return( 1 );
}

_voiinskreiz()
{
   int ex_dam;

   if ( wielded_by && wielded_by->query_attack() &&
        (wielded_by->query_attack()->query_race() == "demon" ||
         wielded_by->query_attack()->query_race() == "ghost") )
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
