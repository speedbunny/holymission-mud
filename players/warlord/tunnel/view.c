view() {
int max;
string enfi, tank, it, ob;
tank = find_living("panzer");
enfi = environment(tank);
tell_room(enfi, "The Panzer surveys its surroundings.\n");
write("You see:\n");
write(call_other(enfi, "long") + "\n");
     ob = first_inventory(enfi);
        max = 20;
        while(ob && max > 0) {
            if (ob != tank) {
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
