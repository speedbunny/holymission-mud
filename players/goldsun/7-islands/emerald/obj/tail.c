inherit "/obj/weapon";

void reset(int i){
 ::reset(i);
 if (i) return;
 set_name("tail");
 set_short("A tail");
 set_long("A tail from raccoon. This is not good weapon.\n");
 set_class(5);
 set_weight(1);
 set_value(45);
}
