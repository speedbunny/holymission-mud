
/* keg of Rice Wine last edit: 190394  whisky uni-linz.ac.at */

inherit "/players/whisky/magic/keg"; 

#define env environment
void reset(int arg)
{
   if (arg) 
   {
    if (!objectp(env(env())))
        destruct(this_object());
     return;
    }
	  set_name("keg");
	  set_alias("cider");
	  set_short("keg of cider");
	  set_long("You see a small oak wooden keg of cider.\n");
	  set_value(200);
	  set_taps(20);
	  set_weight(2);
	  set_strength(5);
	  set_consumer_mess("You take a big tap from your keg.");
	  set_consuming_mess(" taps from a small keg.");
}

