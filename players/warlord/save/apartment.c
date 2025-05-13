/*
	Apartment Object for Tear
	by Kriton@Emerald MUD
*/

#include "apartment.h"

inherit ROOM;

class apartment_rec ap;

void create()
{
  room::create();
  set_short("Apartment in Tear");
  set_properties(([ "light":2, "indoors":1, "free autoload":1 ]));
  set_long(
  "This is a generic apartment.  Please type <help apartment> for details\n"
  "on how to change this description."
  );
  set_no_clean(1);
}

void load_apartment(class apartment_rec tmp)
{
  string str;
  
  ap = tmp;
 
  set_short(ap->short);
  set_long(ap->long);
  set_properties(([ "indoors":ap->indoors, "light":ap->light ]));
  set_exits(([ "out" : __DIR__ "entrance" ]));
  set_items( ap->items );
  set_property("free autoload", 1);
}

string query_smell(string str)
{
  if( !str ) str = "default";
  return (undefinedp(ap->smells[str]) ? 0 : ap->smells[str]);
}

string query_listen(string str)
{
  if( !str ) str = "default";
  return (undefinedp(ap->sounds[str]) ? 0 : ap->sounds[str]);
}

void load_objects()
{
  string tmp;
  int i;
  
  foreach(tmp in keys(ap->objects))
  {
    i = ap->objects[tmp];
    while(i--) new(ap->objects[tmp])->move(this_object());
  } /* foreach */
}

int has_access(string who)
{
  if( !who ) return 0;
  who = convert_name( who );
  if(ap->owner == who) return 1;
    else return (member_array(who, ap->guests) != -1);
}

void init()
{
  room::init();
  if(!has_access( getuid(this_player()) ) && !archp(this_player()))
  {
    write("You are not allowed inside that room without permission!");
    tell_room(this_object(), capitalize(getuid(this_player()))+
      " tried to enter the room but was denied access.", ({ this_player() }));
    this_player()->move((objectp(this_player()->query_last_location()) ?
      this_player()->query_last_location() : "/d/tear/square"));
    return;
  }
  add_action((: call_other, APARTMENT_D, "edit_room" :), "edit");
  add_action((: call_other, APARTMENT_D, "room_service" :), "service");
  add_action((: call_other, APARTMENT_D, "list_storage" :), "list");
  add_action((: call_other, APARTMENT_D, "store_item" :), "store");
  add_action((: call_other, APARTMENT_D, "retieve_item" :), "retrieve");
  add_action((: call_other, APARTMENT_D, "add_guest" :), "addg");
  add_action((: call_other, APARTMENT_D, "del_guest" :), "delg");
  add_action(
    function(string str)
    {
      if(str != "inn") return 0;
      if(in_input(this_player()))
        return notify_fail("You cannot enter more while in input mode.\n");
      this_player()->more(__DIR__ "apartment.txt", "my_action");
      return 1;
    }, "help");
}

string query_owner()
{
  return (ap ? ap->owner : 0);
}

class apartment_rec query_data()
{
  return ap;
}

void pass_data(class apartment_rec tmp)
{
  ap = tmp;
}

int clean_up()  {  return 0;  }
