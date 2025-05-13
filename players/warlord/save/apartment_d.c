/*
	Apartment daemon for Tear
	by Kriton@Emerald MUD
*/

#include "apartment.h"

inherit "std/daemon";

class apartment_rec ap;
mapping loaded;
mapping roomservice;

private void init_defaults();
class apartment_rec load_apartment(string);
void save_apartment(string, class apartment_rec);
int has_apartment(string);
private void load_clones();
private void load_roomservice();

void create()
{
  daemon::create();
  init_defaults();
  loaded = ([]);
  roomservice = ([]);
  load_clones();
  load_roomservice();
}

private void init_defaults()
{
  ap = new(class apartment_rec);
  ap->long = "This is the default long description for your room at the Inn.\n"
             "You can get help on how to change this description by typing\n"
             "<help inn>.";
  ap->short = "Room at the Emerald MUD Inn";
  ap->indoors = 1;
  ap->light = 2;
  ap->sounds = ([]);
  ap->smells = ([]);
  ap->items = ([]);
  ap->guests = ({});
  ap->objects = ([]);
  ap->storage = ([]);
  ap->rent_due = time();
}

private void load_roomservice()
{
  string tmp, *line;
  
  foreach(tmp in read_database(RSERVICE_FILE))
  {
    if(sizeof(line = explode(tmp, ":")) != 4) continue;
    if(!atoi(line[3])) continue;
    roomservice[ line[0] ] = ([ "ids":explode(line[1], ","), "file":line[2],
      "cost":atoi(line[3]) ]);
  }
}

class apartment_rec load_apartment(string who)
{
  if( !who ) return 0;
  if( who == "--default--" || !file_exists(savefile(who)))
  {
    init_defaults();
    who = (who == "--default--" ? who : convert_name(who));
    ap->owner = who;
    ap->rent_due = time();
    if(file_size(savedir(who)) != -2) mkdir(savedir(who));
    write_file(savefile(who), save_variable(ap), 1);
    return ap;
  }
  ap = restore_variable(read_file(savefile(who)));
  return ap;
}

void save_apartment(string who, class apartment_rec rec)
{
  if( !who || !rec) return;
  if(sscanf(base_name(previous_object()), __DIR__ "%*s") != 1) return;
  write_file(savefile(who), save_variable(rec), 1);
}

int has_apartment(string who)
{
  return (file_exists(savefile(who)));
}

private load_clones()
{
  object obj;
  
  foreach(obj in children(APARTMENT ".c"))
  {
    if(!obj->query_owner()) continue;
    loaded[obj->query_owner()] = obj;
  }
}

mixed find_apartment(string who)
{
  object obj;
  
  if(!who) return 0;
  if(!has_apartment(who = convert_name(who))) return -1;
  load_apartment(who);
  if(ap->rent_due <= time()) return -2;
  if(!undefinedp(loaded[who]) && objectp(loaded[who])) return loaded[who];
  obj = new(APARTMENT);
  obj->load_apartment( ap );
  obj->load_objects();
  loaded[who] = obj;
  return obj;
}

/*
	add_action's hooked from the apartment room
*/
int add_guest(string str)
{
  if(!str)
    return notify_fail("Add who as a guest?\n");
  if(!user_exists(str = convert_name(str)))
    return notify_fail("No such player exists by that name.\n");
  ap = previous_object()->query_data();
  if(getuid(this_player()) != ap->owner)
    return notify_fail("Only the owner can add guests to the list.\n");
  if(member_array(str, ap->guests) != -1)
    return notify_fail("That person is already on your guest list.\n");
  if(str == getuid(this_player()))
    return notify_fail("You cannot add yourself to your own guest list.\n");
  ap->guests += ({ str });
  write("Guest added to list.");
  previous_object()->pass_data( ap );
  save_apartment(getuid(this_player()), ap);
  return 1;
}

int del_guest(string str)
{
  if(!str)
    return notify_fail("Remove who from the guest list?\n");
  ap = previous_object()->query_data();
  if(getuid(this_player()) != ap->owner)
    return notify_fail("Only the owner may remove names from the guest list.\n");
  if(member_array(str = convert_name(str), ap->guests) == -1)
    return notify_fail("That person is not even on the guest list.\n");
  ap->guests -= ({ str });
  write("Guest removed from list.");
  save_apartment(getuid(this_player()), ap);
  previous_object()->pass_data( ap );
  return 1;
}

int list_storage()
{
  ap = previous_object()->query_data();
  write("Items in your storage compartment:\n" +
        implode(keys(ap->storage), "\n") +
        "\n\nNames on your guest list:\n"+
        format_page(ap->guests, 4));
  return 1;
}

