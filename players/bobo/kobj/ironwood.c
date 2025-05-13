inherit "obj/weapon";

int power;
 
reset(arg) {
 set_name("ironwood staff");
 set_alias("staff");
 set_class(16);
 set_weight(3);
 set_value(6250);
 set_short("An ironwood staff");
 set_long("It's made of ironwood, which is very hard. There are some letter on it.\n"); 
 set_read("These are old forgotten runes, you can't read them.\n");
 set_hit_func(this_object());
 power=15;
}
 
weapon_hit(attacker) {
  power --;
  if(power>0) {
    write("The staff jerks like a snake in your hand.\n");
    return 50;
  }
  if(power==0) 
    write("The staff has lost its power and dies.\n");
  if(power<0) {
    write("The staff falls off to some rubble.\n");
    wielded_by->stop_wielding("staff");
    destruct(this_object());
  } 
}
