inherit "obj/weapon";
reset(arg) {
   ::reset(arg);
   if(!arg){
   set_name("polearm");
   set_short("Halfling Polearm");
   set_long("A large heavy looking polearm with a steel spike at the end.\n");
   set_class(8);
   set_weight(3);
   set_value(250);
}
}
