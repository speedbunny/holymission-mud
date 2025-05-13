inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("unholy avenger");
    set_alias("avenger");
    set_short("An Unholy Avenger");
    set_long("This black blade radiates evil and glows with a black aura.\n");
    set_class(19 );
    set_value(2000);
    set_weight(4);
}

wield(arg) {
 if(!id(arg)) return; /* duh...moonchild 160793 */
 if(this_player()->query_alignment() >= -250) {
  write("You must be very evil to wield this sword.\n");
  return 1;
 } 
 if(::wield(arg)) {
  write("The unholy avenger pulses with a black radiance.\n");
 }
 return 1;
}
