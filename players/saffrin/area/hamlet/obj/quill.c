inherit "obj/weapon";

reset(arg){

    ::reset(arg);
    if(!arg) {
	set_name("quill");
	set_short("A mighty feather quill");
	set_long("This mightly feather quill is the insturment of William Shakespeare.  Many times\n"+
	  "it has earned him honor.\n");
	set_class(20);
	set_weight(3);
	set_value(6400);
    }
}
