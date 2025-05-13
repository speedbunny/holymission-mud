// Mangla:    changed the query_short to return 1 if not mage.  eliminated . in look
#define E environment

inherit "obj/thing";

object destination;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("Swirling portal leading to another realm");
  set_alias("portal");
  set_short("Swirling portal leading to another realm");
}

query_show_short() { return 1; }

init() {
  ::init();
  if(this_player()->query_guild()==5)
      add_action("enter","enter");
}

enter(arg) {
  if(!destination) dest();
  if(id(arg)) {
    write("You enter the portal and leave to another realm.\n");
    this_player()->move_player("into the portal",destination);
    return 1;
  }
}

get() { return 0; }

long() {
  write("Behind the swirling portal you can see...\n\n");
  if(destination->test_dark() || this_player()->infravision())
  {
     this_player()->mylook(0,destination);
  } else write("It's pitch black!\n");
}

set_portal(dest) {
  catch(call_other(dest,"???"));
  destination=find_object(dest);
  if(!destination)
  {
      destruct(this_object());
      return -1;
  }
  tell_room(environment(this_object()),
      "A swirling portal appears in a bright flash of light.\n");
  return destination;
}

no_clean_up() { return 1; }

dest() {
  tell_room(environment(this_object()),short()+" vanishes.\n");
  destruct(this_object());
  return 1;
}

dump() { return destination; }

short()
{
    if(this_player() && this_player()->query_guild()!=5) return 0;
    return ::short();
}

query_name()
{
    if(this_player() && this_player()->query_guild()!=5) return "";
    return ::query_name();
}

id(s)
{
    if(this_player() && this_player()->query_guild()!=5) return 0;
    return ::id(s);
}
