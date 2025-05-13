

inherit "room/room";
object o1,o2,o3;

reset(arg) {
if (!o1) {o1=clone_object("players/warlord/rooms/skele1");move_object(o1,this_object());}
if (!o2) {o2=clone_object("players/warlord/rooms/skele1");move_object(o2,this_object());}
if (!o3) {o3=clone_object("players/warlord/rooms/skele1");move_object(o3,this_object());}
    if (arg) return;

    set_light(1);
    short_desc = "A room";
    no_castle_flag = 0;
    long_desc = 
        "This room has a bunch of skeletons chained to the walls. You can barely\n"
       + "get through them. They look very angry too.\n";
    dest_dir = 
        ({
        "players/warlord/rooms/skel1","east",
        });
  items=({
  "chains","These are very rusty chains",
      });
}

monster_died(ob1) {
long_desc="The room contains a lot of broken skeletons chained to the wall\n";
return 1;
}
