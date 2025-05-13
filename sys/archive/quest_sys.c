#ifndef QR
#define QR "room/quest_room"
#endif

int query_quest_points();
int query_qexp();
int query_qexp_level();
int query_qexp_perc_lev();

static int quest_points;        /* calculated at login */
mapping    quests;              /* A list of all quests */
int        cumulative_q_points;

nomask int query_cum_q_points() {
  return cumulative_q_points;
}

int query_qexp() {
  return( query_quest_points() );
}

string query_quests(string str) {

  string tmp, rest, rest_tmp, holder;
  int i;

  if (str == 0) {
    holder = implode(m_indices(quests),"#");
    return holder;
  }
  return quests[str];
}

/* finally found a way to treat quest - cheaters */

int remove_quest(string arg) {

  object qr,ob;
  int tmp, sz;

  if (!arg && !interactive(this_object()))    // TP change to TO ?????
    return 0;

  sz = m_sizeof(quests);
  quests = m_delete(quests, arg);

  if(sz != m_sizeof(quests)) {
    write("Quest " + arg + " removed.\n");
    tell_object(this_object(),
                "Your " + arg +
                " quest was removed for cheating and is logged.\n");
    log_file("PENALTY",
             this_object()->query_real_name() +", "+ctime(time())+" by "+
             this_object()->query_real_name()+" quest:"+arg+"#\n");
    call_other(QR, "????");
    qr = find_object(QR);
    tmp = 0;
    if (ob = present(arg, qr)) {
      tmp = ob->query_weight();  
      if(tmp > 0) {
        cumulative_q_points -= tmp;
        quest_points -= tmp;
      }
    }
    save_me(1);
    return 1;
  }
  notify_fail("No such quest found.\n");
  return 0;
}


int set_quest(string q) {

  object qr,ob;
  int tmp;

  if (!q)
    return 0;
  if (quests[q])
    return 0;
#ifdef LOG_SET_QUEST
  if (previous_object()) {
    log_file("QUESTS", name + ": " + ctime(time()) + " " + q + " from " +
             file_name(previous_object()) + "\n");
    if(this_player() && this_player() != this_object()
                     && query_ip_number(this_player()))
      log_file("QUESTS", "Done by " +
               this_player()->query_real_name() + "\n");
  }
#endif /* LOG_SET_QUEST */
  call_other(QR, "????");
  qr = find_object(QR);
  tmp = 0;
  if (ob = present(q, qr)) {
    tmp = ob->query_weight();  
    if(tmp)
      quest_points += tmp; 
    else tmp = -1;
  }
  quests[q] = tmp;
  if(tmp > 0)
    cumulative_q_points += tmp;
  save_me(1);
  return 1;
}

mapping quest_dump() {
  return quests;
}

int query_quest_points() {
  return quest_points;
}

    /* Calculate the quest points now */
void calc_quests() {

  int i, tmp;
  string *qids;
  object qr, ob;

  if (quests) {
    qids = m_indices(quests);
    quest_points = 0;
    call_other(QR, "????");
    qr = find_object(QR);      /* Supposed to be loaded */
    for (i = 0 ; i < sizeof(qids) ; i++) {
      if (qr && (ob = present(qids[i],qr))) {
        tmp=ob->query_weight();
        quests[qids[i]] = (!tmp ? -1 : tmp);
      }
      else
        tmp = quests[qids[i]];
      quest_points += tmp;
    }
  }
  if(!cumulative_q_points)
    cumulative_q_points = quest_points;
  return;
}

void convert_quests() {

  int w, i;
  object qr, ob;
  string *str, holder;

  if(!quests) {
    quests = ([]);
    return;
  }
  if(mappingp(quests))
    return;

  call_other(QR, "????");
  qr = find_object(QR);      /* Supposed to be loaded */
  holder = implode(m_indices(quests),"#");
  str = explode(holder,"#");
  quests = ([]);
  for (i=0;i<sizeof(str);i++) {
    if (qr && (ob=present(str[i],qr))) {
      if(w=ob->query_weight()) 
        quests[str[i]]=w;
      else
        quests[str[i]]=-1;
    }
    else quests[str[i]]=0;  // no valid quest
  }
  catch(save_me(1));
  return;
}

