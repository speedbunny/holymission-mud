inherit "obj/weapon"; 

reset(arg) {  
  ::reset();  
  if(arg) return;  
  set_name("longsword");  
  set_alias("sword");  
  set_alt_name("sword");  
  set_short("Just an ordinary sword, or so it appears.");  
  set_long("This is an ordinary looking sword but you feel there\n"+
           "is something special about it.\n");  
  set_class(15);  
  set_weight(4);  
  set_value(10000);  
  set_hit_func(this_object());  
}  

weapon_hit(attacker) {  
  if(attacker->id("darth vader")) {  
    if(random(40)) {  
      write("The sword buries itself into Darth.\n");  
      return 5 + random(11);  
    } 
