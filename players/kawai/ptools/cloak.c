inherit "obj/armour";
#include <lw.h>

int cloaked;
object mycloak;

int id(string str)
  {return str=="cloak"||str=="armour"||str=="armor"||str=="dark_cloak";}

void reset(int arg)
  {::reset(arg);
  if(!arg)
    {set_short("A dark velvet cloak");
    set_long("The cloak is made of a fine, dark purple velvet.  A small note "+
    "is fixed to the inside.\n");
    set_name("a dark velvet cloak");
    cloaked=0;
    set_type("cloak");}}

void init()
  {::init();
  add_action("read","read");
  add_action("cloak","cloak");
  add_action("uncloak","uncloak");
  add_action("ctalk","say");
  add_action("ctalk","'");}

status ctalk(string str)
  {if(!mycloak)
    {return 0;}
  tell_room(mycloak,"A voice from the shadows says: "+str+"\n");
  return 1;}

status cloak()
  {if(!query_worn())
    {write("Unfortunately you're not wearing the velvet cloak.\n");
    return 1;}
  if(cloaked)
    {write("You're already cloaked!\n");
    return 1;}
  cloaked=1;
  write("You disappear into the shadows...\n");
  tell_room(environment(this_player()),capitalize(this_player()->query_name())+
  " disappears into the shadows...\n");
  mycloak=clone_object("players/kawai/ptools/cloakobj");
  transfer(mycloak,environment(this_player()));
  mycloak->set_p(this_player());
  transfer(this_player(),"players/kawai/ptools/cloakroom");
  return 1;}

status uncloak()
  {if(!query_worn())
    {write("Unfortunately, you're not wearing the velvet cloak.\n");
    return 1;}
  if(!cloaked)
    {write("You're not cloaked!\n");
    return 1;}
  cloaked=0;
  write("You step out of the shadows...\n");
  transfer(this_player(),environment(mycloak));
  destruct(mycloak);
  tell_room(environment(this_player()),capitalize(this_player()->query_name())+
  " steps out of the shadows...\n");
  return 1;}

status read(string str)
  {if(!str)
    {return 0;}
  if(str=="cloak"||str=="velvet cloak"||str=="note")
    {writelw("Greetings Traveler!  I see you've found my cloak!  Well, 'tis a simple "+
    "device.  To hide in the shadows, protected from harm, simply utter the "+
    "command 'cloak', and 'uncloak' to return to the world around you.\n");
    write("                                           -Zoggo the Alchemist\n");
    return 1;}
  return 0;}
