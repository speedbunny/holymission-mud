inherit "obj/weapon";

reset(arg){
 
if(arg) return;

    set_name("unicorn horn");
    set_alt_name("horn");
    set_alias("slayer");
    set_class(12);
    set_weight(2);
    set_value(250);
    set_short("A unicorn horn");
    set_long("A long slender horn of a unicorn.\n");    
    set_hit_func(this_object());
   return 1; 
	}

weapon_hit(attacker){

 if(attacker-> query_race()=="duegar") {
	write("The unicorn horn pulses in your hand.\n");
	return 30; 
	}
     return 0;
	}
query_quest_obj(){ return 1; }
