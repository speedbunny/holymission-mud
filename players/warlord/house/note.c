inherit"obj/treasure";
reset(arg) {
if(arg) return;
set_id("note");
set_short("A note for Skyler");
set_long("A nice looking note. Try to read it.\n");
set_value(0);
set_weight(0);
}
init() {
::init();
add_action("read","read");
}
read(str) {
if(!str) {
write("What are you trying to read?\n");
return 1;
}
if((str=="the note")||(str=="note")) {
if(this_player()->query_real_name()=="rachel") {
write(
"Hello sweetheart. How are you today? I'm doing fine.\n"+
"I thought I would pick some flowers and leave them for you so when\n"+
"you arrive here you have something good to hold onto until I get here.\n"+
"I love you a lot and always will. *hug*  :)  \n"+
"\n"+
"                 Love Always,\n"+
"                     ME   @}--,--'---\n");
return 1;
}
else {
write("The note was for Skyler not for you.\n");
return 1;
}}
}
