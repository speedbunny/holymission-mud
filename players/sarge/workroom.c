#define NAME "sarge"
#define CNAME   capitalize(NAME)
inherit "room/room";
object tracer;
object box;

reset(arg) {
    if(!arg) {
        set_light(1);
        if(!tracer){
        tracer=clone_object("obj/trace");
        move_object(tracer,this_object());
        }
        if(!box){
        box=clone_object("players/moonchild/misc/singer");
        move_object(box,this_object());
        }
        short_desc=CNAME + "'s workroom",
        long_desc=
            "This is the workroom of "+CNAME+".\n" +
            "It looks empty ...\n";

        dest_dir=({
           "players/sarge/rooms/room1","quest",
           "players/sarge/bros/room1_a_1.c","quest2",
            "room/church", "church",
           "players/sarge/testroom.c", "test"
                 });

        items=({ 
            "air","It's very thin up here",
            "floor","The floor is dirty",
 });
     }
}
init() {
   ::init();
        add_action("get","get");
        }
get(str){
        if(this_player()->query_real_name()!="sarge"){
        return 1;
        }
}