int room_service(string str)
{
  string *m;
  int which;
  object ob;
  
  if(!str) return notify_fail("Usage: service [help | list | buy <item>]\n");
  if(str == "help")
  {
    write(
      "Room Service Help File:\n\n"
      "Command:            Description:\n"
      "service help        Gives you this help file.\n"
      "service list        Gives you a list of items you can order.\n"
      "service buy <item>  Order an <item> to be delivered to your room,\n"
      "                    where item is something available through the\n"
      "                    <service list> command.");
    return 1;
  }
  if(str == "list")
  {
    string tmp;
    
    write("The following items are available through room service:");
    printf("%-50sCost:\n", "Item:");
    write("=============================================================");
    foreach(tmp in keys(roomservice))
      write(sprintf("%-50s%d gold", tmp, roomservice[tmp]["cost"]));
    return 1;
  }
  if(sscanf(str, "buy %s", str) != 1)
    return notify_fail("Usage: service [help | list | buy <item>]\n");
  if(sscanf(str, "%*s %*d") == 2) sscanf(str, "%s %d", str, which);
  m = filter_array(keys(roomservice), "filter_matches", this_object(), str);
  if(sizeof(m) == 0)
    return notify_fail("Room service does not offer that.  Please check the list.\n");
  if(which)
  {
    if(--which < 0 || which >= sizeof(m))
      return notify_fail("Room service does not offer that.  "
      "Please check the list.\n");
    str = m[which];
  } else str = m[0];
  if(roomservice[str]["cost"] > (int)this_player()->query_money())
    return notify_fail("You cannot afford that!\n");
  if(!file_exists(__DIR__ "service/" + roomservice[str]["file"] + ".c") ||
    catch(ob = new(__DIR__ "service/" + roomservice[str]["file"])))
    return notify_fail("The kitchen was unable to locate that.  Tell Kriton.\n");
  tell_room(previous_object(), this_player()->query_cap_name()+" orders "
    "something from room service and moments later there is a knocking at "
    "the door.  "+this_player()->query_cap_name()+" answers the door and "
    "returns shortly after.", ({ this_player() }));
  this_player()->add_money(-roomservice[str]["cost"]);
  write("Room service arrives promptly with your order.");
  if(!this_player()->can_carry(ob))
  {
    write("The "+ob->query_short()+" is too heavy, causing you to drop it.");
    ob->move(previous_object());
  } else ob->move(this_player());    
  return 1;
}

int filter_matches(string x, string y)
{
  if(lower_case(x) == lower_case(y)) return 1;
    else return (member_array(lower_case(y), roomservice[x]["ids"]) != -1);
}

int store_item(string str)
{
  object obj, tmp;
  string fn;
  int x;
  
  if( !str ) return notify_fail("Store what?\n");
  if( !(obj = parse_objects(this_player(), str)) )
    return notify_fail("You do not have that.\n");
  ap = previous_object()->query_data();
  if(getuid(this_player()) != ap->owner)
    return notify_fail("You cannot store stuff in another person's room.\n");
  if(sizeof(ap->storage) >= (x = this_player()->query_level()/5 + 4))
    return notify_fail("Your storage is full.  At your level you are only "
    "allowed to store "+x+" items.\n");
  if(catch(tmp = load_object(fn = base_name(obj))))
    return notify_fail("This item could not be re-loaded.  It cannot be stored.\n");
  if(tmp->query_short() != obj->query_short() || obj->query("NoStore") ||
     obj->query_auto_load() || obj->is_artifact())
    return notify_fail("This item cannot be stored here.\n");
  if(!undefinedp(ap->storage[ obj->query_short() ]))
    return notify_fail("You already have one of those in storage, sorry.\n");
  ap->storage[ obj->query_short() ] = fn;
  previous_object()->pass_data( ap );
  save_apartment(getuid(this_player()), ap);
  obj->remove();
  write("Item is now in storage.");
  return 1;
}

int retieve_item(string str)
{
  object obj;
  string tmp;
  int which, i = 0;
  
  if( !str ) return notify_fail("Retrieve what from storage?\n");
  ap = previous_object()->query_data();
  if(getuid(this_player()) != ap->owner)
    return notify_fail("Only the owner may access the storage area.\n");
  if(sscanf(str, "%*s %*d") == 2) sscanf(str, "%s %d", str, which);
  foreach(tmp in keys(ap->storage))
  {
  if(catch(obj = new(ap->storage[tmp])) || !objectp(obj))
    {
      map_delete(ap->storage, tmp);
      previous_object()->pass_data(getuid(this_player()), ap);
      save_apartment(getuid(this_player()), ap);
      continue;
    }
    if(!obj->id(str)) continue;
    if(!which || (which && ++i == which))
    {
      say(this_player()->query_cap_name()+" takes something out of storage.");
      write("You take " + obj->query_short() + " out of storage.");
      if(!this_player()->can_carry(obj))
      {
        write("You cannot carry it, however, and are forced to drop it.");
        obj->move(previous_object());
      } else obj->move(this_player());
      map_delete(ap->storage, tmp);
      previous_object()->pass_data( ap );
      save_apartment(getuid(this_player()), ap);
      return 1;
    }
  } /* foreach */
  write("The item you requested did not seem to be in storage.");
  return 1;
}

int edit_room(string str)
{
  object obj;
  
  if(str != "room") return notify_fail("Edit what?\n");
  ap = previous_object()->query_data();
  if(getuid(this_player()) != ap->owner)
    return notify_fail("Only the owner may use the edit command.\n");
  if(in_input(this_player()) || stringp(in_edit(this_player())))
    return notify_fail("You cannot use the editor while in input or edit.\n");
  if(objectp(obj = present("ap_edit", this_player()))) obj->remove();
  obj = new(A_EDITOR);
  obj->setup(getuid(this_player()), ap, previous_object());
  obj->move(this_player());
  return 1;
}
