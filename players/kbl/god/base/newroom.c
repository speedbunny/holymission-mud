
inherit "obj/clean_up";

// Room variables
static string short_desc, *property;
static mapping dest_dir, exit_mess, items, verbs;
static mixed long_desc;
static status no_castle_flag;
static closure actions;
static string get_string(int num);
static string list_dests(status long);
static string exit_initials(string str);

status id(string str) { return (str && member(items, str)); }

void init()
{
   if (!dest_dir)
    dest_dir = ([ ]);
   if (!exit_mess)
    exit_mess = ([ ]);
   if (!items)
    items = ([ ]);
   if (!actions)
      actions = lambda(({ 'verb, 'fun }),({ #'add_action, 'fun, 'verb }));
   map_array(m_indices(dest_dir), actions, "move");
   if (verbs)
      walk_mapping(verbs, actions);
   return;
}


string short()
{
   if (!short_desc)
    return 0;
   return sprintf("%s.   %s",short_desc[<1] == '.' ? short_desc[0..<2] :
                  short_desc,list_dests(0));
}

void long(string item)
{
   int size;
   if (this_player()->test_dark() == 1)
   {
      if(set_light(0) <= 0)
         write("It is dark.\n");
      return;
   }
   if (item)
   {
      if (member(items, item) == 1)
      {
         if (closurep(items[item]))
            funcall(items[item], item);
         else if (items[item][0] == '@')
            (void)call_other(this_object(),items[item][1..], item);
         else if (items[item][0] == '=')
            long(items[item][1..]);
         else
            printf("%s\n", items[item]);
      }
   return;
   }
   size = sizeof(dest_dir);
   if (stringp(long_desc))
     write(long_desc);
   else
    if (closurep(long_desc))
      funcall(long_desc);
   printf("%-75=s\n", list_dests(1));
}

query_property(str)
{
    int i;
    if (str == 0)
        return property;
    if (!property)
        return 0;
    if (stringp(property))
        return str == property;
    while(i < sizeof(property))
    {
        if (property[i] == str)
            return 1;
        i += 1;
    }
    return 0;
}

set_property(str)
{
   if (!property)
   {
        property = ({ str });
        return;
   }
   if(member_array(str,property) == -1)
   {
      property += ({ str });
      return;
   }
   tell_room(is_object(),"Already existing property: "+str+".\n");
}

static string get_string(int numeric)
{
   string symbolic;
   switch(numeric)
   {
      case  0: symbolic = "No";    break;
      case  1: symbolic = "One";   break;
      case  2: symbolic = "Two";   break;
      case  3: symbolic = "Three"; break;
      case  4: symbolic = "Four";  break;
      case  5: symbolic = "Five";  break;
      case  6: symbolic = "Six";   break;
      case  7: symbolic = "Seven"; break;
      case  8: symbolic = "Eight"; break;
      case  9: symbolic = "Nine";  break;
      default: symbolic = "Many";  break;
   }
   return symbolic;
}

static string list_dests(status long)
{
   string *exits;
   int size;

   exits = m_indices(dest_dir);
   if (get_type_info(dest_dir, 1) >= 2)
      exits = filter_array(exits, lambda(({ 'ex, 'dest_dir }),
                  ({ #'!, ({ #'funcall,
                  ({ #'[, 'dest_dir, 'ex, 1 }), 'ex }) })), dest_dir);
   size = sizeof(exits);
   if (!size)
     return (long ? "   No obvious exits." : "[none]");
   return (long ?   sprintf("    %s obvious exit%c: %s.",
           get_string(size),size == 1 ? 0 : 's',
           implode(exits, ", ")) : sprintf("[%s]",
           implode(map_array(exits, #'exit_initials), ",")));
}

status move()
{
   string verb;
   verb = query_verb();

   (void)this_player()->remove_last_history();
   if (member(dest_dir, verb) == 1)
   {
     if (exit_mess && member(exit_mess, verb) == 1)
     {
       (void)this_player()->set_env_var("msgout", exit_mess[verb, 0]);
       (void)this_player()->set_env_var("msgin",  exit_mess[verb, 1]);
       (void)this_player()->move_player(verb, dest_dir[verb]);
       (void)this_player()->clear_attrib("msgout");
       (void)this_player()->clear_attrib("msgin");
     }
     else
       (void)this_player()->move_player(verb, dest_dir[verb]);
      return 1;
   }
   return 0;
}

status query_drop_castle() { return no_castle_flag; }

string *query_dest_dir()
{
   string *exits, *dest_dirs;
   int val, size;

   exits = m_indices(dest_dir);
   if (get_type_info(dest_dir, 1) >= 2)
      exits = filter_array(exits, lambda(({ 'exit, 'dest_dir }),
              ({ #'!,({ #'[, 'dest_dir, 'exit, 1 }) })), dest_dir);
   size = sizeof(exits);
   for(dest_dirs = ({ }), val = 0; val < size; val++)
      dest_dirs += ({ dest_dir[exits[val]], exits[val] });
   return dest_dirs;
}

mixed query_info(int arg)
{
   mixed fun_val;

   switch(arg)
   {
      case  0: fun_val = dest_dir;   break;
      case  1: fun_val = verbs;      break;
      case  2: fun_val = items;      break;
      case  4: fun_val = exit_mess;  break;
      default: fun_val = 0;          break;
   }
   if (mappingp(fun_val)) fun_val = copy_mapping(fun_val);
   return fun_val;
}

string exit_initials(string dir)
{
   switch(dir)
   {
      case "northwest": dir = "nw"; break;
      case "northeast": dir = "ne"; break;
      case "southeast": dir = "se"; break;
      case "southwest": dir = "sw"; break;
      case "north":
      case "south":
      case "west":
      case "east":
      case "up":
      case "down":
        dir = dir[0..0];
      break;
   }
   return dir;
}
