#define ENV	environment

but(int bash,*no_but) {
  string str1,xmsg;
  object att,helmet,tp;
  int level,lev;

  tp=this_player();
  att = tp->query_attack();
  level = tp->query_level();
  lev = (level/2 + 15);

  if(tp->query_ghost()) {
      write("Your immaterial head is useless!\n");
      return ({-1});
  }
  if(bash) { write("You dont have the self control to bash and but at the same time.\n");
		return ({-1});
		}
/* 920122 now we HAVE to use helmets -- LLort */
  if(!(helmet=tp->query_armour()[tp->query_arm_types("helmet")])) {
      write("You need a helmet to do that!\n");
      return ({-1});
  }

/*  920914 capa    head but funktioniert auch in no_fight area        */
  str1 = ENV(tp)->query_property();
  if(ENV(tp)->query_property("no_fight")) {
    ENV(tp)->try_attack(att);
    return ({-1});
  }
/* to quick butts can hurt ;-)                        */
  if(no_but) {
   if(random(2)) {
      write("Ouch, that was to early! You hurt yourself!\n");
      tp->reduce_hit_point(random(4)-helmet->armour_class());
   } else write ("You have to wait a while !\n");
   return ({-1});
  }

  if ((att) && (ENV(tp)==ENV(att)) && (living(att))) {
   if (random((30-level)*20) < 1) {
       xmsg="VICIOUS HIT !!\n";
    lev = lev + level * 20;
    } else xmsg="";
    xmsg+="You smash your head in the opponents face.\n";

    return ({lev,xmsg,att});
  }
  write("You are not fighting!\n");
  return ({-1});
}
