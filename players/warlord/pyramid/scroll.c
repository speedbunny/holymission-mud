inherit "/obj/treasure";

reset(arg) {
if (arg) return;
set_id("scroll");
set_short("Scroll of Phychor");
set_long("This is an old scroll, with a tight seal on it.\n");
set_value(100);
set_weight(1);
return 1;
}
init () {
::init() ;
add_action("read","read");
}
read(str) {
if ((str!="scroll") && (str!="the scroll")) return;
if (present("old book")) {
write("With the help of the book you can read the scroll...barely..it reads:\n"+
"Find ye flower black as night and take it in ye hand four times.\n"+
"Be ye warned of this though that it will hurt if ye successful!!\n");
return 1;
}
else {
write("You can not decifer the writing on the scroll\n");
return 1;
}
}
