inherit "obj/weapon";

reset(arg){

  ::reset(arg);
  if(!arg) {  
    set_name("goblet");
    set_short("A jeweled goblet");
    set_long("A jeweled goblet filled with poisonous wine.  It is made from soild gold and\n"+
               "has jewels encrusted in it.\n");
    set_class(13);
    set_weight(3);
    set_value(5200);
  }
}
