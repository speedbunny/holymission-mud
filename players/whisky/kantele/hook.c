
/* collar */

inherit "/obj/armour";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        set_name("spiked collar");
        set_alias("collar");
        set_short(query_name());
        set_type("neck");
        set_long( 
        "A black leather collar, full with sharp steel spikes.\n"+
        "It is enveloped in a bright green, magical aura.\n");
        set_ac(1);
        set_weight(1);
        set_value(1500);
      }    
}
 
int query_mage_wear() { return 1; }
int query_monk_wear() { return 1; }
int query_ninja_wear() { return 1; }
