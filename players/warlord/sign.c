id (str) {
return str=="sign"; }
short() {
return "A wooden sign";
}
long() {
write("This is a small but magnificent sign. Read it!\n");
}
reset (arg) {
if (arg) return 1;
return 1;
}
init () {
add_action("read","read");
}
read (str) {
if (str=="the sign"||str=="sign") {
write("\n");
write("Go west from the church til you see path going north.\n");
write("Then head north til you can go up the mountain. Go up it and you will be at\n");
write("Warlord's castle. Also one of the finest bars, armouries and weaponaries\n");
write("Also there is a smaller castle in there for people with not so much power.\n");
write("Good Hunting all ye brave warriors!!!\n");
write("                               Warlord \n");
return 1;
}
else {
write("Read what?\n");
return 1;
}
}
