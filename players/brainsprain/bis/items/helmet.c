inherit "obj/armour";
void reset(int arg){
    if(arg) return;
  ::reset();

    set_name("helmet");
    set_alias("helmet");
    set_short("Soldier's Helmet");
    set_long(
"This high-domed helmet is made out of iron.  The top of the helmet is "+
"conical.  A metal plate slides up and down to cover or reveal the eyes. "+
"A chin strap hang from the left side if the helmet.\n");
    set_value(100);
    set_weight(2);
    set_type("helmet");
    set_ac(1);
  }
