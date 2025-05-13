id(str) {return str=="launcher";}

get() {return 1;}

short() {return "Drago's Water Balloon Launcher";}

long() {
 write("A slingshot-like device used to launch water balloons.\n");
 write("This device is built with an auto loader that feeds a continuous\n");
 write("supply of balloons. Just type 'launch <player>'\n");
}

query_weight() {return 1;}

query_value() {return 5;}

 init() {
 add_action("launch","launch ballon at");
 add_action("launch","launch at");
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
tell_object(victim,call_other(this_player(),"query_name")+" pegged you square in the head with a water balloon.\n"); 
write("THWAK!  The Balloon seeks out it's target.\n");
 write("SPLASH! You soak "+capitalize(str)+" with the balloon.\n");
 return 1;
 }

