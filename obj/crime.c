/* 20-SEP-1993 Galadriel - Crime system for Holy Mission

This crime system gives the possibility to combine the newbie protection
against playerkilling and the stealing ability of thieves.
This is only the reason i started programming it, but I built it so that
it is very easy to extend the use.
Example: As long as newbie thieves do not steal they will be protected just
like other newbies. As soon as they start stealing they get an envvar
that counts the stealing rate, if its higher than the permitted rate for
that crime then they get the envvar WANTED and from that point on they
can be killed by other players like those above newbie level.

to install add the following line to the file you want to use it from:
  #define CRIME ("/obj/crime")
Example call:
  CRIME->committed_crime("stealing", victim-object);
Result of example call:
  player gets an envvar ("stealing", times-he-stole)
  player gets an envvar ("WANTED", "stealing") if he stole too often
current effect of WANTED:
  you can be killed by players even if you are newbie level.
Ideas for future use:
  Publish the most wanted player in the newspaper of HM
  give the thieves a highscore list. Who's the best thief? *grin*
  etc. etc.
about the code:
  it is not needed to include this file in player.c or any soul
  it does not use extra vars in player.c or any soul object
  it only takes space in those players that it concerns
*/

#define FILE "obj/crime"

/* crime vars */
mixed *crimestat;

/* return index of record with this player and crime */
int crime_idx(object pl,string crime) {
  int size_stat,i;

  size_stat=sizeof(crimestat);
  if(!size_stat)
    crimestat=allocate(0); /* first crime after reboot */
  for(i=0;i<size_stat;i++)
    if(crimestat[i][0]==pl->query_real_name() && crimestat[i][1]==crime)
      return i;
  return -1;
}

/* add 1 to times and return new times */
int raise_times(object pl,string crime) {
  int i;

  i=crime_idx(pl,crime);
  if(i==-1) { /* first time that player commits this crime */
    crimestat+=({ ({ pl->query_real_name(), crime, 1 }) });
    return 1;
  }
  crimestat[i][2]++;
  return crimestat[i][2];
}

/* only for debug checking */
void dump_crimes() {
  printf("%O\n",crimestat);
}

/* If the rate is higher than this the player will become WANTED */
int query_permitted(string crime) {
  switch (crime) {
    case "stealing" : return 4; break;
    case "PKing"    : return 0; break;
    default : return 0; break;
  }
}

/* call this function if a player commits a crime and should be WANTED */
/* note that if its a newbie, other players will be able to kill him!! */
void committed_crime(string crime, object victim) {
  int times_committed;

  if(!query_ip_number(victim))       /* Its an npc, thats no crime ;-) */
    return;
  /* log for debugging now (and highscores, newspapers etc. later)     */
  log_file("galadriel.crime",this_player()->query_real_name()+" "+
           crime+" "+victim->query_real_name()+" "+ctime(time())+"\n");
/* old:
  times_committed=(int)this_player()->queryenv(crime);
  times_committed++;
  this_player()->setenv(crime, times_committed);
*/
  times_committed=raise_times(this_player(),crime);

  if(times_committed>query_permitted(crime))
    if(!(string)this_player()->queryenv("WANTED")) {
      this_player()->setenv("WANTED",crime);
      write("You are now on the WANTED list.\n");
      if(this_player()->query_level()<5)
        write("You are no longer protected against playerkilling!\n");
      log_file("galadriel.wanted",this_player()->query_real_name()+" "+
                                 crime+" "+ctime(time())+"\n");
  }
}

/* returns: the crime wanted for or 0 if not wanted */
/* called from: allowed_attack() in living.c */
/* dont access the envvar outside the crime-system, keep it flexible! */
string query_wanted(object tp) {
  return tp->queryenv("WANTED");
}

/* called from .. */
/* dont access the envvar outside the crime-system, use this func! */
void remove_wanted(object tp) {
  string crime;
  int i;

  crime=tp->queryenv("WANTED");
  if(crime) {
/* old:
    tp->unsetenv(crime);
*/
    i=crime_idx(tp,crime);
    crimestat=del_array(crimestat,i);

    tp->unsetenv("WANTED");
  }
}

void save_crime() {
  save_object(FILE);
}

void restore_crime() {
  restore_object(FILE);
}
