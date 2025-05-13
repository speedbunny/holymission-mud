
/* The Ring Of Crom */

inherit "/obj/armour";

#include "/spells/spell.h"

#define MR modify_resistance
#define MI modify_immunity

void reset( int flag ) {
     ::reset( flag );
     if ( flag == 0 ) {

        set_name("Ring of Crom");
        set_alias("ring");
        set_short(query_name());
        set_type("ring");
        set_long( 
        "This is the Mighty Ring of the God Crom, father of the Barbarians.\n"+
        "The ring looks to be a simple gold band, but it almost seems to\n"+
        "hum with power. Legends say that this ring will grant its wielder\n"+
        "protection from the spells of the practicers of nagic. You know it\n"+
        "would not be wise to try to wear this ring if you are not a member\n"+
        "of the Barbarian Horde.\n");

        set_ac(1);
        set_weight(5); /* only the strong may wear this */
        set_value(4000);

        MI( FIRE, 100 ); 
        MI( ELECTRICITY, 100 );
        MI( COLD, 100 ); 
        MI( ACID, 100 );  
        MI( ENERGY, 100 );
        MI( DRAIN, 100 );
        MI( TOUCH, 100 );   
        MI( PETRIFICATION, 100 );
        MI( POISON, 100 );
        MI( BREATH, 100 );
        MI( DEATHMAGIC, 100 ); 
        MI( MAGIC, 100 ); 
	MI( MINDEFFECTIVE, 100 );
        MI( ILLUSION, 100 );    
	MI( SUMMONING, 100 );

	MR( FIRE, 100 );
	MR( ELECTRICITY, 100 );
	MR( COLD, 100 );
	MR( ACID, 100 );
	MR( ENERGY, 100 );
	MR( DRAIN, 100 );
	MR( TOUCH, 100 );
	MR( PETRIFICATION, 100 );
	MR( POISON, 100 );
	MR( BREATH, 100 );
	MR( DEATHMAGIC, 100 );
	MR( MAGIC, 100 );
	MR( MINDEFFECTIVE, 100 );
	MR( ILLUSION, 100 );
	MR( SUMMONING, 100 );

	modify_stat( 4, -2 );
	modify_stat( 3, -2 );
      }    
}
 
int wear(string str) {
  if(!str || !id(str)) return 0;
if(this_player()->query_guild()==11) return ::wear (str);
  else {
write("Crom strikes you down for trying to wear his ring!\n");
this_player()->hit_player(this_player()->query_hp()-1);
    return 1;
  }
}
