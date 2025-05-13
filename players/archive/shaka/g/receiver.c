string name;
object receiver; /* all catch tells are told to this (interactive) object */
id(str) { return str==name; }
short() { return name; }
get() { return 0; }
drop() { return 1; }
init() 
{
  enable_commands(); /* this should be living(for catch_tell) */
}
catch_tell(message)
{
  tell_object(receiver,"[* Shaka Talk *] "+message);
}

set_name(str) { name=str; }
set_receiver(ob) { receiver=ob; }
query_name() { return receiver->query_name(); }
query_real_name() { return name; }
