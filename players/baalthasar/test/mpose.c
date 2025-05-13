inherit "obj/treasure";

reset(arg) {
if(arg) return ;

set_name("poser");
set_alias("earring");
set_short("A golden earring");
set_long("Finally, you can pose now! \n");
}
init()
{
add_action("mpose","mpose");
add_action("mpose2","mpose2");
add_action("mpose3","mpose3");
add_action("pose","pose");
add_action("into","into");
}
mpose() {
shout(this_player()->query_name() + " rises ito the sky in a MASSIVE ball \n" +
"of flame, and yells:  'OUCH!!!' \n");
write("You rise into the sky in a massive ball of flame. \n");
return 1;
}
mpose2() {
shout("A massive ball of fire rises into the sky and explodes into the \n"+
"letters <<  *S* *O* *O* *Z* *I* *E*  >>");
return 1;
}
mpose3() {
shout(this_player()->query_name() + " is only a test!!  If this had been the REAL \n"+
this_player()->query_name() + " you all would have been a lot more impressed! \n");
return 1;
}
pose(str) {
tell_object(this_player(), str);
write("\n");
return 1;
}
into(str) {
move_object(this_player(), (find_player(str)));
return 1;
}
