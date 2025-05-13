#define QR      "room/quest_room"

int query_quest_points();
int query_qexp();
int query_qexp_level();                 // is function-name is irritating !
int query_qexp_perc_lev();

static int quest_points;        /* calculated at login */
string quests;                  /* A list of all quests */

int query_qexp()
{
   return( query_quest_points() );
}

int query_qexp_level()                 // is function-name is irritating !
{
   int max, lev;

   max = apply( call, QR, "query_total_weight" );
   lev = level + 1;
   lev = lev > 29 ? 30 : lev;
   if ( level <= 4 ) return( 0 );
   return( lev*lev*max/900 );
}

int query_qexp_perc_lev()
{
   if ( level < 4 )
      return( 100 );
   return( (100*query_qexp()) / (query_qexp_level()+1) );
}

query_quests(str) {
    string tmp, rest, rest_tmp;
    int i;

    if (str == 0)
	return quests;
    rest = quests;
    while(rest) {
	if (str == rest)
	    return 1;
	i = sscanf(rest, "%s#%s", tmp, rest_tmp);
	if (i == 0)
	    return 0;
	if (tmp == str)
	    return 1;
	if (i == 1)
	    return 0;
	rest = rest_tmp;
    }
    return 0;
}

/* finally found a way to treat quest - cheaters */

remove_quest(arg)
{
    string *ploder;

    if (!arg && !interactive(this_player()))
	return 0;

    ploder = explode(query_quests(),"#");

    if (member_array(arg,ploder)!=-1)
    {
	ploder = ploder - ({ arg });
	quests = implode(ploder,"#");
	write("Ok removed.\n");
	tell_object(this_object(),
	  "Your "+arg+" quest was removed for cheating and is logged.\n");
	log_file("PENALTY",name +", "+ctime(time())+" by "+
	  this_player()->query_real_name()+" quest:"+arg+"#\n");
	save_me(1);
	return 1;
    }
    notify_fail("No such quest found.\n");
    return 0;
}


set_quest(q) {
    object qr,ob;

    if (!q)
	return;
    if (query_quests(q))
	return 0;
#ifdef LOG_SET_QUEST
    if (previous_object()) {
	log_file("QUESTS", name + ": " + ctime(time()) + " " + q + " from " +
	  file_name(previous_object()) + "\n");
	if (this_player() && this_player() != this_object() &&
	  query_ip_number(this_player()))
	    log_file("QUESTS", "Done by " +
	      this_player()->query_real_name() + "\n");
    }
#endif /* LOG_SET_QUEST */
    call_other(QR, "????");
    qr=find_object(QR);
    if (ob=present(q,qr)) quest_points+=ob->query_weight();
    if (quests == 0)
	quests = q;
    else
	quests = quests + "#" + q;
    save_me(1);
    return 1;
}

int query_quest_points() { return quest_points; }

    /* Calculate the quest points now */
calc_quests()
{
    if (quests) {
	object qr;

	/* 021092 Cashimor: quest_points to zero? */
	quest_points=0;
	call_other(QR, "????");
	qr=find_object(QR);      /* Supposed to be loaded */
	str=explode(quests,"#");
	for (i=0;i<sizeof(str);i++)
	    if (qr && (ob=present(str[i],qr)))
		quest_points+=ob->query_weight();
    }
}

