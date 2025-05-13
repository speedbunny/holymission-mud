/* soul for the samurai wizard channel */
/*version 2.1*/
#pragma strict_types
#pragma save_types

int dropped;

void dest()
  {
  destruct(this_object());
  }

string query_auto_load()
  {
  return "/players/tatsuo/sam_wiz_soul:";
  }

int get()
  { return 1; }

int id(string str)
  { return str == "samwizsoul"; }

int drop()
  {
  "players/tatsuo/sam_wiz_chan"->remove_user(this_player());
  "players/tatsuo/sam_wiz_chan"->tell_users(
  capitalize((string)this_player()->query_real_name()) +
  " leaves the samurai-wizard channel.\n");
  dropped = 1;
  move_object(this_object(),"players/tatsuo/workroom");
  call_out("dest",0);
  return 1;
  }

int fun(string str)
  {
  return (int)"players/tatsuo/sam_wiz_chan"->channel_it(str);
  }

void init()
  {
  if(dropped) return;
  add_action("fun","samwiz");
  add_action("fun","samwiz/");
  "players/tatsuo/sam_wiz_chan"->tell_users(
  capitalize((string)this_player()->query_real_name()) +
  " joins the samurai-wizard channel.\n");
  "players/tatsuo/sam_wiz_chan"->add_user(this_player(),1);
  }

