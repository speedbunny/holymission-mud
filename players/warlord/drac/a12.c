inherit"room/room";
int num;
object app;
reset (arg) {
if (!random(3) && !app) {
app=clone_object("obj/monster");
app->set_name("apparition");
app->set_short("Apparition");
app->set_long("This is a soul which is at unrest\n");
app->set_level(17);
app->set_whimpy(1);
transfer(app,this_object());
}
if (arg) return;
set_light(1);
short_desc="Spooky room\n";
long_desc="You have entered a spooky room. You can feel a presence somewhere\n"+
          "near you.\n";
dest_dir=({
"players/warlord/drac/a11","west",
"players/warlord/drac/a5","south",
});
}
