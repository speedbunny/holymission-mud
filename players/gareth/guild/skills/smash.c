#include "/players/gareth/define.h"

smash(arg) {
   int numwep;
   int i;
   object ob;
   object *wep;

  if(!arg) {
    write("whose weapon do you want to smash???\n");
    return 1;
  }

  if(TP->query_ghost()) {
    write("At this point you couldn't even break a twig!!\n");
        return 1;
  }

  if(TP->query_level() < 8) { 
        write("You don't possess this power yet.\n"); 
	return 1; 
     }

  if(TP->query_spell_points() < 35) {
        write("You're too confused to know the weak spot of the weapon.\n"); 
	return 1;
	}

  if((!(ob=present(arg,E(TP)))) || !living(ob)) {
    write("You can't do that to "+arg+".\n");
    say(TPN+" tried smash "+arg+" but failed miserably.\n");
    return 1;
  }

  wep=all_inventory(ob);
  numwep = sizeof(wep);
  for(i = 0; i < numwep; i++) {
    if(wep[i]->query_wielded()) {
      if(((random(TP->QL))+10) > (wep[i]->weapon_class()*2)) {
        ob->stop_wielding();
        destruct(wep[i]);
        say(TPN+" growls as "+TP->QO+" vicsously hits "+
          ob->query_name()+"'s weapon shattering it.\n");
        TOB(ob,TPN+" hits your weapon with such force that it shatters.\n");
        write("You destroy "+ob->query_name()+"'s weapon.\n");
        return 1;
      } else {
        say(ob->query_name()+"'s "+wep[i]->query_name()+
          " starts vibrating but it withstands the devastating blow.\n");
        TOB(ob,TPN+"tried to smash your weapon.\nThe "+wep[i]->N+
          " begins to vibrate but it whithstands the blow.\n");
        write("Ya didn't smash the weapon  - try it again!\n");
        return 1;
      }
    }
  }
  write(ob->query_name()+" is not wielding a weapon.\n");
  return 1;

  TP->restore_spell_points(-35);
  return 1;
}
