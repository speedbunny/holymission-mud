inherit "room/room";
 
object monster;
int ran;
 
reset(arg) {
    if (arg) return;
    set_light(0);
    short_desc="In a cave";
    long_desc="You're in a wet and dark cave under the magic swamps.\n"+
     "The ground is safe here.\n";
    dest_dir=({
	"players/bobo/krooms/swamps/under_sw11","north",
	"players/bobo/krooms/swamps/under_sw3","south",
	"players/bobo/krooms/swamps/under_sw6","east",
	"players/bobo/krooms/swamps/under_sw8","west",
   });

 ran=random(5);
 while(ran>0) {
   monster=clone_object("obj/monster");
   monster->set_name("cockroach");
   monster->set_short("A cockroach");
   monster->set_level(1);
   monster->set_size(1);
   monster->set_hp(50);
   monster->set_al(-10);
   monster->set_aggressive(1);
   monster->set_ac(3);
   monster->set_wc(5);
   move_object(monster,this_object());
   ran--;
 }
}
 
