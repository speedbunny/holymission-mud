/*  Coded by Katana of Holy Mission */
/*  Modified with permission by Jewel of Holy Mission for use 
       in her area */
/*  further modifications here please */
 
inherit "obj/weapon";
 
#define TP      (this_player())
 
id(str) {
    return(str == "clip" || str == "paperclip");
}
 
query_value()
{
    return 0;
}
 
long() {
    write("This is a small paperclip.  You could throw it at someone.\n");
}
 
reset(arg) {
    ::reset(arg);
    if (arg)
        return;
 
  set_name("paperclip");
  set_alias("clip");
  set_short("A paperclip");
  set_long("This is a special boomerang paperclip." +
           "You can throw it at someone.\n");
  set_class(1);
  set_value(0);
  set_weight(1);
}
 
wield(str)
{
  if (!str) return 0;
  if (str == "paperclip" || str == "clip" ) {
    write( "You can throw this paperclip, but not wield it.\n" );
    return(1);
  }
  return(0);
}
 
throw(str)
{
    object target;
    if (!str) return 0;
 
    target = present( str, environment(TP) );
    if (!target) {
      write( "There is no " + str + " in this room.\n");
      return(1);
    }
 
    write("You throw the paperclip at " + target->query_name() + "!\n" +
          "The paperclip bops "+ target->query_objective() +
          " on the head, bounces, " +
          "and returns to you.\n");
 
    say(TP->query_name() + " throws a paperclip at " + 
        target->query_name() + 
        "!\nThe paperclip bops " + target->query_objective() +
           " on the head, bounces, and " +
        "returns to its owner.\n"
        , target);
 
    tell_object(target, TP->query_name() + " nails you with a PAPERCLIP!!\n");
 
    return 1;
}
 
init() {
    add_action("throw", "throw");
}
 
get() {
    return 1;
}

