#include "/players/tatsuo/guild/ndef.h"
#include "/players/tatsuo/guild/nmess.h"
int hit_dam;
int stars;
object who;

main( arg )
{

  if(environment(TP)->query_property("no_fight")){
  return printf("This is not a place of violence.\n"),1;
 }
   
     

     stars = random(TPL/3)+1;
   hit_dam = FIREDAM; 
   
   
   
   if ( arg )
      who = present( arg, environment( this_player() ) );
   else
      who = this_player()->query_attack();

    if (TP->query_sp() < FIRE_COST )
   {
      write( "You are too low in power to cast this spell.\n" );
      return( 1 );
   }

 
   if (present("heart_beat",TP))
   {
       write("You are just preparing your attack.\n");
       return 1;
   }
   if ( !who || !living( who ) || environment(who)!=environment(TP) ) {
     write("You cannot fireshuriken someone, who isn't here or who is dead!\n");
      return( 1 );
   }

       
   if ( random( 100+ 20) > SHADOWMAGIC ) {  /* better fail chance */
      write( "You cannot concentrate enough to cast a fireshuriken ...\n");
      return( 1 ); 
   }

   write( "You point with your hand at " + who->query_name() + ".\n" +
         "Suddenly the air around your hand begins to glow and\n"+stars+
         " fireshuriken go flying forth from your hand towards your opponent !!!\n");
     if(TP->query_immortal()){ write("Firedamage: "+FIREDAM+"\n"); }
   tell_object( who, TP->query_name()+" shoots a fireshuriken at you !!!\n" );
say( TPN+ " summons forth "+stars+" firshuriken towards "+who->query_name()+
        ".\n", who );

        CalcDam(who, who->query_name(),hit_dam);
   if (who->query_race()=="troll")    /* trolls suffer double fire dam */
   {
       hit_dam = hit_dam * 2;
       who->hit_player(hit_dam,5);
    }
   else
     who->hit_player(hit_dam);


   move_object(clone_object("/players/tatsuo/guild/sorcerer_spells/heart_beat"), TP);
   TP->restore_spell_points( - FIRE_COST );
   
   return( 1 );
}
 



