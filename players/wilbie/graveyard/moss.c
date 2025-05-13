inherit "obj/food";
 
void reset(int arg) {
  ::reset(arg);
  if(arg) return;
 
  set_name("moss");

  set_strength(5);
  set_value(15);
  set_eater_mess("It tastes better than you'd expect!\n");
  set_eating_mess(" eats some weird green moss.\n");
  set_short("Some green moss");
  set_long("A small amount of weird green moss.\n");
  set_weight(1);
}
