inherit "room/room";
reset(arg) {
    set_light(1);
short_desc="Prison yard.";
long_desc=
"You are in the prison yard where when the policemen are feeling\n"+
"really nice they let the prisoners come out and look at the sun\n"+
"with their own eyes.  The walls here are very high and there is\n"+
"a guard here watching over everything.\n";
    dest_dir=({
	"players/bobo/krooms/vill/guardroom","east",
             });
   items=({
	   "door","A simple door with no lock",
	   "walls","Tall walls surround this area",
         });
    clone_list = ({ 1, 1, "orc", "obj/monster",
                       ({ "set_name", "policeman",
                          "set_alias", "man",
                          "set_race", "human",
                          "set_level", 10,
                          "set_hp", 150,
                          "set_short", "A policeman",
                          "set_long", "A policeman, you see nothing special about him.\n",
                          "set_al", 150,
                          "set_aggressive", 0,
                          "set_size", 3,
                          "add_money", 150,
                          "set_ac", 5,
                          "set_wc", 10 }),
                   -1, 1, "knife", "obj/weapon",
                       ({ "set_name", "club",
                          "set_short", "A club",
                          "set_long", "A wooden club. This club belongs to the Red Rock Junction\n" +
                                      "police department. It allows the policemen to stop malicious\n" +
                                      "wrong doers without killing them, often.\n",
                          "set_wc", 10,
                          "set_weight", 2,
                          "set_value", 200}),
                });
    ::reset();
    replace_program("room/room");
}
