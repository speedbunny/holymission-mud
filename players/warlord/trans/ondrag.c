inherit"room/room";
 reset(arg) {
 if (arg) return;
 set_light(1);
 short_desc="Inside Dragon airway.\n";
 long_desc="You are in the seating area of the Dragon Airway.\n";
 dest_dir=({
 });
 return 1;
 }
init() {
add_action("view","view");
}
view() {
int max;
string enfi, drag, it, ob;
drag = find_living("dragonair");
enfi = environment(drag);
tell_room(enfi, "The Dragon surveys its surroundings.\n");
write("You see:\n");
write(call_other(enfi, "long") + "\n");
     ob = first_inventory(enfi);
        max = 20;
        while(ob && max > 0) {
            if (ob != drag) {
                string short_str;
                short_str = call_other(ob, "short");
                if (short_str) {
                    max -= 1;
                    write(short_str + ".\n");
                    it = short_str;
                }
            }
            ob = next_inventory(ob);
        }
return 1;
}
