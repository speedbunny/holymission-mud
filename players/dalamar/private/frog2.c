inherit "obj/treasure";

object plyr;

reset (arg) {
if (arg) return;

    set_short(0);
   set_alias("echoer");
   set_long("A room echoer.\n");
   set_value(0);
   set_weight(0);
}
init() {
      add_action("recho","roomecho");
      ::init();
      }
recho(str)
    { say(str+"\n");write("You room echo: "+str+"\n");return 1;}
query_auto_load() { return "/players/dalamar/private/frog2.c:"; }
drop() {return 1;}
