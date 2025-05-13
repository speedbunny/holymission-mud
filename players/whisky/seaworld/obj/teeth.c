inherit "/obj/weapon";


reset(arg) {
  ::reset(arg);
  if(!arg) { 
    set_name("teeth");
    set_class(8);
    set_alias("sharks teeth");
    set_short("A sharks teeth");
    set_long("The teeth of the dangerous shark.\n");
    set_value(1000);
    set_weight(2);
    set_hit_func(this_object());
  }
 }

  weapon_hit(attacker)
{
                              
    write("You bare your teeth and massacre "+attacker->query_name()+" to hash HACK HACK.\n");
    say(this_player()->query_name()+" bares the teeth and massacres "+attacker->query_name()+" to hash.\n");

   if (attacker->query_race()=="fish")
   {
      return random(60);
    }
   else 
     return 0;
  }

/* Non metal, Ethereal Cashimor */

query_non_metal() {
  return 1;
}
