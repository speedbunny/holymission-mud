#define FILENAME "/players/baer/wring:"
id (str)    { return str=="ring"; }

short ()   {
    return "Silver Ring (worn)"; }

long ()    { write ("An unjunkable ring!\n");}

init () {
    add_action ("f",        "find");  add_action ("ring_baer",        "r");
}
get ()   { return 1; }
drop ()  { return 1; }
query_auto_load ()   { return FILENAME; }

find (target) {
    object obj;
    int i;
    if (!target) { write ("You find nothing.\n"); return 1; }
    obj=find_living(target);
    if (!obj) { write ("Unable to find " + target + ".\n"); return 1; }
    obj=environment(obj);
    if (!obj) { write (target + " has no environment. \n"); return 1; }
    write ("\n     " + file_name (obj) + "\n");
    obj->long();
    obj=all_inventory(obj);
    write ("\n     " + sizeof(obj) + " objects in that room.\n\n");
    for (i=0;i<sizeof(obj);i++)
	if (obj[i]->short())
	    write (ladjust (i+1,5) + obj[i]->short() + ".\n");
    return 1;
}

int ring_baer(string arg)
{
   object mob;

    if (!arg) 
    {
        notify_fail("Ering what ?\n"); 
        return 0;
    }
    if (this_player()->query_real_name()=="widge")
        mob = find_living("baer");

    if (!mob)
    {
       notify_fail("Baer isn't here :(\n");
       return 0;
    }
    tell_object(mob,"[*] "+capitalize(this_player()->query_real_name())+ 
                    "[*] +"+arg+"\n");
    write("Ok.\n");
    return 1;
}

         
        
