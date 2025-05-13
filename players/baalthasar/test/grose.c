inherit "obj/treasure";

reset(arg) {
if(arg) return ;

set_name("rose");
set_short("a black rose");
set_long("A beautiful long-stemmed black rose. \n");
}
init()
{
add_action("smell_rose", "smell");
}   
smell_rose(str) {
if ((!str) || !id(str))
{ 
return 0;
}
write("The smell of this flower warms your heart and touches your soul with \n"
+"a bit of romance. \n");
return 1;
}
