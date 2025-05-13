#define NAME "sarge"
#define TP this_player()
#define TPN this_player()->query_real_name()
#define CNAME   capitalize(NAME)
inherit "obj/treasure";
int shield;

reset(arg) {
if (arg) return;

  set_id("shield");
  set_alias("shield");
  set_weight(0);
  set_value(1);
  set_short("A portable shield");
   set_long("This is a portable shield to keep people out of a room.\n");
}
init() {
    ::init();
    add_action("set_shield", "shield");
    check();{
    if(!TP->short())
        TP->vis();
        }
}
set_shield(str) {
    if(TPN!="sarge") {return;}
    if (!str) {
        write("Shield is set to "+shield+".\n");
        return 1;
    }
    if(str=="on") {
        write("You raise the shields.\n");
        say("Sarge raises the shields.\n");
        shield=1;
        return 1;
    }
    if(str=="off") {
        write("You power down the shield.\n");
        say("Sarge powers down the shield.\n");
        shield=0;
        return 1;
    }
    write("Set shield to what?\n");
    return 1;
}
check(){
    if(shield && !present("pass",TP)) {
        write("Sarge does not wish you to enter at this time.\n");
        say(this_player()->query_name()+" tries to enter but is kicked out.\n");
        move_object(this_player(), "/room/church");
    }
}
