inherit "obj/weapon";

reset(arg) {
   
   if(arg) return;
      set_name("Tooth");
      set_alias("tooth");
      set_short("Guineapig-Tooth");
      set_long("A tiny tooth of a guineapig, but can cause severe damage.\n");
      set_class(5);
      set_weight(3);
      set_value(150);


}
init() {
  ::init();

}
