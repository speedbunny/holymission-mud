init() {
    add_action("bp","bp");
}

bp() {
object *u;
int i;

    u=users();
    for (i=0;i<sizeof(u);i++)
	if (u[i]!=this_player()) tell_object(u[i],"");
    write("Beep.\n");
    return 1;
}
