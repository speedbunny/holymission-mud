#define TP      this_player()

compare(str) {
  string wp1,wp2;
  object ob1,ob2;
  int w1,w2;
  if(!str) {
	notify_fail("What do you wish to compare?\n");
	return 0;
  }
  if(TP->query_level() < 8) {
	write("You ponder over the two items but cannot come to any conclusion.\n");
	return 1;}
  if(TP->query_spell_points() < 20) {
	write("You try to make the comparision but your mind feels weak and confused.\n");
	return 1;
	}
  if(sscanf(str,"%s to %s",wp1,wp2) !=2)  {
    notify_fail("You must do `compare <item1> to <item2>`.\n");
    return 0;
  }
  if (!present(wp1,TP) || !present(wp2,TP)) {
  write("You don't have those items.\n");
  return 1;
  }
  ob1 = present(wp1,TP);
  ob2 = present(wp2,TP);
  if(ob1->query_weapon()) {
      if(ob2->query_armour()) {
          write("Both items have to be of the same kind! (weapon or armour)\n");
          return 1;
      } else if(!ob2->query_weapon()) {
          write("You are only able to compare armours or weapons!\n");
          return 1;
      } else {
          w1=ob1->weapon_class();
          w2=ob2->weapon_class();
      }
  } else {
      if(ob2->query_weapon()) {
          write("Both items have to be of the same kind! (weapon or armour)\n");
          return 1;
      } else if(!ob2->query_armour()) {
          write("You are only able to compare armours or weapons!\n");
          return 1;
      } else {
          w1=ob1->armour_class();
          w2=ob2->armour_class();
      }
  }
  if(w1-w2>0)
      write("Your fighters mind favours the "+wp1+".\n");
  else if(w1-w2<0)
      write("Your fighters mind favours the "+wp2+".\n");
  else
      write("Your fighters mind decides they are equal.\n");
  TP->restore_spell_point(-20);
  return 1;
}
