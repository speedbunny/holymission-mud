death_shout() {
 
  object us;
  int im,ti;
   string str;
   int rnum;

	rnum = random(100);
 
  us = users();
  im = 0;

	if(rnum < 10) str = cap_name+" got wiped out by "+
		attacker_ob->short();
	if(rnum < 25) str = cap_name+" was eaten alive by "+
		attacker_ob->short();
	if(rnum < 35) str = cap_name+" lost a battle with "+
		attacker_ob->short();
	if(rnum >= 35) str = cap_name+" was killed by "+
		attacker_ob->short();
 
  while(im < sizeof(us))
    {
      if(us[im]->query_level() < 10001
		&& !us[im]->query_muffled() && !in_editor(us[im])) {
          if(str && us[im] != this_object())
            {
 tell_object(us[im], "\n"+ str +".\n> ");
            }
	}
        im += 1;
  } 
  return;
}
