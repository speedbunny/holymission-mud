id(str) { return str=="expe"; }

init() { add_action("x","x"); }

x(str) {
int a,b,c;

    if (!str) {
	write("x what ?\n");
	return 1;
    }

    a=get_eval_cost();
    c=command(str,this_player());
    b=get_eval_cost();
    write("delta "+(a-b)+" c "+c+"\n");
    return 1;
}
