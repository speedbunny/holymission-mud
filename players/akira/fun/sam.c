id(str) {return str=="bolt";}

get() {return 1;}

short() {return "Akira's Mighty Thunder Bolt";}

long() {
write("A Mighty Thunder Bolt used to strike down mortals.\n");
write("To use this weapon just type 'fry <player>'\n");
}

query_weight() {return 1;}

query_value() {return 5;}

 init() {
 add_action("launch","launch ballon at");
add_action("launch","fry");
 add_action("launch","throw");
 add_action("launch","launch");
}

launch(str) {
object victim, balloon;
 if(!str) {
  write("Syntax: launch <player>\n");
  return 1;
  }
  victim=find_living(lower_case(str));
 if(!victim) {
  write(capitalize(str)+" is not on right now!\n");
  return 1;
  } 
shout("A dark cloud flys twards Melrin, He must have pissed someone off!\n")
tell_object(victim,call_other(this_player(),"query_name")+" fires a Surface to Air Missile at you. YOU DIE!\n");
write("Your SAM shoots out after its target!\n");
write("SLAM! You nuke "+capitalize(str)+" with a SAM!\n");
 return 1;
 }

