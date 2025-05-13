inherit "room/room";

#define TP this_player()
#define MO move_player

int PATH;

int _decoy() {

    write("You are blocked by the bushes and trees.\n");
    return 1;
}

int _hide_exit() {

    if (PATH) {
        write("You creep through the passage in the bushes.\n");
	TP->MO("through the bushes#/players/bobo/krooms/swamps/grass1");
    }
    else
        write("You are blocked by the bushes.\n");
    return 1;
}


int _hide_exit2(string str) {

    if(str != "bushes" && str != "bush" &&
       str != "west bushes" && str != "west bush") return 0;
    write("You find a passage west through the bushes.\n");
    PATH = 1;
    return 1;
}


void reset(int arg) {

    if (arg) return;
    PATH = 0;
    set_light(1);
    short_desc="A clearing in Mythwood";
    long_desc="You are standing in a clearing of the Mythwood forest.\n" +
              "The clearing stretches out to the east and west, but to the\n" +
              "north and west it semms an impenetrable forest lined with\n" +
              "bushes and trees.\n";

    dest_dir=({
		"players/bobo/krooms/mythwood/clear2","south",
		"players/bobo/krooms/mythwood/clear4","east",
		"players/bobo/krooms/mythwood/clear1","southeast",
             });
    items = ({ "bush","Many green bushes that appear to conceal things",
               "bushes","Many green bushes that appear to conceal things",
               "tree","Tall and forbidding. You have no hope of passing it",
               "trees","Tall and forbidding. You have no hope of passing them",
            });

    clone_list = ({ 1, 1, "troll", "players/kelly/monster/brownie",
                                ({ "set_name",  "troll",
                                   "set_race",  "troll",
                                   "set_short", "A troll",
                                   "set_long",  "This is one of the rare Mythwood trolls.\n",
                                   "set_level",      8,
                                   "set_size",       4,
                                   "set_hp",         120,
                                   "set_ac",         10,
                                   "set_wc",         12,
                                   "set_al",         -60,
                                   "set_aggressive", 1,
                                }),

                    -1, 1, "boots", "obj/armour",
                                ({  "set_name",   "boots",
                                    "set_alias",  "troll boots",
                                    "set_size",   4,
                                    "set_type",   "boot/leg",
                                    "set_weight", 2,
                                    "set_ac",     1,
                                    "set_value",  300,
                                    "set_short",  "Large troll boots",
                                    "set_long",   "A litte bit smelly, but nevertheless a good armour.\n",
                                 }),

                    -1, 1, "glove", "obj/armour",
                                 ({ "set_name",   "glove",
                                    "set_short",  "Troll gloves",
                                    "set_long",   "A pair of tough leather gloves from a troll.\n",
                                    "set_type",   "glove",
                                    "set_ac",     1,
                                    "set_size",   4,
                                    "set_value",  250,
                                    "set_weight", 1,
                                 }),

                 });

}

void init() {
    ::init();
    add_action("_hide_exit","west");
    add_action("_hide_exit2","search");
    add_action("_decoy","north");
    add_action("_decoy","northwest");
}


