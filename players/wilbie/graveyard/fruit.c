inherit "obj/food";
 
void reset(int arg) {
  ::reset(arg);
  if(arg) return;
 
  set_name("fruit");

  set_strength(30);
  set_value(60);
  set_eater_mess("It tastes better than you'd expect!\n");
  set_eating_mess(" eats some strange looking fruit.\n");
  set_short("Some strange fruit");
  set_long("A piece of strange looking fruit.\n");
  set_weight(1);
}
