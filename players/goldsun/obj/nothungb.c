/*      magic weapon for the best adventurers
     This weapon contains from 2 parts     (now) 
     which you have to join
*/

inherit "/obj/weapon";
                       
reset(arg) {
if (arg) return;

    set_name("Nothung");
    set_short("The Ancient Nothung");
    set_alt_name("nothung");
    set_long("This is the lost Goldsun's sword. It seems to be common sword \n"+
             " but it is not true.\n");
    set_value(30000);
    set_weight(5);
    set_type(3);
    set_class(5);
    set_hit_func(this_object());
    set_light(1); 
 }
 
 weapon_hit(attacker){
  if (random(20) < (this_player()->query_chr()/10 +7)  ) 
   {
       write("A shine lightning bolt smashes "+attacker->query_name()+
                 " to the small peaces.\n");
       say("\nYou are blinded by the lightning from the "+
                  this_player()->query_name()+"'s Nothung !!!\n\n");
       if (attacker->id("dragon")) return (27 + random(40));
        else return 17+random(11); 
   } else return 13+random(7);
   
  }

query_quest_item(){ return 1;}

