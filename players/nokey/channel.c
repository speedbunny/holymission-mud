/* Channel object for the fun channel. Coded by No Key on Holy Mission
   Started coding: 050894 */
/* 060894: Nokey: made a generic channel object out of it */
#pragma strict_types
#pragma save_types

mixed users;
string chan_name;
string online_mes;
string chan_act;

void set_chan_act(string str)
  { chan_act = str; }

void set_chan_name(string str)
  {
  chan_name = str;
  }

void tell_users(string str)
  {
  int a;
  for(a=0; a<sizeof(users); a+=2)
    if(users[a] && users[a+1])
      tell_object(users[a],str);
  }

int line(object pl, int online)
  {
  int a;
  if((a = member_array(pl,users)) == -1) return 0;
  users[a+1] = online;
  return 1;
  }

void refresh_users()
  {
  mixed tempusers;
  mixed user;
  int a;
  tempusers = ({});
  user = allocate(2);
  for(a=0; a<sizeof(users); a+=2)
    if(users[a])
      {
      user[0] = users[a];
      user[1] = users[a+1];
      tempusers = tempusers + user;
      }
  if(!tempusers) users = ({});
  else users = tempusers;
  }

varargs void add_user(object user, int online)
  {
  mixed newuser;
  if(member_array(user,users) != -1)
    return;
  newuser = allocate(2);
  newuser[0] = user;
  newuser[1] = online;
  users = users + newuser;
  }

void remove_user(object user)
  {
  int a;
  if ((a = member_array(user,users)) == -1) return;
  users[a] = 0;
  refresh_users();
  }

int list_users()
  {
  int a;
  string name;
  write(online_mes +":\n");
  for(a=0; a<sizeof(users); a+=2)
    {
    if(users[a] && interactive(users[a]))
      {
      if(!users[a+1])
        write(" OFF: ");
      else
        write("      ");
      write(capitalize((string)users[a]->query_real_name()) +"\n");
      }
    }
  return 1;
  }

int channel_it(string str)
  {
  string msg;
  if(!str) return list_users();
  if(str == "off" || str == "on")
    return line(this_player(), (str == "on"));
  msg = "["+ chan_name +"]"+
  " "+
  capitalize((string)this_player()->query_real_name()) +" ";
  if(query_verb() == chan_act)
    msg = msg + "says: ";
  msg = msg + str +"\n";
  tell_users(msg);
  return 1;
  }

void reset(int arg)
  {
  refresh_users();
  if(arg) return;
  chan_name = "!!FUN!!";
  online_mes = "Comedians online";
  chan_act = "fun";
  }
