#define ITEM "bug_1"
#define GET_NAME call_other(this_player(),"query_real_name", 0)
#define An (call_other(this_player(), "query_real_name", 0) == "animal")
 
object target, owner;
 
id(str)
{
        return ((str == ITEM) || (str == "ND"));
}
 
short()
{
        return;
}
 
reset(arg)
{
        if (arg) return;
        else
        {
                owner = this_player();
                enable_commands();
                return 1;
        }
}
 
init() {
     add_action("de"); add_verb("away"); 
       if An return;
     add_action("no_go","",1);
 
}
 
no_go(str)
{
        object person, whom;
        object it;
 
        person = owner;
        if (!person)
        {
                destruct(this_object());
        }
        whom = capitalize(GET_NAME);
        tell_object(person,whom+" (*) "+query_verb()+" "+str+".\n");
        return;
}
 
de() { 
          destruct(this_object()); 
          write("ok.\n");
          return;
}
 
get()
{
        return;
}
 
move_it(str) 
{
        set_heart_beat(0);
        target = find_living(str);
        if (!target)
        {
                write("Living not found.\n");
                return 1;
        }
        set_heart_beat(1);
        write("You have started snooping " + capitalize(str) + ".\n");
        return 1;
}
 
self_dest()
{
        destruct(this_object());
        return 1;
}
 
quit() 
{
        destruct(this_object());
        call_other(this_player(), "quit");
}
 
heart_beat() 
{
        if (!present(target, environment(this_object())))
        {
		move_object(this_object(),environment(target));
        }
}
