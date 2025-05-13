inherit "room/room";
 
reset(arg) {
    if (arg) return;
#if 0
    set_outdoors(0);
#endif
    set_light(0);
    short_desc = "The Hag's Lab";
    no_castle_flag = 0;
    long_desc = "Lab\n\n" +
        "   This is where the old hag makes strange things. Beakers\n"
      + "   and broken bottles are strewn all over the room. You\n"
      + "   wonder what the old hag was creating before she was killed.\n\n";
    dest_dir =
        ({
        "/players/animal/evil6", "up",
        });
}
 
query_long() {
    return long_desc;
}
 
query_light() {
    return 0;
}
 
clear() {
        object ob, o, n;
                 ob = this_object();
                n = first_inventory(ob);
        while(n) {
                o = next_inventory(n);
                if (query_ip_number(n)) {
                        n = o;
                        continue;
                        }
               destruct(n);
                n = o;
                }
        return 1;
}
