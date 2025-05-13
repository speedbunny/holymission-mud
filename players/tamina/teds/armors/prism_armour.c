inherit "obj/armour";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

  set_name("Prismatic Armour");
  set_alias("armor");
  set_type("armour");
  set_size(0);
  set_short("Prismatic Armour");
  set_long(
"This is a fabulous set of armour, the skin of the fierce \n"+
"Prismatic Dragon, Misthena.  It wondrously reflects the five colours\n"+
"of that dragon, Red, Black, Blue, Green and White. It feels incredibly\n"+
"magical, and very protective.  Perhaps it can be identified.\n");
  set_ac(3);
  set_weight(6);
  set_value(10000);
  set_arm_light(1);
  modify_stat(2, 2);  // Con
  modify_stat(3, 3);  // Int
}

int query_mage_wear()     { return 1;  }
int query_ninja_wear()    { return 1;  }
int query_monk_wear()     { return 1;  }
int query_summoner_wear() { return 1;  }

string query_info() 
{
  return
"This is the wondrous plated armour of Misthena, the Prismatic Dragon.\n"+
"Only some of its powers can be identified, but we know that it has\n"+
"the power to enhance its wearer's abilities.\n";

}
