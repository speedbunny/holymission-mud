inherit "obj/armour";
void reset(int arg){
  ::reset();

    set_name("shield");
    set_alias("shield");
    set_short("Soldier's Shield");
    set_long(
"This shield is composed of a piece of leather stetched over a wooden "+
"frame.  Metal covers the leather in a spiderweb fashion, strengthening "+
"the shield.  The edge of the shield is covered with shards if metal.\n");
    set_value(150);
    set_weight(2);
    set_type("shield");
    set_ac(2);
  }
