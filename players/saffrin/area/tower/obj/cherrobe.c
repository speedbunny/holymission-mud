inherit "obj/armour";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

  set_name("Mage-Master Robe");
  set_alias("robe");
  set_type("armor");
  set_size("any");
  set_short("Mage-Master Robe");
  set_long(
      "This is a the dark green robe of the Mage-Master Cherlindrea.  "+
      "There is a strange power that emits from the material of the robe.  "+
      "It is made from moldivite, a powerful meteorite.  "+
      "It glows with a soft green hue.\n");
  set_ac(1);
  set_weight(6);
  set_value(10000);
  set_arm_light(1);
  modify_stat(2, 3);  // Con
  modify_stat(3, 2);  // Int
}

int query_mage_wear() { return 1; }
