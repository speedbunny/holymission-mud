
/* The Ring Of Crom */

inherit "/obj/armour";
#include "/spells/spell.h"

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_name("Ring of Crom");
        set_alias("ring");
        set_short(query_name());
        set_type("ring");
        set_long( 
        "This is the Mighty Ring of the God Crom, father of the Barbarians.\n"+
        "The ring looks to be a simple gold band, but it almost seems to\n"+
        "hum with power. Legends say that this ring will grant its wielder\n"+
        "protection from the spells of the practicers of magic. You know it\n"+
        "would not be wise to try to wear this ring if you are not a member\n"+
        "of the Barbarian Horde.\n");
        set_ac(1);
        set_weight(5); /* only the strong may wear this */
        set_value(4000);
        modify_resistance(FIRE,50);
        modify_resistance(MAGIC,50);
        modify_resistance(COLD,50);
        modify_resistance(ILLUSION,50);
        modify_resistance(POISON,50);
        modify_resistance(TOUCH,50);
        modify_resistance(ENERGY,50);
modify_stat(4, -2);
modify_stat(3, -2);
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
