inherit "room/room";
init() {
object obj;
	obj=clone_object("/players/tarod/shadow/prot");
	obj->do_shadow();
}
