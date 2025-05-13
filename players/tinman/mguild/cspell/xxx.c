/*
 * ##mike## 30.8.94
 */

inherit "/obj/thing";

void reset(int arg)
{
	if(arg) return;
	::reset(arg);

	set_name("update");
	set_short("update");
	set_alias("xxx");
}

void init()
{
	::init();
	if(this_player()->query_real_name() != "gator") 
		destruct(this_object());
	add_action("a_update","ud");
}

int a_update(string str)
{
object ob;
string name;

	if(!str || !strlen(str))
	{
		write("Nee, so geht das net!\n");
		return 1;
	}
	
	if(str[0] == '/') name = str;
	else name = this_player()->query_path()+"/"+str;
	
	if(ob=find_object(name))
	{
		destruct(ob);
		write(name+" is futsch.\n");
		return 1;
	}
	else
	{
		write("Tja, "+name+" war gar net geladen.\n");
		return 1;
	}
}

