#define FILENAME "/players/jug/obj/wiztool:"

init() {
	add_action("goto_jug", "goto");
	add_action("inventory", "I");
	add_action("clone_obj", "clone");
	add_action("dest_tool", "dest");
	add_action("help", "help");
}

long() {
	write("It is transparent.\n");
}

get() { return 1; }
        
drop() { return 1;}

id(str) { return str == "wiztool"; }

query_auto_load() {
	return FILENAME;
}

goto_jug(str) {
	if (str == "jug")
		this_player()->move_player("#/players/jug/workroom");
	else if (str[0] == '/')
		this_player()->move_player("#" + str);
	else
		this_player()->teleport(str);
	return 1;
}

Fail(str) {
  write("Couldn't find '" + str + "'.\n");
  return 1;
}

inventory(str) {
  object ob, where;
  int n;
  
  if (str)
		where = find_ob(str);
  else
	where = this_player();
  if (!where) {
	Fail(str);
	return 1;
	}
  write_inv_ob(where);
  return 1;
}

write_inv_ob(obj) {
  object ob;
  int n;
  
  ob = first_inventory(obj);
  write("Inventory of ");
  write_ob_and_desc(obj);
  while(ob) {
    write(" " + n + ": ");
	write_ob_and_desc(ob);
    n += 1;
    ob = next_inventory(ob);
	}
  write("That's all.\n");
  return 1;
}

write_ob_and_desc(obj) {
  string str;
  
  if(!obj)
	return 0;
  write(obj);
  write(" <-> ");
  str = call_other(obj,"short",0);
  if (!str)
	str = obj->query_name();
  if(!str)
	str = "Invisible object.";
  write(str + "\n");
  return 1;
}

find_ob(str) {
	return(search_all(str));
}
 
search_all(str) {
  object ob, fob;
  
  if(!str) return 0;
  
  fob = this_player();
  if(!ob) ob = present(str, fob);
  if(!ob) ob = present(str, environment(fob));
  if(!ob) ob = find_object(str);
  if(!ob) ob = find_living(str);
  if(!ob) ob = find_living("ghost of " + str);
  return ob;
}

clone_obj(str)
{
	object ob;
	
    ob = clone_object(str);
    move_object(ob, this_player());
    return 1;
}

dest_tool(str)
{
	object ob;
	
	ob = find_ob(str);
	if (!ob) {
		write(str + " not found.\n");
		return 1;
		}
	if (ob == this_object())
	    write("Oh no, why does you destruct me ...\n");
	else {
		write("Destructing:\n  ");
        write_ob_and_desc(ob);
        }
    destruct(ob);
    return 1;
}

help(str) {
	if (!str || !id(str))
		return 0;
	write("Wiztool commands:\n");
	write("goto player/obj   ...   teleports you to player/obj\n");
	write("I [player/obj]    ...   enchanted inventory of player/obj\n");
	write("\nA new tool from Jug !!!\n");
}
