/* EARTH_GRIP.C - Programmed by Patience */
/* 280793: Ethereal Cashimor: Does only work in native environments */
#define TP     (this_player())
#define COST   (TP->query_wis())*3 / 2
#define SR     "/players/patience/skill/skill_rout"

do_earthgrip( arg )
{
   object who, obj;
   mixed  *skill;
   int    sLevel, sMaxLevel;

   skill = TP->get_skill( "earth_grip" );
   if ( !skill && !sizeof( skill ) )
      return;

   sLevel = skill[0];
   sMaxLevel = skill[1];
   if ( !sLevel || !sMaxLevel )
      return;

   if ( arg )
      who = present( arg, environment( this_player() ) );
   else
      who = this_player()->query_attack();

   if ( TP->query_sp() < COST ) {
      write( "You are too low in power to cast an earthgrip.\n" );
      return( 1 );
   }

   if ( !who || !living( who ) || environment(who)!=environment(TP) ) {
     write("You cannot cast an earthgrip at someone,\n" +
           "who isn't here or who is dead!\n");
      return( 1 );
   }
   if ( !(who->query_npc()) ) {
      write( "This spell won't work at players.\n" );
      return( 1 );
   }
  if(environment(this_player())->query_env_name()) {
    write("You can only do this if earth is near!\n");
    return 1;
  }

   if ( who->query_str() > random(sLevel) ) {
      write( "You fail to cast the earthgrip ...\n");
      return( 1 ); 
   }

   write( "You concentrate yourself to the ground surrounding your opponent.\n"+
          "Suddenly the earth around your opponent softens and quickly\n" +
          "hardens again. "+capitalize(who->query_pronoun())+
          " can't move anymore !!!\n" );
   tell_object( who, TP->query_name()+" softens the ground around you.\n" +
                "You sink into the ground and the it hardens again.\n" +
                "You cannot move anymore !!!\n" );
   say( TP->query_name() + " cast an earthgrip at " + who->query_name() +
        ".\n", who );

   if ( who->query_npc() ) {
      obj = present( "waskannom", who );
      if ( obj )
         obj->free_chance( sLevel * 2 );
      else {
         who->set_trapped( 1 );
         who->set_dex( who->query_dex()/2 ); 
         obj = clone_object( "/players/patience/guild/sorcerer_spells/wkn" );
         obj->free_chance( sLevel * 4 );
         move_object( obj, who );   
      }
   }

   TP->restore_spell_points( -1 * COST );

   SR->advance_skill( TP, "earth_grip", 1, sMaxLevel );

   return( 1 );
}
