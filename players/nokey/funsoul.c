/* Colossus 080994: Removed autoloading function as it was */
/* causing bugs for people trying to login. Please do not  */
/* put this bit of code on the game until you are level 33 */
/* please.                                                 */
/* 110894: Nokey: reason for bug: guild mage + funsoul do NOT mix
   it is the shadow that's put on them that messes up the call_other
   with this_player() in the init(). */
/* an object for a bit of fun */
#define MAGE 5
#pragma strict_types
#pragma save_types

int dropped;

void dest()
  {
  destruct(this_object());
  }

string query_auto_load()
  { return "/players/nokey/funsoul:"; }

int get()
  { return 1; }

int id(string str)
  { return str == "funsoul"; }

int drop()
  {
  "players/nokey/channel"->remove_user(this_player());
  "players/nokey/channel"->tell_users(
  capitalize((string)this_player()->query_real_name()) +
  " leaves the fun.\n");
  dropped = 1;
  move_object(this_object(),"players/nokey/workroom");
  call_out("dest",0);
  return 1;
  }

int fun(string str)
  {
  return (int)"players/nokey/channel"->channel_it(str);
  }

void init()
  {
  if(dropped) return;
  if((int)this_player()->query_guild() == MAGE)
    {
    write("Mages can not have a fun soul.. sorry :(\n");
    destruct(this_object());
    return;
    }
  add_action("fun","fun");
  add_action("fun","fun/");
  "players/nokey/channel"->tell_users(
  capitalize((string)this_player()->query_real_name()) +
  " joins the fun.\n");
  "players/nokey/channel"->add_user(this_player(),1);
  }

