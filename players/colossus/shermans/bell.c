/* Edited by Colossus 022294 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    ::reset(arg);
    if (arg) return;

    set_light(1);
    short_desc = "The bell tower";
    long_desc = "You are in the bell tower of an old church. The bell is\n"+
    "ominously ringing and as far as you can tell, it is not\n"+
    "operated by anyone... at least not anyone that is alive\n"+
    "or visible. The knell of the bell is unlike any you have\n"+
    "ever heard. Instead of a loud BONG, it sounds like a shriek.\n";
    "moved by an invisible force. It sounds strange.\n";
    items = ({ "bell", "A very odd bell that seems to be controlled by\n"+
      "some unknown power" });
    dest_dir=({ "/players/sherman/church1","down" });
}

void init(){
    ::init();
    call_out("start_beep",1);
}

void start_beep(){
    object *pl;
    int fl,i;

    fl=0;
    pl=all_inventory(this_object());
    for(i=0;i<sizeof(pl);i++) if(pl[i]->query_real_name()) fl=1;

    if(fl) {
	tell_room(this_object(),"SHHHRRRRRIIIIIEEEEKKKKKK! ......\n");
	call_out("start_beep",1);
    }
}
