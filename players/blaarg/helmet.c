inherit"obj/armour";

reset(arg) {
    ::reset(arg);
    if (arg) return;
 set_alias("helmet");
    set_name("soldier's helmet");
    set_type("helmet");
        set_short("A soldier's helmet");
	set_long(
 	"A metal helmet with a red tail on top. It's a normal issued helmet of"+
" the chinese army.\n");
    set_weight(1);
    set_ac(1);
    set_size("any");
    set_value(200);
}
