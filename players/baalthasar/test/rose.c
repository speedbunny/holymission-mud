inherit "obj/treasure";

reset(arg) {
if(arg) return ;

set_name("rose");
set_short("a black rose");
set_long("A beatifully evil looking black rose. \n");
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
write("The intoxicating smell of power, evil, and love emanate from this dark rose. \n");
return 1;
}
