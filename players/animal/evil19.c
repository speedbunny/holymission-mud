inherit "room/room";
 
reset(arg) {
    if(arg) return;
    long_desc ="Smelly room\n" +
         "\n" +
         "    You have entered a very smelly room.\n" +
         "    The floor here is covered with rotting\n" +
         "    cheese. The smell is so horrible that\n" +
         "    feel like throwing up! You notice that\n" +
         "    the cheese looks like it was left here\n" +
         "    by accident.\n" +
         "\n";
    short_desc = "A smelly room";
    dest_dir = ({
        "/players/animal/evil18", "south",
        "/players/animal/evil20", "east"
    });
    items = ({
        "cheese","This is a rotting swiss cheese full of holes\n" +
                       "One of the holes seems rather large",
        "hole","You look in a hole and see the word three inscribed"
    });
    return;
}
 
query_long() { return long_desc; }
 
query_light() {return 0; }
