inherit "obj/weapon";

void reset(int i){
 ::reset(i);

 if (i) return;
 set_name("trout bone");
 set_alias("bone");
 set_short("Trout bone");
 set_long("A bone from river trout.\n");
 set_class(10);
 set_value(500);
 set_weight(2);
}
