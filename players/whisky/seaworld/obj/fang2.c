inherit "/obj/treasure";
object feind;
  /* (c) Whisky*/
  reset(arg) {
    if (arg) return 1;
    set_id("fang");
    set_alias("stone-fish fang");
   set_short("A stone-fish fang");
    set_value(100); /*wer den verkauft ist selber schuld */
    set_weight(1);
    set_long("This is the stone-fish fang of the dangerous\n"+
              "stone-fish, but its also a good weapon against\n"+
          "your enemies. Just type <stinger> to do\n"+
            "bad damage to your opponent. And remember, it's\n"+
           "only for a single use.\n");

   return 1; }

 init() {
   ::init();
    add_action("stinger","stinger");
       }
stinger(feind) {
if (feind == present(environment(this_player())){
  write("As you stick the dangerous fang into "+feind->query_name()+"\n"+
       feind->query_name()+" growls from pain.\n");

 say(this_player()->query_name()+" stingers "+feind->query_name()+" to death.\n");
 call_other(feind, "hit_player", 100);
   destruct(this_object());
  return 1; }
else {
 write("You aren't hunted by anybody.\n");
return 1; }
}
