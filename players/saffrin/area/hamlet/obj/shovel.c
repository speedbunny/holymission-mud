inherit "obj/weapon";

reset(arg){

  ::reset(arg);
  if(!arg) {
     set_name("shovel");
     set_short("A shovel");       
     set_long("This is a shovel with a long wooden handle.  Its bottem is made from iron that is\n"+
                "slightly rusted.\n");
     set_class(5);
     set_weight(1);
     set_value(2000);
  }
}
