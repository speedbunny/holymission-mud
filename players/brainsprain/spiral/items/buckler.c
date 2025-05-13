inherit "obj/armour";
void reset(int arg) {
  ::reset(arg);

    set_name("buckler");
    set_alias("buckler");
    set_short("A Steel Buckler");
    set_long(
"  A medium size shield, made of stainless steel.  In the center of the\n"+
"  shield someone has painted an eagle with an ebony staff in its mouth\n"+
"  The edges of the shield are covered with razor sharp spikes.\n");
    set_value(150);
    set_weight(3);
    set_type("shield");
    set_ac(3);
  }
