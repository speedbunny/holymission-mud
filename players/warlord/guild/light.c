inherit "obj/armour";

     
reset(arg) {
  ::reset(arg);
  if (!arg) {
     set_id("light");
     set_arm_light(2);
  }
}
 drop() { return 1; } 
