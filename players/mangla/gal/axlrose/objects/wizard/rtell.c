/* Meecham's Room Emoter */
/* Axlrose - Edit */
inherit "obj/treasure";

query_auto_load() { return "/players/axlrose/objects/wizard/rtell:"; }
// drop() { return 1; }
reset(arg)
{
    if(arg) return;
    set_name("room emoter");
}

init()
{
    ::init();
    add_action("esay","esay");
}

esay(str)
{
    if(!str) return 0;
    tell_room(environment(this_player()),str+"\n");
    return 1;
}

check_tell(str)
{
    object person,ob;
    string msg;
    sscanf(str,"%s %s",person,msg);
    ob=find_player(person);
    if(!ob) return 0;
    else return 0;
}

// Mangla trying to remove an error that appears every time loaded.
drop() {
  destruct(this_object());
  return 1;
}
