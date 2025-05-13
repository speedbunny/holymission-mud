
inherit "obj/weapon";

reset(arg){
  ::reset(arg);
  if(arg) return;

  set_name("mace");
  set_class(7);
  set_value(50);
  set_weight(1);
  set_short("mace");
  set_long(
   "A flail with a small, spiked steel ball at the end of it. It appears\n"+
   "to have been used to bash in a skull recently, as the blood on the ball\n"+
   "is still warm to the touch.\n");
}
