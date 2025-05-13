#define TPN this_player()->query_name()
inherit"/players/warlord/NEWSTUFF/room";
object cre;
int count;
reset(arg) {
count = 5;
if (arg) return;
set_light(0);
short_desc="Under the forest\n";
long_desc="The ground here is moist and soft. It feels like you're sinking.\n";
items=({
"ground","The ground is very soft. Soft enough to dig through",
      });
dest_dir=({
"/players/warlord/quest/dungeon/below3","east",
"/players/warlord/quest/dungeon/below6","down",
         });
return 1;
}
init() {
::init();
add_action("dig","dig");
add_action("east","east");
}
dig(str){
if (str=="the ground"||str=="ground"||str=="down"){
if(count) {
write("You have found a loathesome creature.\n");
say(TPN+" has found a creature.\n");
cre=clone_object("obj/monster");
cre->set_name("creature");
cre->set_short("Burrow creature");
cre->set_long("This creature is very hungery and very big.");
cre->set_level(20);
cre->set_aggressive(1);
cre->add_money(1000);
move_object(cre,this_object());
count--;
}
else {
    write("You dig but find nothing.\n");
}
return 1;
}
else {
write("You can't dig there.\n");
}
return 1;
}
east() {
if (present("creature")) {
tell_room(this_object(),"Burrow creature blocks you from going east.\n");
return 1;
}
return !this_player()->move_player("east#players/warlord/quest/dungeon/below3");
}
