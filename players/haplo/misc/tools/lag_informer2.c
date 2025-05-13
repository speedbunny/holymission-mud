inherit "obj/treasure";

#include "/players/sauron/std_defs.h"
int hidden;

void set_hidden(int i) {
  hidden=i;
}

int query_hidden() {
  return hidden;
}

int person_lag(string str) {
  object target;
  target=find_living(str);
  if(!str) {
    WRITE("Who do you want to inform about the lag?\n");
    return 1;
  }
  if(!target) {
    WRITE(CAP(str)+" is not playing at this time.\n");
    return 1;
  }
  WRITE("You inform "+CAP(str)+" about the lag.\n");
  TELLO(target,CNAME(TP)+" regretfully informs you that "+HE(TP)
                        +" is wallowing in lag.\n");
  return 1;
}

int room_lag(string str) {
  if(!str) {
    WRITE("You inform everyone about the lag.\n");
    SAY(CNAME(TP)+" regretfully informs everyone that "+HE(TP)
                 +" is wallowing in lag.\n");
    return 1;
  }
  WRITE("You lag "+str+".\n");
  SAY(CNAME(TP)+" lags "+str+".\n");
  return 1;
}

int person_lagless(string str) {
  object target;
  target=find_living(str);
  if(!str) {
    WRITE("Who do you want to inform about the lack of lag?\n");
    return 1;
  }
  if(!target) {
    WRITE(CAP(str)+" is not playing at this time.\n");
    return 1;
  }
  WRITE("You inform "+CAP(str)+" that you have no lag whatsoever.\n");
  TELLO(target,CNAME(TP)+" informs you that "+HE(TP)
                        +" has no lag whatsoever.\n");
  return 1;
}

int room_lagless() {
  WRITE("You inform everyone about the lack of lag.\n");
  SAY(CNAME(TP)+" informs everyone that "+HE(TP)
               +" has absolutely no lag.\n");
  return 1;
}

int person_lag_pity(string str) {
  object target;
  target=find_living(str);
  if(!str) {
    WRITE("Who do you want to take pity on for being lagged?\n");
    return 1;
  }
  if(!target) {
    WRITE(CAP(str)+" is not playing at this time.\n");
    return 1;
  }
  WRITE("You take pity on "+CAP(str)+" for being lagged.\n");
  TELLO(target,CNAME(TP)+" takes pity on you for being lagged.\n");
  return 1;
}

int hide_it(string str) {
  if(str!="informer") return 0;
  if(!present(TO,TP)) return 0;
  if(query_hidden()) {
    WRITE("It's already hidden!\n");
    return 1;
  }
  WRITE("You hide your lag informer.\n");
  SAY(CNAME(TP)+" hides "+HIS(TP)+" Lag Informer.\n");
  set_hidden(1);
  return 1;
}

int search_for_it(string str) {
  if(str!="informer") return 0;
  if(!present(TO,TP)) return 0;
  if(!query_hidden()) {
    WRITE("It wasn't hidden!\n");
    return 1;
  }
  WRITE("You find your lag informer.\n");
  SAY(CNAME(TP)+" finds "+HIS(TP)+" Lag Informer.\n");
  set_hidden(0);
  return 1;
}

int informer_activate(string str) {
  if(!str || !id(str)) {
    NF("Activate what?\n");
    return 0;
  }
  MOVEO(TO,ENV(TO));
  WRITE("Lag informer activated.\n");
  return 1;
}

string query_auto_load() {
  return MSCOBJ+"lag_informer2:";
}

int drop() {
  WRITE("The Dark Lord Sauron-sama tells you: Don't drop litter..... destruct"
       +" your Lag informer if you want to get rid of it!\n");
  return 1;
}

mixed short() {
  if(query_hidden()) return 0;
  return ::short();
}

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    set_id("informer");
    set_name("informer");
    set_alias("lag informer");
    set_alt_name("lag_informer");
    set_short(CNAME(TP)+"'s Lag Informer");
    set_long("This is an autoloading lag informer brought to you by The Dark"
            +" Lord himself.\nUse 'rlag <name>' to inform a single player, or"
            +" simply 'lag' to inform your immediate environment.\nOn the"
            +" other hand, if you have absolutely no lag whatsoever, you can"
            +" use the corresponding 'rnolag' and 'nolag' commands!\nYou can"
            +" take pity on someone else if they are lagged using 'lagpity',"
            +" and you can now hide your lag informer using the command"
            +" 'hide', and show it again by searching for it (ie."
            +" <hide/search informer>).\nUse 'activate informer' to activate"
            +" your informer in your inventory.\nIf you have any suggestions,"
            +" feel free to mail him.\n");
    set_value(0);
    set_weight(0);
    hidden=1;
  }
}

void init() {
  ::init();
  add_action("person_lag","rlag");
  add_action("room_lag","lag");
  add_action("person_lagless","rnolag");
  add_action("room_lagless","nolag");
  add_action("person_lag_pity","lagpity");
  add_action("hide_it","hide");
  add_action("search_for_it","search");
  add_action("informer_activate","activate");
}
