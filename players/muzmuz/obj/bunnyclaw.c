inherit "obj/weapon";

reset(arg) {
  if(arg) return;
     set_name ("Bunny Claw");
     set_alias("claw");
     set_short("Bunny Claw");
       set_long("A claw of a bunny. It looks nice, but it can be used as weapon.\n");
     set_class(5);
     set_weight(3);
     set_value(300);


}
init() {
  ::init() ;

}
