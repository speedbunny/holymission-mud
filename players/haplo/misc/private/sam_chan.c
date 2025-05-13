#define ANC_ROOM "/players/haplo/guild/ancest"
#pragma strict types

inherit "/players/tatsuo/channel";

int number_of_listeners()
  {
  int a;
  if(!sizeof(users)) return 0;
  for(a=0; a<sizeof(users); a+=2)
    if(users[a] && users[a+1] && interactive(users[a]))
      return 1;
  return 0;
  }

void reset(int arg)
  {
  ::reset(arg);
  if(arg) return;
  chan_name = "samwiz";
   chan_act = "samwiz";
  online_mes = "Samurai wizards online";
  }

void notify(string str)
  {
  string msg;
  if(!str || str == "off" || str == "on") return;
  msg ="One of the ancestors ";
  if (query_verb() == "samwiz")
    msg = msg + "says: ";
  msg = msg + str +"\n";
  tell_room(ANC_ROOM,msg);
  }

int channel_it(string str)
  {
  notify(str);
  return ::channel_it(str);
  }
