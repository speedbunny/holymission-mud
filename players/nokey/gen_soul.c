/* Generic soul to work with the generic channel.
   coded by Nokey on Holy Mission 070894 */
#pragma strict_types
#pragma save_types

#define WIZ "nokey"
/*the wizard who owns this channel*/
#define AUTOL "/players/nokey/gen_soul:"
/*filename of this object for autoload*/
#define ID "gen_soul"
/*the id of the soul for the driver*/
#define CHAN "/players/nokey/channel"
/*filename of the channel daemon*/
#define JOINM " enters the channel.\n"
/*message sent to the users of the channel when a new user enters the channel*/
#define LEAVEM " leaves the channel.\n"
/*message when user leaves the channel*/
#define ACT "chan"
/*the action to use the channel*/

int dropped;

void dest()
  {
  destruct(this_object());
  }

string query_auto_load()
  {
  return AUTOL;
  }

int get()
  { return 1; }

int id(string str)
  { return str == ID; }

int drop()
  {
  CHAN->remove_user(this_player());
  CHAN->tell_user(
  capitalize((string)this_player()->query_real_name()) +
  LEAVEM);
  dropped = 1;
  move_object(this_object(),"players/"+ WIZ +"/workroom");
  call_out("dest",0);
  return 1;
  }

int fun(string str)
  {
  return (int)CHAN->channel_it(str);
  }

void init()
  {
  if(dropped) return;
  add_action("fun",ACT);
  add_action("fun",ACT +"/");
  CHAN->tell_users(
  capitalize((string)this_player()->query_real_name()) +
  JOINM);
  CHAN->add_user(this_player(),1);
  }

