inherit "obj/armour";
void reset(int arg){
  ::reset();

    set_name("crown");
    set_alias("kings crown");
    set_short("King's Crown");
    set_long(
"This crown is made of pure gold.  There are three diamonds pieced "+
"together to form a triangle in the center.  Several other jewels "+
"and semi-precious stones are artfully arranged around it.\n");
    set_value(5000);
    set_weight(1);
    set_type("helmet");
    set_ac(2);
  }
