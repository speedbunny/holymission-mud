drop() { return 0; }
 
get() { return 1; }
 
id(str) { return str == "book" || str == "manual" || str == "instructions"; }
 
init() {
    add_action("read","read");
    add_action("drop_object","drop");
}
 
long() {
    write("Your pet can do the following things:\n\n"+
          "-- name <name>\n"+
          "-- setin <msg>\n"+
          "-- setout <msg>\n"+
          "-- sic <monster>\n"+
          "-- torment <monster>\n"+
          "-- chew corpse\n"+
          "-- stay\n"+
          "-- heel\n\n"+
          "Name will rename your pet,\n"+
          "Setin will change the msg seen when yer pet arrives,\n"+
          "Setout will change the msg seen when yer pet leaves,\n"+
          "Sic forces your pet to attack <monster>,\n"+
          "Torment forces yor pet to growl at <monster>,\n"+
          "Chew corpse will heal your pet,\n"+
          "Stay will make your pet stay in that room, and warn you\n"+
	  "if anyone should enter it,\n"+
          "Heel will call your pet to your side, and stop any fights.\n\n"+
          "Note:  Netdeath will NOT affect your pet, but quitting will.\n");
          return 1;
}
 
query_value() { return 1; }
 
read(str) { 
    if (id(str)) long(); return 1; }
 
short() { return "Instructions for using pets"; }


drop_object(str) {
    if (str == "all") {
        drop_object("instructions");
        return;
    }
    if (!str || !id(str)) return 0;
	write("The instructions self-destructs!\n");
    destruct(this_object());
    return 1;
}
