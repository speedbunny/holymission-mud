inherit "room/room";
reset(arg) {
    set_light(1);
short_desc="Lieutenant's office";
long_desc=
"You are in the office of the police lieutenant.  It is rather open\n"+
"for a police commander's office you think.  The door to the south\n"+
"is open and there are stairs leading up to another floor running\n"+
"the west wall.  Furnishings in this room include two chairs and a \n"+
"desk seated behind which is the lieutenant.\n";
    dest_dir=({
               "players/kelly/rooms/vill/wardrobe","up",
               "players/kelly/rooms/vill/police_office","south",
             });
    items=({
	"chairs","A couple of plain chairs with padding on the seats",
	"desk","The desk has piles of papers all over it and is a mess",
            "stairs","Simple stairs",
            "door","A wooden door",
          });
    clone_list = ({ 1, 1, "man", "obj/monster",
			({ "set_name","lieutenant",
                          "set_alt_name", "policeman",
                          "set_alias", "man",
                          "set_race", "human",
                          "set_level", 19,
			  "set_short","The police lieutenant",
                          "set_al", 150,
                          "set_aggressive", 0,
                          "set_size", 3,
                          "add_money", 150,
                          "set_ac", 5,
                          "set_wc", 10,
                          }),
                   -1, 1, "sword", "obj/weapon",
                       ({ "set_name", "sword",
                          "set_short", "A shortsword",
                          "set_long", "A sharp shortsword.\n",
                          "set_wc", 15,
                          "set_weight", 3,
                          "set_value", 500}),
                });
    ::reset();
    replace_program("room/room");
}
