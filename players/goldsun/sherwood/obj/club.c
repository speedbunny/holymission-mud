inherit "obj/weapon";

reset(arg){
 ::reset(arg);
 if (arg) return;
 set_name("club");
 set_short("A highwayman's club");
 set_long("This is special club made by highwayman.\n"
          +"It is made from magic stone and alive wood.\n");
 set_value(5000);
 set_weight(5);
 set_type(3);
 set_class(16);
}

