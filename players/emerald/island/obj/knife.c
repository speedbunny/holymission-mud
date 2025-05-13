inherit "/obj/weapon";

void reset(int arg) {
   ::reset(arg);
   if (arg) return;
   set_name("knife");
   set_short("A gnomish knife");
   set_long("A small steel knife, of gnomish design.  It is painted in"+
            "garish colours.\n");
   set_class((8));
   set_weight(1);
   set_value(100+random(50));
   set_type(2);
}
