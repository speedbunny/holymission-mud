inherit "obj/thing";

reset(arg) {
    ::reset(arg);
    if(!arg){
	set_name("piece");
	set_weight(1);
	set_value(100);
	set_alt_name("silver");
	set_alias("silver piece");
	set_short("Piece of silver");
    set_long("A piece of silver\n"+
    "it looks like a part of a cross\n");
	  "The letters are drawn on it in an old way.\n"+
	  "You can't read them yet.\n");
	set_can_get(1);
	set_read("You cannot read the letters.\n");
    }
}
