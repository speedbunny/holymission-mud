inherit "/obj/weapon";

reset(arg){

if (arg) return;

set_name("bronze chain");
set_alias("chain");
set_weight(2);
set_class(8);
set_value(2000);
set_short("A bronze chain");
set_long("This is not very long chain.\n"
   	 +"It is made from bronze.\n");
set_hit_func(this_object());
}

weapon_hit(attacker){
 if (random(5) < 1){
 write("You harm the "+attacker->query_name()+" and the chain muffles around "+
    attacker->query_pronoun()+".\n");
  attacker->hold(this_player(),random(5));
  }
  
 return random(8);
 }

