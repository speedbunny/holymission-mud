inherit "obj/armour";
int env_var;

reset(arg){
::reset(arg);
set_name("com");
set_short("A wrist com");
set_long("Just 'com <msg>'\n");
set_weight(0);
}

init()
{
    add_action("comtalk", "com");
    add_action("comtalk", "com/");
    add_action("comtalk", "comem");
}
static com_talk(str){
    string msg;
    object *u;
    int i;
    switch(str){
    case 0:
	u=users();
	write("Blue team members:\n");
	for(i=0;sizeof(u);i++)
	    write(u[i]->query_com_line() ? "ON: " : "OFF: " +
	    u[i]->short(1)+"\n");
    break;
case "on":
    env_var["comoff"]=0;
    write("Com line turned off.\n");
    u=users();
    for(i=0;i<sizeof(u);i++)
	tell_object(u[i], capitalize(this_player()->query_real_name())+" tunes off.\n");

    break;
case "off":
    env_var["comoff"]=1;
    write("Com line turned on.\n");
    u=users();
    for(i=0;i<sizeof(u);i++)
	tell_object(u[i], capitalize(this_player()->query_real_name())+" tunes on.\n");
    break;
default:
    u=filter_array(users(), "com_line_filter", this_object());
    msg=("<* Blue team: "+capitalize(this_player()->query_real_name())+" "+
    (query_verb()=="com" ? " says: " : " ")+str+"\n");
    for(i=0;i<sizeof(u);i++)
	tell_object(u[i], msg);
}
return 1;
}
query_com_line(){
    return !env_var["comoff"];
}
static com_line_filter(ob){
    return ob->query_com_line();
}
