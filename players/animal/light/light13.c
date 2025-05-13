inherit "room/room";
 
#define me capitalize(this_player()->query_real_name())
 
int i;
 
reset(arg) {
    if (arg) return;
#if 0 
    ::reset(arg);
    set_outdoors(4);
#endif
    i = 0;
    set_light(1);
    short_desc = "Stream";
    no_castle_flag = 0;
    long_desc =
        "The stream\n"
        + "\n"
        + "     You have come to a small stream in the middle\n"
        + "     of a wooded area. The stream looks quite cool \n"
        + "     and refreshing. The stream is surrounded by willow\n"
        + "     trees and you see small animals down by the stream\n"
        + "     drinking.\n"
        + "\n";
    dest_dir =
        ({
        "players/animal/light/light11", "east",
        });
     items = ({
     "stream", "The stream is more of a river, it looks fast and deep",
     });
}
 
query_long() {
    return long_desc;
}
query_outdoorness() {
    return 4;
}
query_light() {
    return 1;
}
 
init() {
     ::init();
     add_action("swim","swim");
     add_action("swim","enter");
}
 
swim(str)  {
     int m;
     string name;
     object corpse, ob;
     ob = this_player();
     if(!str) str = "stream";
     if (str == "stream" || str == "river") {
     write("You enter the cold waters of the stream.\n\n");
     say(me+" enters the stream.\n");
     write("You are trying to swim against the strong current.\n");
     write("The current is VERY strong here.\n\n");
     write("The current is TOO strong, you are pulled under the water.\n\n");
     write("You see your life flash before your eyes.\n");
     write("You start to gasp for air, you might not survive.\n\n");
     write("You 'awaken' and find yourself lying on a beach.\n\n");
     write("You have DIED! You see your corpse lying here besides you" +
           " on the beach here.\n\nIt seems you DID die, but for some"+
           " reason you are still alive! Must be a miracle\n");
    name = call_other(ob,"query_name",0);
    corpse = clone_object("obj/corpse");
    call_other(corpse, "set_name", name);
    call_other(ob,"transfer_all_to",corpse);
    m = call_other(ob,"query_money");
    call_other(ob,"add_money",-m);
    move_object(this_player(),"players/animal/evil7");
    say(name+ " comes floating down the river, DEAD!\n\n");
    say(name + " shouts: I am alive!\n");
    move_object(corpse, environment(ob));
	return 1;
    }
}
 
